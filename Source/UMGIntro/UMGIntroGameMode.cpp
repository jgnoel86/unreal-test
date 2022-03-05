// Copyright Epic Games, Inc. All Rights Reserved.

#include "UMGIntroGameMode.h"
#include "UMGIntroCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUMGIntroGameMode::AUMGIntroGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
