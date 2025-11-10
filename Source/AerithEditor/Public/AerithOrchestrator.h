
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ClaudeAPIClient.h"
#include "AerithOrchestrator.generated.h"

DECLARE_DELEGATE_OneParam(FOnAerithOperationComplete, const FString& );


UCLASS()
class AERITHEDITOR_API UAerithOrchestrator : public UObject
{
	GENERATED_BODY()

public:
	UAerithOrchestrator();

	void ProcessPrompt(const FString& UserPrompt, UBlueprint* ContextBlueprint, FOnAerithOperationComplete OnComplete);

	void CreateBlueprintFromDescription(const FString& Description, UClass* ParentClass, const FString& PackagePath, FOnAerithOperationComplete OnComplete);

	void ModifyBlueprint(UBlueprint* Blueprint, const FString& Instructions, FOnAerithOperationComplete OnComplete);

	void GenerateCppCode(const FString& Description, FOnAerithOperationComplete OnComplete);

private:
	void OnAIResponseReceived(bool bSuccess, const FString& Response, FOnAerithOperationComplete Callback, UBlueprint* TargetBlueprint);

	void ExecuteBlueprintOperations(const FString& AIResponse, UBlueprint* Blueprint, FOnAerithOperationComplete Callback);

	void ParseAndExecuteInstructions(TSharedPtr<FJsonObject> Instructions, UBlueprint* Blueprint, FString& OutResult);

	FString BuildSystemPrompt() const;
	FString BuildBlueprintContextPrompt(UBlueprint* Blueprint) const;

	UClaudeAPIClient* GetOrCreateAPIClient();

	UPROPERTY()
	UClaudeAPIClient* APIClient;
};
