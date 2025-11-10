// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlueprintModifier.h"

#ifdef AERITHEDITOR_BlueprintModifier_generated_h
#error "BlueprintModifier.generated.h already included, missing '#pragma once' in BlueprintModifier.h"
#endif
#define AERITHEDITOR_BlueprintModifier_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBlueprint;
class UClass;
class UEdGraph;
class UObject;

// ********** Begin Class UBlueprintModifier *******************************************************
#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSaveBlueprint); \
	DECLARE_FUNCTION(execCompileBlueprint); \
	DECLARE_FUNCTION(execAddComponent); \
	DECLARE_FUNCTION(execAddFunction); \
	DECLARE_FUNCTION(execAddVariable); \
	DECLARE_FUNCTION(execCreateNewBlueprint);


struct Z_Construct_UClass_UBlueprintModifier_Statics;
AERITHEDITOR_API UClass* Z_Construct_UClass_UBlueprintModifier_NoRegister();

#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBlueprintModifier(); \
	friend struct ::Z_Construct_UClass_UBlueprintModifier_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend AERITHEDITOR_API UClass* ::Z_Construct_UClass_UBlueprintModifier_NoRegister(); \
public: \
	DECLARE_CLASS2(UBlueprintModifier, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AerithEditor"), Z_Construct_UClass_UBlueprintModifier_NoRegister) \
	DECLARE_SERIALIZER(UBlueprintModifier)


#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBlueprintModifier(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBlueprintModifier(UBlueprintModifier&&) = delete; \
	UBlueprintModifier(const UBlueprintModifier&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBlueprintModifier); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBlueprintModifier); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBlueprintModifier) \
	NO_API virtual ~UBlueprintModifier();


#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_11_PROLOG
#define FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_14_INCLASS_NO_PURE_DECLS \
	FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBlueprintModifier;

// ********** End Class UBlueprintModifier *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_codenameCrimson_Plugins_Aerith_Source_AerithEditor_Public_BlueprintModifier_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
