// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnderlookCharacter.generated.h"

UCLASS()
class GEP_API AUnderlookCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	bool mWaitingToRespawn;
	float mRespawnTime;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		int TeamID;
	UPROPERTY(BlueprintReadWrite, Category = Gameplay)
		bool CanRespawn = true; //default to true until you attempt the challenge.
public:
	// Sets default values for this character's properties
	AUnderlookCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		int GetTeamID() {return TeamID;}
	UFUNCTION(BlueprintCallable)
		void SetTeamID(int newTeamID) { TeamID = newTeamID; }
	UFUNCTION(BlueprintCallable)
		void StartRespawnTimer(float timeToRespawn);
};
