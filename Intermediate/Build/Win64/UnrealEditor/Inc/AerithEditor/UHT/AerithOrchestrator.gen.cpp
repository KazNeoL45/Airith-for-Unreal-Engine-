// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AerithOrchestrator.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeAerithOrchestrator() {}

// ********** Begin Cross Module References ********************************************************
AERITH_API UClass* Z_Construct_UClass_UClaudeAPIClient_NoRegister();
AERITHEDITOR_API UClass* Z_Construct_UClass_UAerithOrchestrator();
AERITHEDITOR_API UClass* Z_Construct_UClass_UAerithOrchestrator_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_AerithEditor();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UAerithOrchestrator ******************************************************
void UAerithOrchestrator::StaticRegisterNativesUAerithOrchestrator()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UAerithOrchestrator;
UClass* UAerithOrchestrator::GetPrivateStaticClass()
{
	using TClass = UAerithOrchestrator;
	if (!Z_Registration_Info_UClass_UAerithOrchestrator.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AerithOrchestrator"),
			Z_Registration_Info_UClass_UAerithOrchestrator.InnerSingleton,
			StaticRegisterNativesUAerithOrchestrator,
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
	return Z_Registration_Info_UClass_UAerithOrchestrator.InnerSingleton;
}
UClass* Z_Construct_UClass_UAerithOrchestrator_NoRegister()
{
	return UAerithOrchestrator::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAerithOrchestrator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AerithOrchestrator.h" },
		{ "ModuleRelativePath", "Public/AerithOrchestrator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_APIClient_MetaData[] = {
		{ "ModuleRelativePath", "Public/AerithOrchestrator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_APIClient;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAerithOrchestrator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAerithOrchestrator_Statics::NewProp_APIClient = { "APIClient", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAerithOrchestrator, APIClient), Z_Construct_UClass_UClaudeAPIClient_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_APIClient_MetaData), NewProp_APIClient_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAerithOrchestrator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAerithOrchestrator_Statics::NewProp_APIClient,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAerithOrchestrator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAerithOrchestrator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AerithEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAerithOrchestrator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAerithOrchestrator_Statics::ClassParams = {
	&UAerithOrchestrator::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAerithOrchestrator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAerithOrchestrator_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAerithOrchestrator_Statics::Class_MetaDataParams), Z_Construct_UClass_UAerithOrchestrator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAerithOrchestrator()
{
	if (!Z_Registration_Info_UClass_UAerithOrchestrator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAerithOrchestrator.OuterSingleton, Z_Construct_UClass_UAerithOrchestrator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAerithOrchestrator.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAerithOrchestrator);
UAerithOrchestrator::~UAerithOrchestrator() {}
// ********** End Class UAerithOrchestrator ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_AerithOrchestrator_h__Script_AerithEditor_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAerithOrchestrator, UAerithOrchestrator::StaticClass, TEXT("UAerithOrchestrator"), &Z_Registration_Info_UClass_UAerithOrchestrator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAerithOrchestrator), 1040546031U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_AerithOrchestrator_h__Script_AerithEditor_1849246127(TEXT("/Script/AerithEditor"),
	Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_AerithOrchestrator_h__Script_AerithEditor_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_AerithOrchestrator_h__Script_AerithEditor_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
