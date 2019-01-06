// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class GEP_API APickupBase : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		bool CanRespawn;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
		float EffectDuration;
private:
	bool IsActive;
public:	
	// Sets default values for this actor's properties
	APickupBase();

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = Item)
		class USphereComponent* CollisionComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NotifyActorBeginOverlap(AActor * OtherActor);

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void DeSpawn();
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void ReSpawn();

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
		void OnActivate(AActor* pickedUpBy);
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable, Category = "Pickup")
		void ActivateEffect(AActor* pickedUpBy);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Pickup")
		void DeActivateEffect(AActor* pickedUpBy);
};
