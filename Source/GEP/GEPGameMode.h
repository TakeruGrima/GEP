// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnderlookCharacter.h"
#include "GEPGameMode.generated.h"

UCLASS(minimalapi)
class AGEPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGEPGameMode();
protected:
	UFUNCTION(BlueprintImplementableEvent)
		void OnCharacterKilled(AUnderlookCharacter* killedCharacter, AActor* killedBy);

	UFUNCTION(BlueprintImplementableEvent)
		void OnGameStart();

	UFUNCTION(BlueprintImplementableEvent)
		void OnGameEnd(int winningTeamID);

	UFUNCTION(BlueprintImplementableEvent)
		void OnObjectiveComplete(int teamID, AUnderlookCharacter* completedBy);
public:
	//called from level blueprint when placed assets have been assigned. i.e spawners or pre-placed enemies.
	UFUNCTION(BlueprintCallable)
		void LevelSetupComplete();

	UFUNCTION(BlueprintCallable)
		void CharacterKilled(class AUnderlookCharacter* killedCharacter, AActor* killedBy);

	UFUNCTION(BlueprintCallable)
		void GameOver(int winningTeamID);

	UFUNCTION(BlueprintCallable)
		void ObjectiveComplete(int teamID, AUnderlookCharacter* completedBy);
};



