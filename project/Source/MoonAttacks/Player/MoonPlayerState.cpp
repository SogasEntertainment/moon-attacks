#include "MoonPlayerState.h"
#include "MoonAttacks/Abilities/AttributeSets/MoonBaseAttributeSet.h"
#include "MoonAttacks/GameMode/MoonAttacksGameModeBase.h"
#include "MoonCharacter.h"

AMoonPlayerState::AMoonPlayerState()
{
}

void AMoonPlayerState::BeginPlay()
{
	if (auto ASC = GetAbilitySystemComponent())
	{
		if (auto AttributeSet = GetAttributeSet<UMoonBaseAttributeSet>(UMoonBaseAttributeSet::StaticClass()))
		{
			OnHealthChangedDelegateHandle = ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &AMoonPlayerState::OnHealthChanged);
		}
	}
}

bool AMoonPlayerState::IsAlive() const
{
	return GetHealth() > 0;
}

float AMoonPlayerState::GetHealth() const
{
	if (const auto AttributeSet = Cast<UMoonBaseAttributeSet>(GetAbilitySystemComponent()->GetAttributeSet(UMoonBaseAttributeSet::StaticClass())))
	{
		return AttributeSet->GetHealth();
	}

	return 0.0f;
}

float AMoonPlayerState::GetMaxHealth() const
{
	if (const auto AttributeSet = Cast<UMoonBaseAttributeSet>(GetAbilitySystemComponent()->GetAttributeSet(UMoonBaseAttributeSet::StaticClass())))
	{
		return AttributeSet->GetMaxHealth();
	}

	return 0.0f;
}

float AMoonPlayerState::GetSpeed() const
{
	if (const auto AttributeSet = Cast<UMoonBaseAttributeSet>(GetAbilitySystemComponent()->GetAttributeSet(UMoonBaseAttributeSet::StaticClass())))
	{
		return AttributeSet->GetSpeed();
	}

	return 0.0f;
}

float AMoonPlayerState::GetMaxSpeed() const
{
	if (const auto AttributeSet = Cast<UMoonBaseAttributeSet>(GetAbilitySystemComponent()->GetAttributeSet(UMoonBaseAttributeSet::StaticClass())))
	{
		return AttributeSet->GetMaxSpeed();
	}

	return 0.0f;
}

void AMoonPlayerState::OnHealthChanged(const FOnAttributeChangeData& InData)
{
	auto Player = Cast<AMoonCharacter>(GetPawn());

	if (IsValid(Player) && !IsAlive())
	{
		GetAbilitySystemComponent()->CancelAllAbilities();

		if (auto MoonGameMode = Cast<AMoonAttacksGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			MoonGameMode->PlayerDied();
		}
	}
}
