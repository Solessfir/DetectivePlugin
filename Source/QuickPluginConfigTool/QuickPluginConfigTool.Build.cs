// Copyright 2020 - Trifolium Digital Limited

using UnrealBuildTool;

public class QuickPluginConfigTool : ModuleRules
{
	public QuickPluginConfigTool(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.Add("Core");

		PrivateDependencyModuleNames.AddRange
		(
			new[]
            {
                "Projects",
                "InputCore",
                "UnrealEd",
                "LevelEditor",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "PropertyEditor",
                "TargetPlatform",
            }
		);
	}
}
