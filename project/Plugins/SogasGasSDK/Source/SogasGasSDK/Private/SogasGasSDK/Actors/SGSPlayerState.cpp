#include "SogasGasSDK/Actors/SGSPlayerState.h"

ASGSPlayerState::ASGSPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

USGSAbilitySystemComponent* ASGSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
