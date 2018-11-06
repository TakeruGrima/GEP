// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class GEP_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USkeletalMeshComponent* MeshComp;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* MuzzleLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool IsAutomatic = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool UseAmmo = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float Rate;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Gameplay)
		TSubclassOf<class UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float Damage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool mFiringAutomatic = false;
	bool mCanFire = true;
	float mTimeSinceLastFire = 0;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	USkeletalMeshComponent* GetWeaponMesh() { return MeshComp; };

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Effects)
		UParticleSystem* BeamEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Effects)
		UParticleSystem* FlashEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Effects)
		UParticleSystem* BloodSplatterEffect;

	UPROPERTY(EditDefaultsOnly, Category = Effects)
		TSubclassOf<class UCameraShake> FireCamShake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float Ammo;

	virtual bool FireWeapon();

	void StopFiring();

	void OnReload();
};
