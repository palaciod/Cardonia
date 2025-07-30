// Copyright Epic Games, Inc. All Rights Reserved.

#include "CardoniaGameMode.h"
#include "CardoniaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACardoniaGameMode::ACardoniaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BaseCharacters/BP_Human_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;

	}
}
