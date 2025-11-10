
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Blueprint.h"
#include "BlueprintAnalyzer.generated.h"


UCLASS()
class AERITHEDITOR_API UBlueprintAnalyzer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static FString AnalyzeBlueprint(UBlueprint* Blueprint, bool bIncludeDetailedNodes = false);

	static FString AnalyzeGraph(class UEdGraph* Graph, bool bIncludeDetailedNodes = false);

	static TSharedPtr<FJsonObject> AnalyzeNode(class UEdGraphNode* Node);

	static TArray<TSharedPtr<FJsonValue>> GetBlueprintVariables(UBlueprint* Blueprint);

	static TArray<TSharedPtr<FJsonValue>> GetBlueprintFunctions(UBlueprint* Blueprint);

	static TArray<TSharedPtr<FJsonValue>> GetBlueprintComponents(UBlueprint* Blueprint);

private:
	static FString PinTypeToString(const struct FEdGraphPinType& PinType);
	static FString GetPinDirection(const class UEdGraphPin* Pin);
};
