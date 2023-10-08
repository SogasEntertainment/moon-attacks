#include "SogasGasSDK/Actors/SGSActor.h"

ASGSActor::ASGSActor()
{
	AbilitySystemComponent = CreateDefaultSubobject<USGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* ASGSActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
