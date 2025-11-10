// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ClaudeAPIClient.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeClaudeAPIClient() {}

// ********** Begin Cross Module References ********************************************************
AERITH_API UClass* Z_Construct_UClass_UClaudeAPIClient();
AERITH_API UClass* Z_Construct_UClass_UClaudeAPIClient_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
UPackage* Z_Construct_UPackage__Script_Aerith();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UClaudeAPIClient *********************************************************
void UClaudeAPIClient::StaticRegisterNativesUClaudeAPIClient()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UClaudeAPIClient;
UClass* UClaudeAPIClient::GetPrivateStaticClass()
{
	using TClass = UClaudeAPIClient;
	if (!Z_Registration_Info_UClass_UClaudeAPIClient.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ClaudeAPIClient"),
			Z_Registration_Info_UClass_UClaudeAPIClient.InnerSingleton,
			StaticRegisterNativesUClaudeAPIClient,
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
	return Z_Registration_Info_UClass_UClaudeAPIClient.InnerSingleton;
}
UClass* Z_Construct_UClass_UClaudeAPIClient_NoRegister()
{
	return UClaudeAPIClient::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UClaudeAPIClient_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ClaudeAPIClient.h" },
		{ "ModuleRelativePath", "Public/ClaudeAPIClient.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClaudeAPIClient>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UClaudeAPIClient_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Aerith,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClaudeAPIClient_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UClaudeAPIClient_Statics::ClassParams = {
	&UClaudeAPIClient::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClaudeAPIClient_Statics::Class_MetaDataParams), Z_Construct_UClass_UClaudeAPIClient_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UClaudeAPIClient()
{
	if (!Z_Registration_Info_UClass_UClaudeAPIClient.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClaudeAPIClient.OuterSingleton, Z_Construct_UClass_UClaudeAPIClient_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UClaudeAPIClient.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UClaudeAPIClient);
UClaudeAPIClient::~UClaudeAPIClient() {}
// ********** End Class UClaudeAPIClient ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_ClaudeAPIClient_h__Script_Aerith_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UClaudeAPIClient, UClaudeAPIClient::StaticClass, TEXT("UClaudeAPIClient"), &Z_Registration_Info_UClass_UClaudeAPIClient, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClaudeAPIClient), 2627993496U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_ClaudeAPIClient_h__Script_Aerith_3027328664(TEXT("/Script/Aerith"),
	Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_ClaudeAPIClient_h__Script_Aerith_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_ClaudeAPIClient_h__Script_Aerith_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
