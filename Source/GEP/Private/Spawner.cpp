// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AActor * ASpawner::SpawnActor(TSubclassOf<AActor> BPToSpawn)
{
	AActor* spawnedActor = GetWorld()->SpawnActor<AActor>(BPToSpawn, GetActorTransform());
	return spawnedActor;
}

