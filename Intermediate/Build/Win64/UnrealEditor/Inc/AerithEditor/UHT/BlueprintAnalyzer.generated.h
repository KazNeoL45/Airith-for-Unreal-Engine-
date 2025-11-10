// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlueprintAnalyzer.h"

#ifdef AERITHEDITOR_BlueprintAnalyzer_generated_h
#error "BlueprintAnalyzer.generated.h already included, missing '#pragma once' in BlueprintAnalyzer.h"
#endif
#define AERITHEDITOR_BlueprintAnalyzer_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBlueprint;

// ********** Begin Class UBlueprintAnalyzer *******************************************************
#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAnalyzeBlueprint);


struct Z_Construct_UClass_UBlueprintAnalyzer_Statics;
AERITHEDITOR_API UClass* Z_Construct_UClass_UBlueprintAnalyzer_NoRegister();

#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBlueprintAnalyzer(); \
	friend struct ::Z_Construct_UClass_UBlueprintAnalyzer_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AERITHEDITOR_API UClass* ::Z_Construct_UClass_UBlueprintAnalyzer_NoRegister(); \
public: \
	DECLARE_CLASS2(UBlueprintAnalyzer, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AerithEditor"), Z_Construct_UClass_UBlueprintAnalyzer_NoRegister) \
	DECLARE_SERIALIZER(UBlueprintAnalyzer)


#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBlueprintAnalyzer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBlueprintAnalyzer(UBlueprintAnalyzer&&) = delete; \
	UBlueprintAnalyzer(const UBlueprintAnalyzer&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBlueprintAnalyzer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBlueprintAnalyzer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBlueprintAnalyzer) \
	NO_API virtual ~UBlueprintAnalyzer();


#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_10_PROLOG
#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_13_INCLASS_NO_PURE_DECLS \
	FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBlueprintAnalyzer;

// ********** End Class UBlueprintAnalyzer *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintAnalyzer_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
