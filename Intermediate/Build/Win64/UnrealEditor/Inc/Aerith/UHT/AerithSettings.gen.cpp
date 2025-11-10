// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AerithSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAerithSettings() {}

// ********** Begin Cross Module References ********************************************************
AERITH_API UClass* Z_Construct_UClass_UAerithSettings();
AERITH_API UClass* Z_Construct_UClass_UAerithSettings_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_Aerith();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAerithSettings **********************************************************
void UAerithSettings::StaticRegisterNativesUAerithSettings()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAerithSettings;
UClass* UAerithSettings::GetPrivateStaticClass()
{
	using TClass = UAerithSettings;
	if (!Z_Registration_Info_UClass_UAerithSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AerithSettings"),
			Z_Registration_Info_UClass_UAerithSettings.InnerSingleton,
			StaticRegisterNativesUAerithSettings,
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
	return Z_Registration_Info_UClass_UAerithSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UAerithSettings_NoRegister()
{
	return UAerithSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAerithSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AerithSettings.h" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClaudeAPIKey_MetaData[] = {
		{ "Category", "AI API" },
		{ "DisplayName", "Claude API Key" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_APIEndpoint_MetaData[] = {
		{ "Category", "AI API" },
		{ "DisplayName", "API Endpoint" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Model_MetaData[] = {
		{ "Category", "AI API" },
		{ "DisplayName", "Model" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxTokens_MetaData[] = {
		{ "Category", "AI API" },
		{ "ClampMax", "200000" },
		{ "ClampMin", "1024" },
		{ "DisplayName", "Max Tokens" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Temperature_MetaData[] = {
		{ "Category", "AI API" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "DisplayName", "Temperature" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVerboseLogging_MetaData[] = {
		{ "Category", "Debug" },
		{ "DisplayName", "Verbose Logging" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxContextCharacters_MetaData[] = {
		{ "Category", "Advanced" },
		{ "ClampMax", "100000" },
		{ "ClampMin", "1000" },
		{ "DisplayName", "Max Context Characters" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeDetailedNodeAnalysis_MetaData[] = {
		{ "Category", "Advanced" },
		{ "DisplayName", "Include Detailed Node Analysis" },
		{ "ModuleRelativePath", "Public/AerithSettings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClaudeAPIKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_APIEndpoint;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Model;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxTokens;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Temperature;
	static void NewProp_bVerboseLogging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVerboseLogging;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxContextCharacters;
	static void NewProp_bIncludeDetailedNodeAnalysis_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeDetailedNodeAnalysis;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAerithSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_ClaudeAPIKey = { "ClaudeAPIKey", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAerithSettings, ClaudeAPIKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClaudeAPIKey_MetaData), NewProp_ClaudeAPIKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_APIEndpoint = { "APIEndpoint", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAerithSettings, APIEndpoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_APIEndpoint_MetaData), NewProp_APIEndpoint_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_Model = { "Model", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAerithSettings, Model), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Model_MetaData), NewProp_Model_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_MaxTokens = { "MaxTokens", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAerithSettings, MaxTokens), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxTokens_MetaData), NewProp_MaxTokens_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_Temperature = { "Temperature", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAerithSettings, Temperature), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Temperature_MetaData), NewProp_Temperature_MetaData) };
void Z_Construct_UClass_UAerithSettings_Statics::NewProp_bVerboseLogging_SetBit(void* Obj)
{
	((UAerithSettings*)Obj)->bVerboseLogging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_bVerboseLogging = { "bVerboseLogging", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAerithSettings), &Z_Construct_UClass_UAerithSettings_Statics::NewProp_bVerboseLogging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVerboseLogging_MetaData), NewProp_bVerboseLogging_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_MaxContextCharacters = { "MaxContextCharacters", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAerithSettings, MaxContextCharacters), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxContextCharacters_MetaData), NewProp_MaxContextCharacters_MetaData) };
void Z_Construct_UClass_UAerithSettings_Statics::NewProp_bIncludeDetailedNodeAnalysis_SetBit(void* Obj)
{
	((UAerithSettings*)Obj)->bIncludeDetailedNodeAnalysis = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAerithSettings_Statics::NewProp_bIncludeDetailedNodeAnalysis = { "bIncludeDetailedNodeAnalysis", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAerithSettings), &Z_Construct_UClass_UAerithSettings_Statics::NewProp_bIncludeDetailedNodeAnalysis_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIncludeDetailedNodeAnalysis_MetaData), NewProp_bIncludeDetailedNodeAnalysis_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAerithSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_ClaudeAPIKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_APIEndpoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_Model,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_MaxTokens,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_Temperature,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_bVerboseLogging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_MaxContextCharacters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithSettings_Statics::NewProp_bIncludeDetailedNodeAnalysis,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAerithSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAerithSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Aerith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAerithSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAerithSettings_Statics::ClassParams = {
	&UAerithSettings::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAerithSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAerithSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAerithSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UAerithSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAerithSettings()
{
	if (!Z_Registration_Info_UClass_UAerithSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAerithSettings.OuterSingleton, Z_Construct_UClass_UAerithSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAerithSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAerithSettings);
UAerithSettings::~UAerithSettings() {}
// ********** End Class UAerithSettings ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h__Script_Aerith_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAerithSettings, UAerithSettings::StaticClass, TEXT("UAerithSettings"), &Z_Registration_Info_UClass_UAerithSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAerithSettings), 192532667U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h__Script_Aerith_215127644(TEXT("/Script/Aerith"),
	Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h__Script_Aerith_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h__Script_Aerith_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
