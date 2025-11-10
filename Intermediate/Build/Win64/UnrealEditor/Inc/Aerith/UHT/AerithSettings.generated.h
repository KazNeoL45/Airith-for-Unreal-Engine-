// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AerithSettings.h"

#ifdef AERITH_AerithSettings_generated_h
#error "AerithSettings.generated.h already included, missing '#pragma once' in AerithSettings.h"
#endif
#define AERITH_AerithSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UAerithSettings **********************************************************
struct Z_Construct_UClass_UAerithSettings_Statics;
AERITH_API UClass* Z_Construct_UClass_UAerithSettings_NoRegister();

#define FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAerithSettings(); \
	friend struct ::Z_Construct_UClass_UAerithSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AERITH_API UClass* ::Z_Construct_UClass_UAerithSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UAerithSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/Aerith"), Z_Construct_UClass_UAerithSettings_NoRegister) \
	DECLARE_SERIALIZER(UAerithSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Editor");} \



#define FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAerithSettings(UAerithSettings&&) = delete; \
	UAerithSettings(const UAerithSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAerithSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAerithSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAerithSettings) \
	NO_API virtual ~UAerithSettings();


#define FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h_9_PROLOG
#define FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h_12_INCLASS_NO_PURE_DECLS \
	FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAerithSettings;

// ********** End Class UAerithSettings ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_codenameCrimson_Plugins_Aerith_Source_Aerith_Public_AerithSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
