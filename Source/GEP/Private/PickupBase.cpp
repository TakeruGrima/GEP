// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupBase.h"
#include "Components/SphereComponent.h"


// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupBase::NotifyActorBeginOverlap(AActor * OtherActor)
{
	// on overlap
	OnActivate(OtherActor);
}

