// Copyright 2022 Namman. All Rights Reserved.

using UnrealBuildTool;

public class ActionCameraManager : ModuleRules
{
	public ActionCameraManager(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
