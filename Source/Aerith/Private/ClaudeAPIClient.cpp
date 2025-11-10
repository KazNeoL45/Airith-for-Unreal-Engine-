
#include "ClaudeAPIClient.h"
#include "AerithSettings.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Editor.h"
#include "TimerManager.h"

UClaudeAPIClient::UClaudeAPIClient()
{
}

void UClaudeAPIClient::SendPrompt(const FString& Prompt, const FString& SystemPrompt, FOnClaudeResponseReceived OnComplete)
{
	TArray<TSharedPtr<FJsonObject>> Messages;
	TSharedPtr<FJsonObject> UserMessage = MakeShared<FJsonObject>();
	UserMessage->SetStringField(TEXT("role"), TEXT("user"));
	UserMessage->SetStringField(TEXT("content"), Prompt);
	Messages.Add(UserMessage);

	SendMessages(Messages, SystemPrompt, OnComplete);
}

void UClaudeAPIClient::SendMessages(const TArray<TSharedPtr<FJsonObject>>& Messages, const FString& SystemPrompt, FOnClaudeResponseReceived OnComplete)
{
	const FString APIKey = GetAPIKey();
	if (APIKey.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Claude API Key is not set. Please configure it in Project Settings -> Aerith"));
		OnComplete.ExecuteIfBound(false, TEXT("API Key not configured"));
		return;
	}

	TSharedPtr<FRequestContext> Context = MakeShared<FRequestContext>();
	Context->Messages = Messages;
	Context->SystemPrompt = SystemPrompt;
	Context->Callback = OnComplete;
	Context->RetryCount = 0;
	Context->RetryDelay = InitialRetryDelay;

	SendMessagesInternal(Context);
}

void UClaudeAPIClient::SendMessagesInternal(TSharedPtr<FRequestContext> Context)
{
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(GetAPIEndpoint());
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("x-api-key"), GetAPIKey());
	HttpRequest->SetHeader(TEXT("anthropic-version"), TEXT("2023-06-01"));

	TSharedPtr<FJsonObject> JsonPayload = MakeShared<FJsonObject>();
	JsonPayload->SetStringField(TEXT("model"), GetModel());
	JsonPayload->SetNumberField(TEXT("max_tokens"), GetMaxTokens());
	JsonPayload->SetNumberField(TEXT("temperature"), GetTemperature());

	if (!Context->SystemPrompt.IsEmpty())
	{
		JsonPayload->SetStringField(TEXT("system"), Context->SystemPrompt);
	}

	TArray<TSharedPtr<FJsonValue>> MessagesArray;
	for (const TSharedPtr<FJsonObject>& Message : Context->Messages)
	{
		MessagesArray.Add(MakeShared<FJsonValueObject>(Message));
	}
	JsonPayload->SetArrayField(TEXT("messages"), MessagesArray);

	FString JsonString;
	TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(JsonPayload.ToSharedRef(), JsonWriter);

	HttpRequest->SetContentAsString(JsonString);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UClaudeAPIClient::OnResponseReceived, Context);

	if (!HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Failed to send HTTP request"));
		Context->Callback.ExecuteIfBound(false, TEXT("Failed to send HTTP request"));
	}
	else
	{
		if (Context->RetryCount > 0)
		{
			UE_LOG(LogTemp, Log, TEXT("Aerith: Retrying request to Claude API (Attempt %d/%d)..."), Context->RetryCount + 1, MaxRetries + 1);
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Aerith: Sending request to Claude API..."));
		}
	}
}

void UClaudeAPIClient::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, TSharedPtr<FRequestContext> Context)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: HTTP request failed"));

		// Retry on network failures
		if (Context->RetryCount < MaxRetries)
		{
			UE_LOG(LogTemp, Warning, TEXT("Aerith: Network error, will retry in %.1f seconds..."), Context->RetryDelay);
			ScheduleRetry(Context);
			return;
		}

		Context->Callback.ExecuteIfBound(false, TEXT("HTTP request failed after multiple retries"));
		return;
	}

	const int32 ResponseCode = Response->GetResponseCode();
	const FString ResponseContent = Response->GetContentAsString();

	// Handle rate limiting (429)
	if (ResponseCode == 429)
	{
		if (Context->RetryCount < MaxRetries)
		{
			UE_LOG(LogTemp, Warning, TEXT("Aerith: Rate limit hit. Waiting %.1f seconds before retry..."), Context->RetryDelay);
			ScheduleRetry(Context);
			return;
		}

		Context->Callback.ExecuteIfBound(false, TEXT("Rate limit exceeded. Please wait a minute and try again. The API has usage limits that prevent too many requests in a short period."));
		return;
	}

	// Handle other server errors that might be temporary (500, 502, 503, 504)
	if (ResponseCode >= 500 && ResponseCode < 600)
	{
		if (Context->RetryCount < MaxRetries)
		{
			UE_LOG(LogTemp, Warning, TEXT("Aerith: Server error %d, will retry in %.1f seconds..."), ResponseCode, Context->RetryDelay);
			ScheduleRetry(Context);
			return;
		}

		Context->Callback.ExecuteIfBound(false, FString::Printf(TEXT("API server error %d after multiple retries"), ResponseCode));
		return;
	}

	if (ResponseCode != 200)
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: API returned error code %d: %s"), ResponseCode, *ResponseContent);

		// Parse error message if available
		TSharedPtr<FJsonObject> JsonError;
		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(ResponseContent);
		FString ErrorMessage = FString::Printf(TEXT("API Error %d"), ResponseCode);

		if (FJsonSerializer::Deserialize(JsonReader, JsonError) && JsonError.IsValid())
		{
			const TSharedPtr<FJsonObject>* ErrorObject;
			if (JsonError->TryGetObjectField(TEXT("error"), ErrorObject))
			{
				FString ErrorType, ErrorMsg;
				if ((*ErrorObject)->TryGetStringField(TEXT("type"), ErrorType))
				{
					ErrorMessage += FString::Printf(TEXT(": %s"), *ErrorType);
				}
				if ((*ErrorObject)->TryGetStringField(TEXT("message"), ErrorMsg))
				{
					ErrorMessage += FString::Printf(TEXT(" - %s"), *ErrorMsg);
				}
			}
		}

		Context->Callback.ExecuteIfBound(false, ErrorMessage);
		return;
	}

	TSharedPtr<FJsonObject> JsonResponse;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(ResponseContent);

	if (!FJsonSerializer::Deserialize(JsonReader, JsonResponse) || !JsonResponse.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Failed to parse JSON response"));
		Context->Callback.ExecuteIfBound(false, TEXT("Failed to parse JSON response"));
		return;
	}

	const TArray<TSharedPtr<FJsonValue>>* ContentArray;
	if (JsonResponse->TryGetArrayField(TEXT("content"), ContentArray) && ContentArray->Num() > 0)
	{
		TSharedPtr<FJsonObject> ContentObject = (*ContentArray)[0]->AsObject();
		if (ContentObject.IsValid())
		{
			FString TextContent;
			if (ContentObject->TryGetStringField(TEXT("text"), TextContent))
			{
				UE_LOG(LogTemp, Log, TEXT("Aerith: Received response from Claude API"));
				Context->Callback.ExecuteIfBound(true, TextContent);
				return;
			}
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Aerith: Unexpected response format"));
	Context->Callback.ExecuteIfBound(false, TEXT("Unexpected response format"));
}

void UClaudeAPIClient::ScheduleRetry(TSharedPtr<FRequestContext> Context)
{
	Context->RetryCount++;

	// Use a timer to retry after the delay
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindLambda([this, Context]()
	{
		SendMessagesInternal(Context);
	});

	if (GEditor)
	{
		GEditor->GetTimerManager()->SetTimer(TimerHandle, TimerDelegate, Context->RetryDelay, false);
	}

	// Exponential backoff: double the delay for next retry, up to max
	Context->RetryDelay = FMath::Min(Context->RetryDelay * 2.0f, MaxRetryDelay);
}

FString UClaudeAPIClient::GetAPIKey() const
{
	const UAerithSettings* Settings = GetDefault<UAerithSettings>();
	return Settings ? Settings->ClaudeAPIKey : TEXT("");
}

FString UClaudeAPIClient::GetAPIEndpoint() const
{
	const UAerithSettings* Settings = GetDefault<UAerithSettings>();
	return Settings ? Settings->APIEndpoint : TEXT("https://api.anthropic.com/v1/messages");
}

FString UClaudeAPIClient::GetModel() const
{
	const UAerithSettings* Settings = GetDefault<UAerithSettings>();
	return Settings ? Settings->Model : TEXT("claude-3-5-sonnet-20241022");
}

int32 UClaudeAPIClient::GetMaxTokens() const
{
	const UAerithSettings* Settings = GetDefault<UAerithSettings>();
	return Settings ? Settings->MaxTokens : 8192;
}

float UClaudeAPIClient::GetTemperature() const
{
	const UAerithSettings* Settings = GetDefault<UAerithSettings>();
	return Settings ? Settings->Temperature : 0.7f;
}
