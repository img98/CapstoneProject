// Copyright Epic Games, Inc. All Rights Reserved.

#include "CapstoneTPSGameMode.h"
#include "CapstoneTPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACapstoneTPSGameMode::ACapstoneTPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
