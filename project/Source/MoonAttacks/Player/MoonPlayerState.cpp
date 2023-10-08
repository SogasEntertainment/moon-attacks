#include "MoonPlayerState.h"
#include "MoonAttacks/Abilities/AttributeSets/MoonBaseAttributeSet.h"

AMoonPlayerState::AMoonPlayerState()
{
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
