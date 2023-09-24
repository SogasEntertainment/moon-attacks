#include "SogasGasSDK/Actors/SGSPawn.h"

ASGSPawn::ASGSPawn()
{
	AbilitySystemComponent = CreateDefaultSubobject<USGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* ASGSPawn::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
