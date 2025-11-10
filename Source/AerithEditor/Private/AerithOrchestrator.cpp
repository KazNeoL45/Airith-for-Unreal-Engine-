
#include "AerithOrchestrator.h"
#include "BlueprintAnalyzer.h"
#include "BlueprintModifier.h"
#include "AerithSettings.h"
#include "Engine/Blueprint.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"

UAerithOrchestrator::UAerithOrchestrator()
	: APIClient(nullptr)
{
}

UClaudeAPIClient* UAerithOrchestrator::GetOrCreateAPIClient()
{
	if (!APIClient)
	{
		APIClient = NewObject<UClaudeAPIClient>(GetTransientPackage());
	}
	return APIClient;
}

void UAerithOrchestrator::ProcessPrompt(const FString& UserPrompt, UBlueprint* ContextBlueprint, FOnAerithOperationComplete OnComplete)
{
	FString SystemPrompt = BuildSystemPrompt();
	FString FullPrompt = UserPrompt;

	if (ContextBlueprint)
	{
		FullPrompt += TEXT("\n\nCurrent Blueprint Context:\n");
		FullPrompt += BuildBlueprintContextPrompt(ContextBlueprint);
	}

	GetOrCreateAPIClient()->SendPrompt(
		FullPrompt,
		SystemPrompt,
		FOnClaudeResponseReceived::CreateUObject(this, &UAerithOrchestrator::OnAIResponseReceived, OnComplete, ContextBlueprint)
	);
}

void UAerithOrchestrator::CreateBlueprintFromDescription(const FString& Description, UClass* ParentClass, const FString& PackagePath, FOnAerithOperationComplete OnComplete)
{
	FString SystemPrompt = BuildSystemPrompt();
	FString Prompt = FString::Printf(TEXT("Create a Blueprint based on this description:\n%s\n\nParent Class: %s"),
		*Description,
		ParentClass ? *ParentClass->GetName() : TEXT("Actor"));

	GetOrCreateAPIClient()->SendPrompt(
		Prompt,
		SystemPrompt,
		FOnClaudeResponseReceived::CreateUObject(this, &UAerithOrchestrator::OnAIResponseReceived, OnComplete, (UBlueprint*)nullptr)
	);
}

void UAerithOrchestrator::ModifyBlueprint(UBlueprint* Blueprint, const FString& Instructions, FOnAerithOperationComplete OnComplete)
{
	if (!Blueprint)
	{
		OnComplete.ExecuteIfBound(TEXT("Error: No Blueprint provided"));
		return;
	}

	FString SystemPrompt = BuildSystemPrompt();
	FString Prompt = FString::Printf(TEXT("Modify this Blueprint according to these instructions:\n%s\n\nCurrent Blueprint:\n%s"),
		*Instructions,
		*BuildBlueprintContextPrompt(Blueprint));

	GetOrCreateAPIClient()->SendPrompt(
		Prompt,
		SystemPrompt,
		FOnClaudeResponseReceived::CreateUObject(this, &UAerithOrchestrator::OnAIResponseReceived, OnComplete, Blueprint)
	);
}

void UAerithOrchestrator::GenerateCppCode(const FString& Description, FOnAerithOperationComplete OnComplete)
{
	FString SystemPrompt = TEXT("You are an expert Unreal Engine C++ programmer. Generate clean, well-commented C++ code that follows Unreal Engine coding standards.");

	FString Prompt = FString::Printf(TEXT("Generate Unreal Engine C++ code for:\n%s\n\nInclude both .h and .cpp files with proper UCLASS/UPROPERTY/UFUNCTION macros."),
		*Description);

	GetOrCreateAPIClient()->SendPrompt(
		Prompt,
		SystemPrompt,
		FOnClaudeResponseReceived::CreateLambda([OnComplete](bool bSuccess, const FString& Response)
		{
			if (bSuccess)
			{
				OnComplete.ExecuteIfBound(FString::Printf(TEXT("Generated C++ Code:\n\n%s"), *Response));
			}
			else
			{
				OnComplete.ExecuteIfBound(FString::Printf(TEXT("Error generating C++ code: %s"), *Response));
			}
		})
	);
}

void UAerithOrchestrator::OnAIResponseReceived(bool bSuccess, const FString& Response, FOnAerithOperationComplete Callback, UBlueprint* TargetBlueprint)
{
	if (!bSuccess)
	{
		Callback.ExecuteIfBound(FString::Printf(TEXT("AI Error: %s"), *Response));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Aerith: Received AI response, executing Blueprint operations..."));

	if (TargetBlueprint)
	{
		ExecuteBlueprintOperations(Response, TargetBlueprint, Callback);
	}
	else
	{
		Callback.ExecuteIfBound(Response);
	}
}

void UAerithOrchestrator::ExecuteBlueprintOperations(const FString& AIResponse, UBlueprint* Blueprint, FOnAerithOperationComplete Callback)
{
	int32 JsonStart = AIResponse.Find(TEXT("{"));
	int32 JsonEnd = AIResponse.Find(TEXT("}"), ESearchCase::IgnoreCase, ESearchDir::FromEnd);

	if (JsonStart != INDEX_NONE && JsonEnd != INDEX_NONE && JsonEnd > JsonStart)
	{
		FString JsonString = AIResponse.Mid(JsonStart, JsonEnd - JsonStart + 1);

		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FString Result;
			ParseAndExecuteInstructions(JsonObject, Blueprint, Result);
			Callback.ExecuteIfBound(Result);
			return;
		}
	}

	Callback.ExecuteIfBound(FString::Printf(TEXT("AI Response:\n%s\n\n(Note: No structured operations found. You may need to manually implement the suggestions.)"), *AIResponse));
}

void UAerithOrchestrator::ParseAndExecuteInstructions(TSharedPtr<FJsonObject> Instructions, UBlueprint* Blueprint, FString& OutResult)
{
	if (!Blueprint || !Instructions.IsValid())
	{
		OutResult = TEXT("Error: Invalid Blueprint or instructions");
		return;
	}

	TArray<FString> Operations;

	const TArray<TSharedPtr<FJsonValue>>* VariablesArray;
	if (Instructions->TryGetArrayField(TEXT("add_variables"), VariablesArray))
	{
		for (const TSharedPtr<FJsonValue>& VarValue : *VariablesArray)
		{
			TSharedPtr<FJsonObject> VarObj = VarValue->AsObject();
			if (VarObj.IsValid())
			{
				FString VarName;
				FString VarType;
				VarObj->TryGetStringField(TEXT("name"), VarName);
				VarObj->TryGetStringField(TEXT("type"), VarType);

				bool bIsArray = false;
				VarObj->TryGetBoolField(TEXT("is_array"), bIsArray);

				if (UBlueprintModifier::AddVariable(Blueprint, VarName, VarType, bIsArray))
				{
					Operations.Add(FString::Printf(TEXT("Added variable: %s (%s)"), *VarName, *VarType));
				}
			}
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* FunctionsArray;
	if (Instructions->TryGetArrayField(TEXT("add_functions"), FunctionsArray))
	{
		for (const TSharedPtr<FJsonValue>& FuncValue : *FunctionsArray)
		{
			TSharedPtr<FJsonObject> FuncObj = FuncValue->AsObject();
			if (FuncObj.IsValid())
			{
				FString FuncName;
				FuncObj->TryGetStringField(TEXT("name"), FuncName);

				if (UBlueprintModifier::AddFunction(Blueprint, FuncName))
				{
					Operations.Add(FString::Printf(TEXT("Added function: %s"), *FuncName));
				}
			}
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* ComponentsArray;
	if (Instructions->TryGetArrayField(TEXT("add_components"), ComponentsArray))
	{
		for (const TSharedPtr<FJsonValue>& CompValue : *ComponentsArray)
		{
			TSharedPtr<FJsonObject> CompObj = CompValue->AsObject();
			if (CompObj.IsValid())
			{
				FString CompName;
				FString CompClassName;
				CompObj->TryGetStringField(TEXT("name"), CompName);
				CompObj->TryGetStringField(TEXT("class"), CompClassName);

				UClass* CompClass = FindObject<UClass>(nullptr, *CompClassName);
				if (!CompClass)
				{
					CompClass = LoadObject<UClass>(nullptr, *CompClassName);
				}

				if (CompClass && UBlueprintModifier::AddComponent(Blueprint, CompName, CompClass))
				{
					Operations.Add(FString::Printf(TEXT("Added component: %s (%s)"), *CompName, *CompClassName));
				}
			}
		}
	}

	if (Operations.Num() > 0)
	{
		if (UBlueprintModifier::CompileBlueprint(Blueprint))
		{
			Operations.Add(TEXT("Blueprint compiled successfully"));
		}
		else
		{
			Operations.Add(TEXT("Blueprint compilation had warnings/errors"));
		}
	}

	OutResult = TEXT("Operations executed:\n");
	for (const FString& Op : Operations)
	{
		OutResult += TEXT("- ") + Op + TEXT("\n");
	}

	if (Operations.Num() == 0)
	{
		OutResult = TEXT("No operations were executed. The AI may have provided analysis or suggestions instead.");
	}
}

FString UAerithOrchestrator::BuildSystemPrompt() const
{
	return TEXT(
		"You are Aerith, an AI assistant specialized in Unreal Engine 5 Blueprint development. "
		"You have deep understanding of:\n"
		"- Blueprint visual scripting system\n"
		"- Blueprint node types and connections\n"
		"- Unreal Engine architecture and best practices\n"
		"- Common UE5 classes, components, and functions\n\n"
		"When modifying or creating Blueprints, provide structured JSON instructions in this format:\n"
		"{\n"
		"  \"add_variables\": [{\"name\": \"VariableName\", \"type\": \"float\", \"is_array\": false}],\n"
		"  \"add_functions\": [{\"name\": \"FunctionName\"}],\n"
		"  \"add_components\": [{\"name\": \"ComponentName\", \"class\": \"UStaticMeshComponent\"}]\n"
		"}\n\n"
		"Supported types: bool, int, float, double, string, name, text, vector, rotator, transform, color, object, actor\n"
		"Always explain your reasoning and provide the JSON instructions."
	);
}

FString UAerithOrchestrator::BuildBlueprintContextPrompt(UBlueprint* Blueprint) const
{
	if (!Blueprint)
	{
		return TEXT("");
	}

	const UAerithSettings* Settings = GetDefault<UAerithSettings>();
	const bool bIncludeDetailedNodes = Settings ? Settings->bIncludeDetailedNodeAnalysis : false;
	const int32 MaxChars = Settings ? Settings->MaxContextCharacters : 50000;

	FString FullContext = UBlueprintAnalyzer::AnalyzeBlueprint(Blueprint, bIncludeDetailedNodes);

	// Check if we need to truncate
	if (FullContext.Len() > MaxChars)
	{
		// Try without detailed node analysis if it was enabled
		if (bIncludeDetailedNodes)
		{
			UE_LOG(LogTemp, Warning, TEXT("Aerith: Blueprint context too large (%d chars), switching to summary mode"), FullContext.Len());
			FullContext = UBlueprintAnalyzer::AnalyzeBlueprint(Blueprint, false);
		}

		// If still too large, truncate with a warning
		if (FullContext.Len() > MaxChars)
		{
			UE_LOG(LogTemp, Warning, TEXT("Aerith: Blueprint context (%d chars) exceeds limit (%d chars), truncating to prevent rate limit errors"), FullContext.Len(), MaxChars);
			FullContext = FullContext.Left(MaxChars);
			FullContext += TEXT("\n[TRUNCATED - Blueprint too large. Consider breaking it into smaller Blueprints or increasing MaxContextCharacters in settings]");
		}
	}

	// Estimate token count (roughly 4 chars per token)
	const int32 EstimatedTokens = FullContext.Len() / 4;
	if (EstimatedTokens > 20000)
	{
		UE_LOG(LogTemp, Warning, TEXT("Aerith: Estimated token count is high (~%d tokens). This may approach rate limits."), EstimatedTokens);
	}

	return FullContext;
}
