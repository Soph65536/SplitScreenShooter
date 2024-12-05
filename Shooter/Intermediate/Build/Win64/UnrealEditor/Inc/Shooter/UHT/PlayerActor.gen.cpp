// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Shooter/Scripts/PlayerActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
SHOOTER_API UClass* Z_Construct_UClass_APlayerActor();
SHOOTER_API UClass* Z_Construct_UClass_APlayerActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_Shooter();
// End Cross Module References

// Begin Class APlayerActor
void APlayerActor::StaticRegisterNativesAPlayerActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayerActor);
UClass* Z_Construct_UClass_APlayerActor_NoRegister()
{
	return APlayerActor::StaticClass();
}
struct Z_Construct_UClass_APlayerActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Scripts/PlayerActor.h" },
		{ "ModuleRelativePath", "Scripts/PlayerActor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APlayerActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayerActor_Statics::ClassParams = {
	&APlayerActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerActor_Statics::Class_MetaDataParams), Z_Construct_UClass_APlayerActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlayerActor()
{
	if (!Z_Registration_Info_UClass_APlayerActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayerActor.OuterSingleton, Z_Construct_UClass_APlayerActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlayerActor.OuterSingleton;
}
template<> SHOOTER_API UClass* StaticClass<APlayerActor>()
{
	return APlayerActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerActor);
APlayerActor::~APlayerActor() {}
// End Class APlayerActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_PlayerActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlayerActor, APlayerActor::StaticClass, TEXT("APlayerActor"), &Z_Registration_Info_UClass_APlayerActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerActor), 2370855456U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_PlayerActor_h_2263189099(TEXT("/Script/Shooter"),
	Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_PlayerActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_PlayerActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
