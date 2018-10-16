// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GEPGameMode.h"
#include "GEPHUD.h"
#include "GEPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGEPGameMode::AGEPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/Blinker"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGEPHUD::StaticClass();
}
