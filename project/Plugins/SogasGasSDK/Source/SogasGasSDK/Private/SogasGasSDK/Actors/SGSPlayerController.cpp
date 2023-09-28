#include "SogasGasSDK/Actors/SGSPlayerController.h"
#include "SogasGasSDK/Actors/SGSPlayerState.h"

void ASGSPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// We should document that the use of ASGSPlayerController should be bound to the use of
	// ASGSPlayerState if the user wants to automatically init the ability actor info.
	// Otherwise this logic will need to be implemented manually by the user.
	if (auto PlayerStateVariable = GetPlayerState<ASGSPlayerState>())
	{
		PlayerStateVariable->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerStateVariable, InPawn);
	}
}
