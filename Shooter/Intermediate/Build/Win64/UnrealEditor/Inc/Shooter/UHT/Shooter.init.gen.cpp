// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooter_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Shooter;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Shooter()
	{
		if (!Z_Registration_Info_UPackage__Script_Shooter.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Shooter",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xFE39BD2A,
				0xD32218C4,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Shooter.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Shooter.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Shooter(Z_Construct_UPackage__Script_Shooter, TEXT("/Script/Shooter"), Z_Registration_Info_UPackage__Script_Shooter, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xFE39BD2A, 0xD32218C4));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
