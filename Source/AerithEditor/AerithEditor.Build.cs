// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AerithEditor : ModuleRules
{
	public AerithEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
			}
		);


		PrivateIncludePaths.AddRange(
			new string[] {
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Aerith",
				"UnrealEd",
				"BlueprintGraph",
				"Kismet",
				"KismetCompiler",
				"GraphEditor",
				"HTTP",
				"Json",
				"JsonUtilities"
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"InputCore",
				"EditorFramework",
				"ToolMenus",
				"Slate",
				"SlateCore",
				"EditorStyle",
				"PropertyEditor",
				"Settings",
				"AssetTools",
				"ContentBrowser",
				"WorkspaceMenuStructure",
				"ToolWidgets"
			}
		);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
		);
	}
}
