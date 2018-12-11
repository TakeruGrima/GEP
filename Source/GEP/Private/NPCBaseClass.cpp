// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCBaseClass.h"
#include "UnderlookCharacter.h"


// Sets default values
ANPCBaseClass::ANPCBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCBaseClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (NavState)
	{
	case PATROL:
		Patroling();
		break;
	case CHASE:
		Chasing();
		break;
	default:
		break;
	}
}

// Called to bind functionality to input
void ANPCBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

