
#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "ClaudeAPIClient.generated.h"

DECLARE_DELEGATE_TwoParams(FOnClaudeResponseReceived, bool , const FString& );


UCLASS()
class AERITH_API UClaudeAPIClient : public UObject
{
	GENERATED_BODY()

public:
	UClaudeAPIClient();

	void SendPrompt(const FString& Prompt, const FString& SystemPrompt, FOnClaudeResponseReceived OnComplete);

	void SendMessages(const TArray<TSharedPtr<FJsonObject>>& Messages, const FString& SystemPrompt, FOnClaudeResponseReceived OnComplete);

private:
	struct FRequestContext
	{
		TArray<TSharedPtr<FJsonObject>> Messages;
		FString SystemPrompt;
		FOnClaudeResponseReceived Callback;
		int32 RetryCount;
		float RetryDelay;

		FRequestContext()
			: RetryCount(0)
			, RetryDelay(1.0f)
		{}
	};

	void SendMessagesInternal(TSharedPtr<FRequestContext> Context);
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, TSharedPtr<FRequestContext> Context);
	void ScheduleRetry(TSharedPtr<FRequestContext> Context);

	FString GetAPIKey() const;
	FString GetAPIEndpoint() const;
	FString GetModel() const;
	int32 GetMaxTokens() const;
	float GetTemperature() const;

	static constexpr int32 MaxRetries = 3;
	static constexpr float InitialRetryDelay = 2.0f;
	static constexpr float MaxRetryDelay = 60.0f;
};
