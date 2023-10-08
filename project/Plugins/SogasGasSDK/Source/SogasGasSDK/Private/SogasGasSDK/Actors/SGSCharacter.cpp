#include "SogasGasSDK/Actors/SGSCharacter.h"

ASGSCharacter::ASGSCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<USGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* ASGSCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASGSCharacter::PossessedBy(AController* InNewController)
{
	Super::PossessedBy(InNewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}
