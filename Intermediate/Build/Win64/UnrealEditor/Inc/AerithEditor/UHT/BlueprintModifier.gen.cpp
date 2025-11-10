// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintModifier.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeBlueprintModifier() {}

// ********** Begin Cross Module References ********************************************************
AERITHEDITOR_API UClass* Z_Construct_UClass_UBlueprintModifier();
AERITHEDITOR_API UClass* Z_Construct_UClass_UBlueprintModifier_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprint_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UEdGraph_NoRegister();
UPackage* Z_Construct_UPackage__Script_AerithEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBlueprintModifier Function AddComponent *********************************
struct Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics
{
	struct BlueprintModifier_eventAddComponent_Parms
	{
		UBlueprint* Blueprint;
		FString ComponentName;
		UClass* ComponentClass;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComponentName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ComponentName;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ComponentClass;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddComponent_Parms, Blueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ComponentName = { "ComponentName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddComponent_Parms, ComponentName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComponentName_MetaData), NewProp_ComponentName_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ComponentClass = { "ComponentClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddComponent_Parms, ComponentClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BlueprintModifier_eventAddComponent_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlueprintModifier_eventAddComponent_Parms), &Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ComponentName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ComponentClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBlueprintModifier, nullptr, "AddComponent", Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::BlueprintModifier_eventAddComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::BlueprintModifier_eventAddComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBlueprintModifier_AddComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintModifier_AddComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBlueprintModifier::execAddComponent)
{
	P_GET_OBJECT(UBlueprint,Z_Param_Blueprint);
	P_GET_PROPERTY(FStrProperty,Z_Param_ComponentName);
	P_GET_OBJECT(UClass,Z_Param_ComponentClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBlueprintModifier::AddComponent(Z_Param_Blueprint,Z_Param_ComponentName,Z_Param_ComponentClass);
	P_NATIVE_END;
}
// ********** End Class UBlueprintModifier Function AddComponent ***********************************

// ********** Begin Class UBlueprintModifier Function AddFunction **********************************
struct Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics
{
	struct BlueprintModifier_eventAddFunction_Parms
	{
		UBlueprint* Blueprint;
		FString FunctionName;
		UEdGraph* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FunctionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FunctionName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddFunction_Parms, Blueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::NewProp_FunctionName = { "FunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddFunction_Parms, FunctionName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FunctionName_MetaData), NewProp_FunctionName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddFunction_Parms, ReturnValue), Z_Construct_UClass_UEdGraph_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::NewProp_FunctionName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBlueprintModifier, nullptr, "AddFunction", Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::BlueprintModifier_eventAddFunction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::BlueprintModifier_eventAddFunction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBlueprintModifier_AddFunction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintModifier_AddFunction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBlueprintModifier::execAddFunction)
{
	P_GET_OBJECT(UBlueprint,Z_Param_Blueprint);
	P_GET_PROPERTY(FStrProperty,Z_Param_FunctionName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UEdGraph**)Z_Param__Result=UBlueprintModifier::AddFunction(Z_Param_Blueprint,Z_Param_FunctionName);
	P_NATIVE_END;
}
// ********** End Class UBlueprintModifier Function AddFunction ************************************

// ********** Begin Class UBlueprintModifier Function AddVariable **********************************
struct Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics
{
	struct BlueprintModifier_eventAddVariable_Parms
	{
		UBlueprint* Blueprint;
		FString VarName;
		FString VarType;
		bool bIsArray;
		FString Category;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VarName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VarType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VarName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VarType;
	static void NewProp_bIsArray_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsArray;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddVariable_Parms, Blueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_VarName = { "VarName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddVariable_Parms, VarName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VarName_MetaData), NewProp_VarName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_VarType = { "VarType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddVariable_Parms, VarType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VarType_MetaData), NewProp_VarType_MetaData) };
void Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_bIsArray_SetBit(void* Obj)
{
	((BlueprintModifier_eventAddVariable_Parms*)Obj)->bIsArray = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_bIsArray = { "bIsArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlueprintModifier_eventAddVariable_Parms), &Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_bIsArray_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventAddVariable_Parms, Category), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Category_MetaData), NewProp_Category_MetaData) };
void Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BlueprintModifier_eventAddVariable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlueprintModifier_eventAddVariable_Parms), &Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_VarName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_VarType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_bIsArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_Category,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBlueprintModifier, nullptr, "AddVariable", Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::BlueprintModifier_eventAddVariable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::BlueprintModifier_eventAddVariable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBlueprintModifier_AddVariable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintModifier_AddVariable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBlueprintModifier::execAddVariable)
{
	P_GET_OBJECT(UBlueprint,Z_Param_Blueprint);
	P_GET_PROPERTY(FStrProperty,Z_Param_VarName);
	P_GET_PROPERTY(FStrProperty,Z_Param_VarType);
	P_GET_UBOOL(Z_Param_bIsArray);
	P_GET_PROPERTY(FStrProperty,Z_Param_Category);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBlueprintModifier::AddVariable(Z_Param_Blueprint,Z_Param_VarName,Z_Param_VarType,Z_Param_bIsArray,Z_Param_Category);
	P_NATIVE_END;
}
// ********** End Class UBlueprintModifier Function AddVariable ************************************

// ********** Begin Class UBlueprintModifier Function CompileBlueprint *****************************
struct Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics
{
	struct BlueprintModifier_eventCompileBlueprint_Parms
	{
		UBlueprint* Blueprint;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventCompileBlueprint_Parms, Blueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BlueprintModifier_eventCompileBlueprint_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlueprintModifier_eventCompileBlueprint_Parms), &Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBlueprintModifier, nullptr, "CompileBlueprint", Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::BlueprintModifier_eventCompileBlueprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::BlueprintModifier_eventCompileBlueprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBlueprintModifier::execCompileBlueprint)
{
	P_GET_OBJECT(UBlueprint,Z_Param_Blueprint);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBlueprintModifier::CompileBlueprint(Z_Param_Blueprint);
	P_NATIVE_END;
}
// ********** End Class UBlueprintModifier Function CompileBlueprint *******************************

// ********** Begin Class UBlueprintModifier Function CreateNewBlueprint ***************************
struct Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics
{
	struct BlueprintModifier_eventCreateNewBlueprint_Parms
	{
		FString BlueprintName;
		UClass* ParentClass;
		FString PackagePath;
		UBlueprint* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintModifier.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlueprintName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PackagePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_BlueprintName;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ParentClass;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PackagePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_BlueprintName = { "BlueprintName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventCreateNewBlueprint_Parms, BlueprintName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlueprintName_MetaData), NewProp_BlueprintName_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_ParentClass = { "ParentClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventCreateNewBlueprint_Parms, ParentClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_PackagePath = { "PackagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventCreateNewBlueprint_Parms, PackagePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PackagePath_MetaData), NewProp_PackagePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventCreateNewBlueprint_Parms, ReturnValue), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_BlueprintName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_ParentClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_PackagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBlueprintModifier, nullptr, "CreateNewBlueprint", Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::BlueprintModifier_eventCreateNewBlueprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::BlueprintModifier_eventCreateNewBlueprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBlueprintModifier::execCreateNewBlueprint)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_BlueprintName);
	P_GET_OBJECT(UClass,Z_Param_ParentClass);
	P_GET_PROPERTY(FStrProperty,Z_Param_PackagePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UBlueprint**)Z_Param__Result=UBlueprintModifier::CreateNewBlueprint(Z_Param_BlueprintName,Z_Param_ParentClass,Z_Param_PackagePath);
	P_NATIVE_END;
}
// ********** End Class UBlueprintModifier Function CreateNewBlueprint *****************************

// ********** Begin Class UBlueprintModifier Function SaveBlueprint ********************************
struct Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics
{
	struct BlueprintModifier_eventSaveBlueprint_Parms
	{
		UBlueprint* Blueprint;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintModifier.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintModifier_eventSaveBlueprint_Parms, Blueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BlueprintModifier_eventSaveBlueprint_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlueprintModifier_eventSaveBlueprint_Parms), &Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBlueprintModifier, nullptr, "SaveBlueprint", Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::BlueprintModifier_eventSaveBlueprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::BlueprintModifier_eventSaveBlueprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBlueprintModifier::execSaveBlueprint)
{
	P_GET_OBJECT(UBlueprint,Z_Param_Blueprint);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBlueprintModifier::SaveBlueprint(Z_Param_Blueprint);
	P_NATIVE_END;
}
// ********** End Class UBlueprintModifier Function SaveBlueprint **********************************

// ********** Begin Class UBlueprintModifier *******************************************************
void UBlueprintModifier::StaticRegisterNativesUBlueprintModifier()
{
	UClass* Class = UBlueprintModifier::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddComponent", &UBlueprintModifier::execAddComponent },
		{ "AddFunction", &UBlueprintModifier::execAddFunction },
		{ "AddVariable", &UBlueprintModifier::execAddVariable },
		{ "CompileBlueprint", &UBlueprintModifier::execCompileBlueprint },
		{ "CreateNewBlueprint", &UBlueprintModifier::execCreateNewBlueprint },
		{ "SaveBlueprint", &UBlueprintModifier::execSaveBlueprint },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UBlueprintModifier;
UClass* UBlueprintModifier::GetPrivateStaticClass()
{
	using TClass = UBlueprintModifier;
	if (!Z_Registration_Info_UClass_UBlueprintModifier.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BlueprintModifier"),
			Z_Registration_Info_UClass_UBlueprintModifier.InnerSingleton,
			StaticRegisterNativesUBlueprintModifier,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UBlueprintModifier.InnerSingleton;
}
UClass* Z_Construct_UClass_UBlueprintModifier_NoRegister()
{
	return UBlueprintModifier::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBlueprintModifier_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintModifier.h" },
		{ "ModuleRelativePath", "Public/BlueprintModifier.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBlueprintModifier_AddComponent, "AddComponent" }, // 2572310317
		{ &Z_Construct_UFunction_UBlueprintModifier_AddFunction, "AddFunction" }, // 822976706
		{ &Z_Construct_UFunction_UBlueprintModifier_AddVariable, "AddVariable" }, // 1487575694
		{ &Z_Construct_UFunction_UBlueprintModifier_CompileBlueprint, "CompileBlueprint" }, // 1187311406
		{ &Z_Construct_UFunction_UBlueprintModifier_CreateNewBlueprint, "CreateNewBlueprint" }, // 2647019289
		{ &Z_Construct_UFunction_UBlueprintModifier_SaveBlueprint, "SaveBlueprint" }, // 3904638510
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBlueprintModifier>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBlueprintModifier_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AerithEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintModifier_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBlueprintModifier_Statics::ClassParams = {
	&UBlueprintModifier::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintModifier_Statics::Class_MetaDataParams), Z_Construct_UClass_UBlueprintModifier_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBlueprintModifier()
{
	if (!Z_Registration_Info_UClass_UBlueprintModifier.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBlueprintModifier.OuterSingleton, Z_Construct_UClass_UBlueprintModifier_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBlueprintModifier.OuterSingleton;
}
UBlueprintModifier::UBlueprintModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBlueprintModifier);
UBlueprintModifier::~UBlueprintModifier() {}
// ********** End Class UBlueprintModifier *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h__Script_AerithEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBlueprintModifier, UBlueprintModifier::StaticClass, TEXT("UBlueprintModifier"), &Z_Registration_Info_UClass_UBlueprintModifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBlueprintModifier), 406738556U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h__Script_AerithEditor_4171182649(TEXT("/Script/AerithEditor"),
	Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h__Script_AerithEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h__Script_AerithEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
