// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CLASSPROJECT_MyObject_generated_h
#error "MyObject.generated.h already included, missing '#pragma once' in MyObject.h"
#endif
#define CLASSPROJECT_MyObject_generated_h

#define ClassProject_Source_ClassProject_Public_MyObject_h_15_SPARSE_DATA
#define ClassProject_Source_ClassProject_Public_MyObject_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMyFunction);


#define ClassProject_Source_ClassProject_Public_MyObject_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMyFunction);


#define ClassProject_Source_ClassProject_Public_MyObject_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyObject(); \
	friend struct Z_Construct_UClass_UMyObject_Statics; \
public: \
	DECLARE_CLASS(UMyObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ClassProject"), NO_API) \
	DECLARE_SERIALIZER(UMyObject)


#define ClassProject_Source_ClassProject_Public_MyObject_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUMyObject(); \
	friend struct Z_Construct_UClass_UMyObject_Statics; \
public: \
	DECLARE_CLASS(UMyObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ClassProject"), NO_API) \
	DECLARE_SERIALIZER(UMyObject)


#define ClassProject_Source_ClassProject_Public_MyObject_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyObject(UMyObject&&); \
	NO_API UMyObject(const UMyObject&); \
public:


#define ClassProject_Source_ClassProject_Public_MyObject_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyObject(UMyObject&&); \
	NO_API UMyObject(const UMyObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyObject)


#define ClassProject_Source_ClassProject_Public_MyObject_h_15_PRIVATE_PROPERTY_OFFSET
#define ClassProject_Source_ClassProject_Public_MyObject_h_12_PROLOG
#define ClassProject_Source_ClassProject_Public_MyObject_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_PRIVATE_PROPERTY_OFFSET \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_SPARSE_DATA \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_RPC_WRAPPERS \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_INCLASS \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ClassProject_Source_ClassProject_Public_MyObject_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_PRIVATE_PROPERTY_OFFSET \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_SPARSE_DATA \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_INCLASS_NO_PURE_DECLS \
	ClassProject_Source_ClassProject_Public_MyObject_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CLASSPROJECT_API UClass* StaticClass<class UMyObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ClassProject_Source_ClassProject_Public_MyObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
