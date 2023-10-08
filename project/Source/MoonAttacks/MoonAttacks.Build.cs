// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MoonAttacks : ModuleRules
{
    public MoonAttacks(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "SogasGasSDK"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities" });
    }
}
