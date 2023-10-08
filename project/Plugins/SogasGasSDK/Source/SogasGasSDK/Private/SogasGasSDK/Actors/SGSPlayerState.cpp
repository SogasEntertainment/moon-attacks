#include "SogasGasSDK/Actors/SGSPlayerState.h"

ASGSPlayerState::ASGSPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* ASGSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
