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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATheGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
struct Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATheGameModeBase, ATheGameModeBase::StaticClass, TEXT("ATheGameModeBase"), &Z_Registration_Info_UClass_ATheGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATheGameModeBase), 879612834U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_1339578538(TEXT("/Script/Shooter"),
	Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_TheGameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
