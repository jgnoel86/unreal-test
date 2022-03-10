// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UMGIntro : ModuleRules
{
	public UMGIntro(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HTTP", });
		PrivateDependencyModuleNames.AddRange(new string[] {"Json", "JsonUtilities" });
	}
}
