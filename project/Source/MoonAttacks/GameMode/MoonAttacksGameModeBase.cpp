#include "MoonAttacksGameModeBase.h"
#include "Kismet/KismetSystemLibrary.h"

void AMoonAttacksGameModeBase::PlayerDied()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}
