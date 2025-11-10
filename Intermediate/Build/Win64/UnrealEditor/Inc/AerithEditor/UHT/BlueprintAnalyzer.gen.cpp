// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BlueprintAnalyzer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeBlueprintAnalyzer() {}

// ********** Begin Cross Module References ********************************************************
AERITHEDITOR_API UClass* Z_Construct_UClass_UBlueprintAnalyzer();
AERITHEDITOR_API UClass* Z_Construct_UClass_UBlueprintAnalyzer_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_UBlueprint_NoRegister();
UPackage* Z_Construct_UPackage__Script_AerithEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBlueprintAnalyzer Function AnalyzeBlueprint *****************************
struct Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics
{
	struct BlueprintAnalyzer_eventAnalyzeBlueprint_Parms
	{
		UBlueprint* Blueprint;
		bool bIncludeDetailedNodes;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BlueprintAnalyzer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Blueprint;
	static void NewProp_bIncludeDetailedNodes_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeDetailedNodes;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_Blueprint = { "Blueprint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintAnalyzer_eventAnalyzeBlueprint_Parms, Blueprint), Z_Construct_UClass_UBlueprint_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_bIncludeDetailedNodes_SetBit(void* Obj)
{
	((BlueprintAnalyzer_eventAnalyzeBlueprint_Parms*)Obj)->bIncludeDetailedNodes = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_bIncludeDetailedNodes = { "bIncludeDetailedNodes", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlueprintAnalyzer_eventAnalyzeBlueprint_Parms), &Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_bIncludeDetailedNodes_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlueprintAnalyzer_eventAnalyzeBlueprint_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_Blueprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_bIncludeDetailedNodes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBlueprintAnalyzer, nullptr, "AnalyzeBlueprint", Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::BlueprintAnalyzer_eventAnalyzeBlueprint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::BlueprintAnalyzer_eventAnalyzeBlueprint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBlueprintAnalyzer::execAnalyzeBlueprint)
{
	P_GET_OBJECT(UBlueprint,Z_Param_Blueprint);
	P_GET_UBOOL(Z_Param_bIncludeDetailedNodes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBlueprintAnalyzer::AnalyzeBlueprint(Z_Param_Blueprint,Z_Param_bIncludeDetailedNodes);
	P_NATIVE_END;
}
// ********** End Class UBlueprintAnalyzer Function AnalyzeBlueprint *******************************

// ********** Begin Class UBlueprintAnalyzer *******************************************************
void UBlueprintAnalyzer::StaticRegisterNativesUBlueprintAnalyzer()
{
	UClass* Class = UBlueprintAnalyzer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AnalyzeBlueprint", &UBlueprintAnalyzer::execAnalyzeBlueprint },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UBlueprintAnalyzer;
UClass* UBlueprintAnalyzer::GetPrivateStaticClass()
{
	using TClass = UBlueprintAnalyzer;
	if (!Z_Registration_Info_UClass_UBlueprintAnalyzer.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BlueprintAnalyzer"),
			Z_Registration_Info_UClass_UBlueprintAnalyzer.InnerSingleton,
			StaticRegisterNativesUBlueprintAnalyzer,
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
	return Z_Registration_Info_UClass_UBlueprintAnalyzer.InnerSingleton;
}
UClass* Z_Construct_UClass_UBlueprintAnalyzer_NoRegister()
{
	return UBlueprintAnalyzer::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBlueprintAnalyzer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BlueprintAnalyzer.h" },
		{ "ModuleRelativePath", "Public/BlueprintAnalyzer.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBlueprintAnalyzer_AnalyzeBlueprint, "AnalyzeBlueprint" }, // 1057632750
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBlueprintAnalyzer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBlueprintAnalyzer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AerithEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintAnalyzer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBlueprintAnalyzer_Statics::ClassParams = {
	&UBlueprintAnalyzer::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlueprintAnalyzer_Statics::Class_MetaDataParams), Z_Construct_UClass_UBlueprintAnalyzer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBlueprintAnalyzer()
{
	if (!Z_Registration_Info_UClass_UBlueprintAnalyzer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBlueprintAnalyzer.OuterSingleton, Z_Construct_UClass_UBlueprintAnalyzer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBlueprintAnalyzer.OuterSingleton;
}
UBlueprintAnalyzer::UBlueprintAnalyzer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBlueprintAnalyzer);
UBlueprintAnalyzer::~UBlueprintAnalyzer() {}
// ********** End Class UBlueprintAnalyzer *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h__Script_AerithEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBlueprintAnalyzer, UBlueprintAnalyzer::StaticClass, TEXT("UBlueprintAnalyzer"), &Z_Registration_Info_UClass_UBlueprintAnalyzer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBlueprintAnalyzer), 2330945431U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h__Script_AerithEditor_2208328666(TEXT("/Script/AerithEditor"),
	Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h__Script_AerithEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h__Script_AerithEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
