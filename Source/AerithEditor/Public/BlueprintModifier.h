
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Blueprint.h"
#include "EdGraph/EdGraphNode.h"
#include "BlueprintModifier.generated.h"


UCLASS()
class AERITHEDITOR_API UBlueprintModifier : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static UBlueprint* CreateNewBlueprint(const FString& BlueprintName, UClass* ParentClass, const FString& PackagePath);

	UFUNCTION()
	static bool AddVariable(UBlueprint* Blueprint, const FString& VarName, const FString& VarType, bool bIsArray = false, const FString& Category = TEXT("Default"));

	UFUNCTION()
	static class UEdGraph* AddFunction(UBlueprint* Blueprint, const FString& FunctionName);

	UFUNCTION()
	static bool AddComponent(UBlueprint* Blueprint, const FString& ComponentName, UClass* ComponentClass);

	static UEdGraphNode* CreateNode(class UEdGraph* Graph, UClass* NodeClass, const FVector2D& Position);

	static class UK2Node_CallFunction* CreateFunctionCallNode(UEdGraph* Graph, const FString& FunctionName, UClass* TargetClass, const FVector2D& Position);

	static class UK2Node_VariableGet* CreateVariableGetNode(UEdGraph* Graph, const FString& VariableName, const FVector2D& Position);

	static class UK2Node_VariableSet* CreateVariableSetNode(UEdGraph* Graph, const FString& VariableName, const FVector2D& Position);

	static bool ConnectPins(class UEdGraphPin* SourcePin, class UEdGraphPin* TargetPin);

	static UEdGraphPin* FindPin(UEdGraphNode* Node, const FString& PinName, bool bIsOutput);

	static void GetExecPins(UEdGraphNode* Node, UEdGraphPin*& OutExecPin, UEdGraphPin*& InExecPin);

	UFUNCTION()
	static bool CompileBlueprint(UBlueprint* Blueprint);

	UFUNCTION()
	static bool SaveBlueprint(UBlueprint* Blueprint);

private:
	static struct FEdGraphPinType StringToPinType(const FString& TypeString);
};
