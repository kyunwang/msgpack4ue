// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class msgpack4ue : ModuleRules
{
	public msgpack4ue(ReadOnlyTargetRules Target) : base(Target)
	{
		// PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		// Allows for try...catch blocks. Use sparsely, as it may impact preformance 
		// bEnableExceptions = true;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				//"../Resources/msgpack"
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				//"../Resources/msgpack"
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Json",
				"JsonUtilities",
				"Projects",
				"Engine"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
