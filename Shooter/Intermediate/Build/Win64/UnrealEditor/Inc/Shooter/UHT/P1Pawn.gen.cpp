// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Shooter/Scripts/P1Pawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeP1Pawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
SHOOTER_API UClass* Z_Construct_UClass_AP1Pawn();
SHOOTER_API UClass* Z_Construct_UClass_AP1Pawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Shooter();
// End Cross Module References

// Begin Class AP1Pawn
void AP1Pawn::StaticRegisterNativesAP1Pawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AP1Pawn);
UClass* Z_Construct_UClass_AP1Pawn_NoRegister()
{
	return AP1Pawn::StaticClass();
}
struct Z_Construct_UClass_AP1Pawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Scripts/P1Pawn.h" },
		{ "ModuleRelativePath", "Scripts/P1Pawn.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AP1Pawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AP1Pawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AP1Pawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AP1Pawn_Statics::ClassParams = {
	&AP1Pawn::StaticClass,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AP1Pawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AP1Pawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AP1Pawn()
{
	if (!Z_Registration_Info_UClass_AP1Pawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AP1Pawn.OuterSingleton, Z_Construct_UClass_AP1Pawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AP1Pawn.OuterSingleton;
}
template<> SHOOTER_API UClass* StaticClass<AP1Pawn>()
{
	return AP1Pawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AP1Pawn);
AP1Pawn::~AP1Pawn() {}
// End Class AP1Pawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_P1Pawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AP1Pawn, AP1Pawn::StaticClass, TEXT("AP1Pawn"), &Z_Registration_Info_UClass_AP1Pawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AP1Pawn), 1358725304U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_P1Pawn_h_2397129694(TEXT("/Script/Shooter"),
	Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_P1Pawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_sophe_Documents_Unreal_Projects_SplitScreenShooter_Shooter_Source_Shooter_Scripts_P1Pawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
