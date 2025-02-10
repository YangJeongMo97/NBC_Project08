// Copyright Epic Games, Inc. All Rights Reserved.

#include "NBC_Project08GameMode.h"
#include "NBC_Project08Character.h"
#include "UObject/ConstructorHelpers.h"

ANBC_Project08GameMode::ANBC_Project08GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
