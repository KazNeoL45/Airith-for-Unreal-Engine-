
#include "BlueprintModifier.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/SimpleConstructionScript.h"
#include "Engine/SCS_Node.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"
#include "K2Node_CallFunction.h"
#include "K2Node_Event.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "KismetCompiler.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/SavePackage.h"
#include "Misc/PackageName.h"
#include "PackageTools.h"

UBlueprint* UBlueprintModifier::CreateNewBlueprint(const FString& BlueprintName, UClass* ParentClass, const FString& PackagePath)
{
	if (BlueprintName.IsEmpty() || !ParentClass)
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Invalid parameters for Blueprint creation"));
		return nullptr;
	}

	FString PackageName = PackagePath / BlueprintName;
	UPackage* Package = CreatePackage(*PackageName);
	if (!Package)
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Failed to create package: %s"), *PackageName);
		return nullptr;
	}

	UBlueprint* NewBlueprint = FKismetEditorUtilities::CreateBlueprint(
		ParentClass,
		Package,
		FName(*BlueprintName),
		BPTYPE_Normal,
		UBlueprint::StaticClass(),
		UBlueprintGeneratedClass::StaticClass(),
		FName("AerithBlueprintCreation")
	);

	if (NewBlueprint)
	{
		FAssetRegistryModule::AssetCreated(NewBlueprint);

		Package->MarkPackageDirty();

		UE_LOG(LogTemp, Log, TEXT("Aerith: Created Blueprint: %s"), *BlueprintName);
	}

	return NewBlueprint;
}

bool UBlueprintModifier::AddVariable(UBlueprint* Blueprint, const FString& VarName, const FString& VarType, bool bIsArray, const FString& Category)
{
	if (!Blueprint || VarName.IsEmpty())
	{
		return false;
	}

	FEdGraphPinType PinType = StringToPinType(VarType);
	if (bIsArray)
	{
		PinType.ContainerType = EPinContainerType::Array;
	}

	FBPVariableDescription NewVar;
	NewVar.VarName = FName(*VarName);
	NewVar.VarType = PinType;
	NewVar.Category = FText::FromString(Category);
	NewVar.PropertyFlags = CPF_Edit | CPF_BlueprintVisible;

	Blueprint->NewVariables.Add(NewVar);

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);

	UE_LOG(LogTemp, Log, TEXT("Aerith: Added variable '%s' of type '%s' to Blueprint"), *VarName, *VarType);

	return true;
}

UEdGraph* UBlueprintModifier::AddFunction(UBlueprint* Blueprint, const FString& FunctionName)
{
	if (!Blueprint || FunctionName.IsEmpty())
	{
		return nullptr;
	}

	UEdGraph* NewGraph = FBlueprintEditorUtils::CreateNewGraph(
		Blueprint,
		FName(*FunctionName),
		UEdGraph::StaticClass(),
		UEdGraphSchema_K2::StaticClass()
	);

	if (NewGraph)
	{
		Blueprint->FunctionGraphs.Add(NewGraph);

		FBlueprintEditorUtils::AddFunctionGraph<UClass>(Blueprint, NewGraph, false, nullptr);

		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);

		UE_LOG(LogTemp, Log, TEXT("Aerith: Added function '%s' to Blueprint"), *FunctionName);
	}

	return NewGraph;
}

bool UBlueprintModifier::AddComponent(UBlueprint* Blueprint, const FString& ComponentName, UClass* ComponentClass)
{
	if (!Blueprint || !ComponentClass || ComponentName.IsEmpty())
	{
		return false;
	}

	if (!Blueprint->SimpleConstructionScript)
	{
		Blueprint->SimpleConstructionScript = NewObject<USimpleConstructionScript>(Blueprint);
	}

	USCS_Node* NewNode = Blueprint->SimpleConstructionScript->CreateNode(ComponentClass, FName(*ComponentName));
	if (NewNode)
	{
		Blueprint->SimpleConstructionScript->AddNode(NewNode);
		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);

		UE_LOG(LogTemp, Log, TEXT("Aerith: Added component '%s' of type '%s' to Blueprint"), *ComponentName, *ComponentClass->GetName());
		return true;
	}

	return false;
}

UEdGraphNode* UBlueprintModifier::CreateNode(UEdGraph* Graph, UClass* NodeClass, const FVector2D& Position)
{
	if (!Graph || !NodeClass)
	{
		return nullptr;
	}

	UEdGraphNode* NewNode = NewObject<UEdGraphNode>(Graph, NodeClass);
	if (NewNode)
	{
		Graph->AddNode(NewNode, false, false);
		NewNode->CreateNewGuid();
		NewNode->PostPlacedNewNode();
		NewNode->NodePosX = Position.X;
		NewNode->NodePosY = Position.Y;
		NewNode->AllocateDefaultPins();

		Graph->NotifyGraphChanged();
	}

	return NewNode;
}

UK2Node_CallFunction* UBlueprintModifier::CreateFunctionCallNode(UEdGraph* Graph, const FString& FunctionName, UClass* TargetClass, const FVector2D& Position)
{
	if (!Graph || FunctionName.IsEmpty())
	{
		return nullptr;
	}

	UK2Node_CallFunction* FuncNode = NewObject<UK2Node_CallFunction>(Graph);
	if (FuncNode)
	{
		Graph->AddNode(FuncNode, false, false);
		FuncNode->CreateNewGuid();
		FuncNode->NodePosX = Position.X;
		FuncNode->NodePosY = Position.Y;

		if (TargetClass)
		{
			UFunction* Function = TargetClass->FindFunctionByName(FName(*FunctionName));
			if (Function)
			{
				FuncNode->SetFromFunction(Function);
			}
		}
		else
		{
			FuncNode->FunctionReference.SetExternalMember(FName(*FunctionName), nullptr);
		}

		FuncNode->PostPlacedNewNode();
		FuncNode->AllocateDefaultPins();

		Graph->NotifyGraphChanged();

		UE_LOG(LogTemp, Log, TEXT("Aerith: Created function call node '%s' at (%f, %f)"), *FunctionName, Position.X, Position.Y);
	}

	return FuncNode;
}

UK2Node_VariableGet* UBlueprintModifier::CreateVariableGetNode(UEdGraph* Graph, const FString& VariableName, const FVector2D& Position)
{
	if (!Graph || VariableName.IsEmpty())
	{
		return nullptr;
	}

	UK2Node_VariableGet* VarGetNode = NewObject<UK2Node_VariableGet>(Graph);
	if (VarGetNode)
	{
		Graph->AddNode(VarGetNode, false, false);
		VarGetNode->CreateNewGuid();
		VarGetNode->NodePosX = Position.X;
		VarGetNode->NodePosY = Position.Y;
		VarGetNode->VariableReference.SetSelfMember(FName(*VariableName));
		VarGetNode->PostPlacedNewNode();
		VarGetNode->AllocateDefaultPins();

		Graph->NotifyGraphChanged();

		UE_LOG(LogTemp, Log, TEXT("Aerith: Created variable get node '%s' at (%f, %f)"), *VariableName, Position.X, Position.Y);
	}

	return VarGetNode;
}

UK2Node_VariableSet* UBlueprintModifier::CreateVariableSetNode(UEdGraph* Graph, const FString& VariableName, const FVector2D& Position)
{
	if (!Graph || VariableName.IsEmpty())
	{
		return nullptr;
	}

	UK2Node_VariableSet* VarSetNode = NewObject<UK2Node_VariableSet>(Graph);
	if (VarSetNode)
	{
		Graph->AddNode(VarSetNode, false, false);
		VarSetNode->CreateNewGuid();
		VarSetNode->NodePosX = Position.X;
		VarSetNode->NodePosY = Position.Y;
		VarSetNode->VariableReference.SetSelfMember(FName(*VariableName));
		VarSetNode->PostPlacedNewNode();
		VarSetNode->AllocateDefaultPins();

		Graph->NotifyGraphChanged();

		UE_LOG(LogTemp, Log, TEXT("Aerith: Created variable set node '%s' at (%f, %f)"), *VariableName, Position.X, Position.Y);
	}

	return VarSetNode;
}

bool UBlueprintModifier::ConnectPins(UEdGraphPin* SourcePin, UEdGraphPin* TargetPin)
{
	if (!SourcePin || !TargetPin)
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Invalid pins for connection"));
		return false;
	}

	if (SourcePin->Direction == TargetPin->Direction)
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Cannot connect pins with same direction"));
		return false;
	}

	SourcePin->MakeLinkTo(TargetPin);

	if (SourcePin->GetOwningNode() && SourcePin->GetOwningNode()->GetGraph())
	{
		SourcePin->GetOwningNode()->GetGraph()->NotifyGraphChanged();
	}

	UE_LOG(LogTemp, Log, TEXT("Aerith: Connected pin '%s' to '%s'"), *SourcePin->PinName.ToString(), *TargetPin->PinName.ToString());

	return true;
}

UEdGraphPin* UBlueprintModifier::FindPin(UEdGraphNode* Node, const FString& PinName, bool bIsOutput)
{
	if (!Node)
	{
		return nullptr;
	}

	EEdGraphPinDirection Direction = bIsOutput ? EGPD_Output : EGPD_Input;

	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin && Pin->PinName.ToString().Equals(PinName, ESearchCase::IgnoreCase) && Pin->Direction == Direction)
		{
			return Pin;
		}
	}

	return nullptr;
}

void UBlueprintModifier::GetExecPins(UEdGraphNode* Node, UEdGraphPin*& OutExecPin, UEdGraphPin*& InExecPin)
{
	OutExecPin = nullptr;
	InExecPin = nullptr;

	if (!Node)
	{
		return;
	}

	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin && Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			if (Pin->Direction == EGPD_Output)
			{
				OutExecPin = Pin;
			}
			else if (Pin->Direction == EGPD_Input)
			{
				InExecPin = Pin;
			}
		}
	}
}

bool UBlueprintModifier::CompileBlueprint(UBlueprint* Blueprint)
{
	if (!Blueprint)
	{
		return false;
	}

	FKismetEditorUtilities::CompileBlueprint(Blueprint, EBlueprintCompileOptions::None);

	if (Blueprint->Status == BS_Error)
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Blueprint compilation failed with errors"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("Aerith: Blueprint compiled successfully"));
	return true;
}

bool UBlueprintModifier::SaveBlueprint(UBlueprint* Blueprint)
{
	if (!Blueprint)
	{
		return false;
	}

	UPackage* Package = Blueprint->GetOutermost();
	if (!Package)
	{
		return false;
	}

	FString PackageFileName = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());

	FSavePackageArgs SaveArgs;
	SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
	SaveArgs.SaveFlags = SAVE_NoError;

	bool bSuccess = UPackage::SavePackage(Package, Blueprint, *PackageFileName, SaveArgs);

	if (bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("Aerith: Saved Blueprint to %s"), *PackageFileName);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Aerith: Failed to save Blueprint"));
	}

	return bSuccess;
}

FEdGraphPinType UBlueprintModifier::StringToPinType(const FString& TypeString)
{
	FEdGraphPinType PinType;

	FString LowerType = TypeString.ToLower();

	if (LowerType == TEXT("bool") || LowerType == TEXT("boolean"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Boolean;
	}
	else if (LowerType == TEXT("int") || LowerType == TEXT("integer") || LowerType == TEXT("int32"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Int;
	}
	else if (LowerType == TEXT("int64"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Int64;
	}
	else if (LowerType == TEXT("byte") || LowerType == TEXT("uint8"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Byte;
	}
	else if (LowerType == TEXT("float") || LowerType == TEXT("real"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Real;
		PinType.PinSubCategory = UEdGraphSchema_K2::PC_Float;
	}
	else if (LowerType == TEXT("double"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Real;
		PinType.PinSubCategory = UEdGraphSchema_K2::PC_Double;
	}
	else if (LowerType == TEXT("string") || LowerType == TEXT("fstring"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_String;
	}
	else if (LowerType == TEXT("name") || LowerType == TEXT("fname"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Name;
	}
	else if (LowerType == TEXT("text") || LowerType == TEXT("ftext"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Text;
	}
	else if (LowerType == TEXT("vector") || LowerType == TEXT("fvector"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
		PinType.PinSubCategoryObject = TBaseStructure<FVector>::Get();
	}
	else if (LowerType == TEXT("rotator") || LowerType == TEXT("frotator"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
		PinType.PinSubCategoryObject = TBaseStructure<FRotator>::Get();
	}
	else if (LowerType == TEXT("transform") || LowerType == TEXT("ftransform"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
		PinType.PinSubCategoryObject = TBaseStructure<FTransform>::Get();
	}
	else if (LowerType == TEXT("color") || LowerType == TEXT("fcolor") || LowerType == TEXT("linearcolor"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Struct;
		PinType.PinSubCategoryObject = TBaseStructure<FLinearColor>::Get();
	}
	else if (LowerType == TEXT("object") || LowerType == TEXT("uobject"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Object;
		PinType.PinSubCategoryObject = UObject::StaticClass();
	}
	else if (LowerType == TEXT("actor") || LowerType == TEXT("aactor"))
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_Object;
		PinType.PinSubCategoryObject = AActor::StaticClass();
	}
	else
	{
		PinType.PinCategory = UEdGraphSchema_K2::PC_String;
		UE_LOG(LogTemp, Warning, TEXT("Aerith: Unknown type '%s', defaulting to String"), *TypeString);
	}

	return PinType;
}
