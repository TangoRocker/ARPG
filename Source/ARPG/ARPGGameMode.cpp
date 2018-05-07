// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ARPGGameMode.h"
#include "ARPGPlayerController.h"
#include "ARPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AARPGGameMode::AARPGGameMode()
{

	// use our custom PlayerController class
	PlayerControllerClass = AARPGPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}