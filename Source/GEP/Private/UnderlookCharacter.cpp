// Fill out your copyright notice in the Description page of Project Settings.

#include "UnderlookCharacter.h"


// Sets default values
AUnderlookCharacter::AUnderlookCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnderlookCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUnderlookCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUnderlookCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AUnderlookCharacter::StartRespawnTimer(float timeToRespawn)
{
}

