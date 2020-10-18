using UnrealBuildTool;

public class MyGameEditor : ModuleRules
{
	public MyGameEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"PropertyEditor",
				"MyGame",
			});

		PublicIncludePaths.AddRange(
			new string[]
			{
				"MyGameEditor/Public"
			});

		PrivateIncludePaths.AddRange(
			new string[]
			{
				"MyGameEditor/Private"
			});
	}
}
