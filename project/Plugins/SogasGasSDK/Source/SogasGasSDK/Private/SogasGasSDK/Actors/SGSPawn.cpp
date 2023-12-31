#include "SogasGasSDK/Actors/SGSPawn.h"

ASGSPawn::ASGSPawn()
{
	AbilitySystemComponent = CreateDefaultSubobject<USGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* ASGSPawn::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASGSPawn::PossessedBy(AController* InNewController)
{
	Super::PossessedBy(InNewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}
