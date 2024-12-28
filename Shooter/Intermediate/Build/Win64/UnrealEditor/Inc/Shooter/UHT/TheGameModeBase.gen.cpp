// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Shooter/Scripts/TheGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTheGameModeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
SHOOTER_API UClass* Z_Construct_UClass_ATheGameModeBase();
SHOOTER_API UClass* Z_Construct_UClass_ATheGameModeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_Shooter();
// End Cross Module References

// Begin Class ATheGameModeBase
void ATheGameModeBase::StaticRegisterNativesATheGameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATheGameModeBase);
UClass* Z_Construct_UClass_ATheGameModeBase_NoRegister()
{
	return ATheGameModeBase::StaticClass();
}
struct Z_Construct_UClass_ATheGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Scripts/TheGameModeBase.h" },
		{ "ModuleRelativePath", "Scripts/TheGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoundLengthSecs_MetaData[] = {
		{ "Category", "TheGameModeBase" },
		{ "ModuleRelativePath", "Scripts/TheGameModeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoundTimer_MetaData[] = {
		{ "Category", "TheGameModeBase" },
		{ "ModuleRelativePath", "Scripts/TheGameModeBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentRound_MetaData[] = {
		{ "Category", "TheGameModeBase" },
		{ "ModuleRelativePath", "Scripts/TheGameModeBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RoundLengthSecs;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RoundTimer;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentRound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATheGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATheGameModeBase_Statics::NewProp_RoundLengthSecs = { "RoundLengthSecs", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATheGameModeBase, RoundLengthSecs), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoundLengthSecs_MetaData), NewProp_RoundLengthSecs_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATheGameModeBase_Statics::NewProp_RoundTimer = { "RoundTimer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATheGameModeBase, RoundTimer), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoundTimer_MetaData), NewProp_RoundTimer_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATheGameModeBase_Statics::NewProp_CurrentRound = { "CurrentRound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATheGameModeBase, CurrentRound), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentRound_MetaData), NewProp_CurrentRound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATheGameModeBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATheGameModeBase_Statics::NewProp_RoundLengthSecs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATheGameModeBase_Statics::NewProp_RoundTimer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATheGameModeBase_Statics::NewProp_CurrentRound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATheGameModeBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATheGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATheGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATheGameModeBase_Statics::ClassParams = {
	&ATheGameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATheGameModeBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATheGameModeBase_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATheGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ATheGameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATheGameModeBase()
{
	if (!Z_Registration_Info_UClass_ATheGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATheGameModeBase.OuterSingleton, Z_Construct_UClass_ATheGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATheGameModeBase.OuterSingleton;
}
template<> SHOOTER_API UClass* StaticClass<ATheGameModeBase>()
{
	return ATheGameModeBase::StaticClass();
}
ATheGameModeBase::ATheGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATheGameModeBase);
ATheGameModeBase::~ATheGameModeBase() {}
// End Class ATheGameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATheGameModeBase, ATheGameModeBase::StaticClass, TEXT("ATheGameModeBase"), &Z_Registration_Info_UClass_ATheGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATheGameModeBase), 3933379612U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_3272771805(TEXT("/Script/Shooter"),
	Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
