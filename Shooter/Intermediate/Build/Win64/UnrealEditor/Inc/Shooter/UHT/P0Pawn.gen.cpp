// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Shooter/Scripts/P0Pawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeP0Pawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
SHOOTER_API UClass* Z_Construct_UClass_AP0Pawn();
SHOOTER_API UClass* Z_Construct_UClass_AP0Pawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Shooter();
// End Cross Module References

// Begin Class AP0Pawn
void AP0Pawn::StaticRegisterNativesAP0Pawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AP0Pawn);
UClass* Z_Construct_UClass_AP0Pawn_NoRegister()
{
	return AP0Pawn::StaticClass();
}
struct Z_Construct_UClass_AP0Pawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Scripts/P0Pawn.h" },
		{ "ModuleRelativePath", "Scripts/P0Pawn.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AP0Pawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AP0Pawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Shooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AP0Pawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AP0Pawn_Statics::ClassParams = {
	&AP0Pawn::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AP0Pawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AP0Pawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AP0Pawn()
{
	if (!Z_Registration_Info_UClass_AP0Pawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AP0Pawn.OuterSingleton, Z_Construct_UClass_AP0Pawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AP0Pawn.OuterSingleton;
}
template<> SHOOTER_API UClass* StaticClass<AP0Pawn>()
{
	return AP0Pawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AP0Pawn);
AP0Pawn::~AP0Pawn() {}
// End Class AP0Pawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_P0Pawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AP0Pawn, AP0Pawn::StaticClass, TEXT("AP0Pawn"), &Z_Registration_Info_UClass_AP0Pawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AP0Pawn), 2792553932U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_P0Pawn_h_1812650444(TEXT("/Script/Shooter"),
	Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_P0Pawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_User1_Documents___Unreal_Projects___SplitScreenShooter_Shooter_Source_Shooter_Scripts_P0Pawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
