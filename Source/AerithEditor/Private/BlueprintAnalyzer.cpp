
#include "BlueprintAnalyzer.h"
#include "Engine/Blueprint.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "K2Node.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"
#include "K2Node_CallFunction.h"
#include "K2Node_Event.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Engine/SimpleConstructionScript.h"
#include "Engine/SCS_Node.h"

FString UBlueprintAnalyzer::AnalyzeBlueprint(UBlueprint* Blueprint, bool bIncludeDetailedNodes)
{
	if (!Blueprint)
	{
		return TEXT("{}");
	}

	TSharedPtr<FJsonObject> JsonRoot = MakeShared<FJsonObject>();

	JsonRoot->SetStringField(TEXT("Name"), Blueprint->GetName());
	JsonRoot->SetStringField(TEXT("Type"), Blueprint->GetClass()->GetName());
	JsonRoot->SetStringField(TEXT("ParentClass"), Blueprint->ParentClass ? Blueprint->ParentClass->GetName() : TEXT("None"));

	TArray<TSharedPtr<FJsonValue>> Variables = GetBlueprintVariables(Blueprint);
	JsonRoot->SetArrayField(TEXT("Variables"), Variables);

	TArray<TSharedPtr<FJsonValue>> Functions = GetBlueprintFunctions(Blueprint);
	JsonRoot->SetArrayField(TEXT("Functions"), Functions);

	TArray<TSharedPtr<FJsonValue>> Components = GetBlueprintComponents(Blueprint);
	JsonRoot->SetArrayField(TEXT("Components"), Components);

	if (bIncludeDetailedNodes)
	{
		TArray<TSharedPtr<FJsonValue>> GraphsArray;
		for (UEdGraph* Graph : Blueprint->UbergraphPages)
		{
			if (Graph)
			{
				TSharedPtr<FJsonObject> GraphObj = MakeShared<FJsonObject>();
				GraphObj->SetStringField(TEXT("Name"), Graph->GetName());
				GraphObj->SetStringField(TEXT("Details"), AnalyzeGraph(Graph, true));
				GraphsArray.Add(MakeShared<FJsonValueObject>(GraphObj));
			}
		}
		JsonRoot->SetArrayField(TEXT("EventGraphs"), GraphsArray);
	}
	else
	{
		// Just include graph names and node counts for summary
		TArray<TSharedPtr<FJsonValue>> GraphsSummary;
		for (UEdGraph* Graph : Blueprint->UbergraphPages)
		{
			if (Graph)
			{
				TSharedPtr<FJsonObject> GraphObj = MakeShared<FJsonObject>();
				GraphObj->SetStringField(TEXT("Name"), Graph->GetName());
				GraphObj->SetNumberField(TEXT("NodeCount"), Graph->Nodes.Num());
				GraphsSummary.Add(MakeShared<FJsonValueObject>(GraphObj));
			}
		}
		JsonRoot->SetArrayField(TEXT("EventGraphs"), GraphsSummary);
	}

	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonRoot.ToSharedRef(), Writer);

	return OutputString;
}

FString UBlueprintAnalyzer::AnalyzeGraph(UEdGraph* Graph, bool bIncludeDetailedNodes)
{
	if (!Graph)
	{
		return TEXT("{}");
	}

	TSharedPtr<FJsonObject> JsonGraph = MakeShared<FJsonObject>();
	JsonGraph->SetStringField(TEXT("GraphName"), Graph->GetName());

	if (bIncludeDetailedNodes)
	{
		TArray<TSharedPtr<FJsonValue>> NodesArray;
		for (UEdGraphNode* Node : Graph->Nodes)
		{
			if (Node)
			{
				TSharedPtr<FJsonObject> NodeObj = AnalyzeNode(Node);
				if (NodeObj.IsValid())
				{
					NodesArray.Add(MakeShared<FJsonValueObject>(NodeObj));
				}
			}
		}
		JsonGraph->SetArrayField(TEXT("Nodes"), NodesArray);
	}
	else
	{
		JsonGraph->SetNumberField(TEXT("NodeCount"), Graph->Nodes.Num());
	}

	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonGraph.ToSharedRef(), Writer);

	return OutputString;
}

TSharedPtr<FJsonObject> UBlueprintAnalyzer::AnalyzeNode(UEdGraphNode* Node)
{
	if (!Node)
	{
		return nullptr;
	}

	TSharedPtr<FJsonObject> JsonNode = MakeShared<FJsonObject>();

	JsonNode->SetStringField(TEXT("NodeType"), Node->GetClass()->GetName());
	JsonNode->SetStringField(TEXT("NodeTitle"), Node->GetNodeTitle(ENodeTitleType::FullTitle).ToString());
	JsonNode->SetStringField(TEXT("NodeGuid"), Node->NodeGuid.ToString());

	if (UK2Node_CallFunction* FuncNode = Cast<UK2Node_CallFunction>(Node))
	{
		if (FuncNode->FunctionReference.GetMemberName() != NAME_None)
		{
			JsonNode->SetStringField(TEXT("FunctionName"), FuncNode->FunctionReference.GetMemberName().ToString());
		}
	}
	else if (UK2Node_VariableGet* VarGetNode = Cast<UK2Node_VariableGet>(Node))
	{
		JsonNode->SetStringField(TEXT("VariableName"), VarGetNode->GetVarName().ToString());
	}
	else if (UK2Node_VariableSet* VarSetNode = Cast<UK2Node_VariableSet>(Node))
	{
		JsonNode->SetStringField(TEXT("VariableName"), VarSetNode->GetVarName().ToString());
	}
	else if (UK2Node_Event* EventNode = Cast<UK2Node_Event>(Node))
	{
		JsonNode->SetStringField(TEXT("EventName"), EventNode->EventReference.GetMemberName().ToString());
	}

	TArray<TSharedPtr<FJsonValue>> PinsArray;
	for (UEdGraphPin* Pin : Node->Pins)
	{
		if (Pin)
		{
			TSharedPtr<FJsonObject> PinObj = MakeShared<FJsonObject>();
			PinObj->SetStringField(TEXT("PinName"), Pin->PinName.ToString());
			PinObj->SetStringField(TEXT("PinType"), PinTypeToString(Pin->PinType));
			PinObj->SetStringField(TEXT("Direction"), GetPinDirection(Pin));
			PinObj->SetNumberField(TEXT("LinkedTo"), Pin->LinkedTo.Num());

			if (Pin->LinkedTo.Num() > 0)
			{
				TArray<TSharedPtr<FJsonValue>> ConnectionsArray;
				for (UEdGraphPin* LinkedPin : Pin->LinkedTo)
				{
					if (LinkedPin && LinkedPin->GetOwningNode())
					{
						TSharedPtr<FJsonObject> ConnectionObj = MakeShared<FJsonObject>();
						ConnectionObj->SetStringField(TEXT("NodeGuid"), LinkedPin->GetOwningNode()->NodeGuid.ToString());
						ConnectionObj->SetStringField(TEXT("PinName"), LinkedPin->PinName.ToString());
						ConnectionsArray.Add(MakeShared<FJsonValueObject>(ConnectionObj));
					}
				}
				PinObj->SetArrayField(TEXT("Connections"), ConnectionsArray);
			}

			PinsArray.Add(MakeShared<FJsonValueObject>(PinObj));
		}
	}
	JsonNode->SetArrayField(TEXT("Pins"), PinsArray);

	return JsonNode;
}

TArray<TSharedPtr<FJsonValue>> UBlueprintAnalyzer::GetBlueprintVariables(UBlueprint* Blueprint)
{
	TArray<TSharedPtr<FJsonValue>> Variables;

	if (!Blueprint)
	{
		return Variables;
	}

	for (const FBPVariableDescription& Var : Blueprint->NewVariables)
	{
		TSharedPtr<FJsonObject> VarObj = MakeShared<FJsonObject>();
		VarObj->SetStringField(TEXT("Name"), Var.VarName.ToString());
		VarObj->SetStringField(TEXT("Type"), PinTypeToString(Var.VarType));
		VarObj->SetStringField(TEXT("Category"), Var.Category.ToString());
		VarObj->SetBoolField(TEXT("IsArray"), Var.VarType.IsArray());
		Variables.Add(MakeShared<FJsonValueObject>(VarObj));
	}

	return Variables;
}

TArray<TSharedPtr<FJsonValue>> UBlueprintAnalyzer::GetBlueprintFunctions(UBlueprint* Blueprint)
{
	TArray<TSharedPtr<FJsonValue>> Functions;

	if (!Blueprint)
	{
		return Functions;
	}

	for (UEdGraph* Graph : Blueprint->FunctionGraphs)
	{
		if (Graph)
		{
			TSharedPtr<FJsonObject> FuncObj = MakeShared<FJsonObject>();
			FuncObj->SetStringField(TEXT("Name"), Graph->GetName());

			TArray<TSharedPtr<FJsonValue>> InputsArray;
			TArray<TSharedPtr<FJsonValue>> OutputsArray;

			for (UEdGraphNode* Node : Graph->Nodes)
			{
				if (UK2Node_FunctionEntry* EntryNode = Cast<UK2Node_FunctionEntry>(Node))
				{
					for (UEdGraphPin* Pin : EntryNode->Pins)
					{
						if (Pin && Pin->Direction == EGPD_Output && Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
						{
							TSharedPtr<FJsonObject> ParamObj = MakeShared<FJsonObject>();
							ParamObj->SetStringField(TEXT("Name"), Pin->PinName.ToString());
							ParamObj->SetStringField(TEXT("Type"), PinTypeToString(Pin->PinType));
							InputsArray.Add(MakeShared<FJsonValueObject>(ParamObj));
						}
					}
				}
				else if (UK2Node_FunctionResult* ResultNode = Cast<UK2Node_FunctionResult>(Node))
				{
					for (UEdGraphPin* Pin : ResultNode->Pins)
					{
						if (Pin && Pin->Direction == EGPD_Input && Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec)
						{
							TSharedPtr<FJsonObject> ParamObj = MakeShared<FJsonObject>();
							ParamObj->SetStringField(TEXT("Name"), Pin->PinName.ToString());
							ParamObj->SetStringField(TEXT("Type"), PinTypeToString(Pin->PinType));
							OutputsArray.Add(MakeShared<FJsonValueObject>(ParamObj));
						}
					}
				}
			}

			FuncObj->SetArrayField(TEXT("Inputs"), InputsArray);
			FuncObj->SetArrayField(TEXT("Outputs"), OutputsArray);

			Functions.Add(MakeShared<FJsonValueObject>(FuncObj));
		}
	}

	return Functions;
}

TArray<TSharedPtr<FJsonValue>> UBlueprintAnalyzer::GetBlueprintComponents(UBlueprint* Blueprint)
{
	TArray<TSharedPtr<FJsonValue>> Components;

	if (!Blueprint || !Blueprint->SimpleConstructionScript)
	{
		return Components;
	}

	const TArray<USCS_Node*>& Nodes = Blueprint->SimpleConstructionScript->GetAllNodes();
	for (USCS_Node* Node : Nodes)
	{
		if (Node && Node->ComponentTemplate)
		{
			TSharedPtr<FJsonObject> CompObj = MakeShared<FJsonObject>();
			CompObj->SetStringField(TEXT("Name"), Node->GetVariableName().ToString());
			CompObj->SetStringField(TEXT("Class"), Node->ComponentTemplate->GetClass()->GetName());
			Components.Add(MakeShared<FJsonValueObject>(CompObj));
		}
	}

	return Components;
}

FString UBlueprintAnalyzer::PinTypeToString(const FEdGraphPinType& PinType)
{
	FString TypeString = PinType.PinCategory.ToString();

	if (PinType.PinSubCategoryObject.IsValid())
	{
		TypeString += TEXT(" (") + PinType.PinSubCategoryObject->GetName() + TEXT(")");
	}

	if (PinType.IsArray())
	{
		TypeString += TEXT(" Array");
	}

	return TypeString;
}

FString UBlueprintAnalyzer::GetPinDirection(const UEdGraphPin* Pin)
{
	if (!Pin)
	{
		return TEXT("Unknown");
	}

	switch (Pin->Direction)
	{
	case EGPD_Input:
		return TEXT("Input");
	case EGPD_Output:
		return TEXT("Output");
	default:
		return TEXT("Unknown");
	}
}
