#include "MoonPlayerController.h"
#include "MoonAttacks/Abilities/AttributeSets/MoonBaseAttributeSet.h"
#include "MoonPlayerState.h"

void AMoonPlayerController::Kill()
{
	if (auto PlayerStateVariable = GetPlayerState<AMoonPlayerState>())
	{
		PlayerStateVariable->GetAttributeSet<UMoonBaseAttributeSet>(UMoonBaseAttributeSet::StaticClass())->SetHealth(0.0f);
	}
}
