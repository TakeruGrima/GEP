// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnderlookCharacter.h"
#include "NPCBaseClass.generated.h"

UENUM()
enum eAINavstate
{
	IDLE UMETA(DisplayName = "Idle"),
	PATROL UMETA(DisplayName = "Patrol"),
	CHASE UMETA(DisplayName = "Chase")
};

UCLASS()
class GEP_API ANPCBaseClass : public AUnderlookCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCBaseClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum) 
		TEnumAsByte<eAINavstate> NavState;

	UFUNCTION(BlueprintImplementableEvent, Category = "Navigation")
		void Patroling();

	UFUNCTION(BlueprintImplementableEvent, Category = "Navigation")
		void Chasing();
	
};
