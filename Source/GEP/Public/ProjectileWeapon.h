// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "ProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GEP_API AProjectileWeapon : public AWeaponBase
{
	GENERATED_BODY()
	
public:

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AGEPProjectile> ProjectileClass;

	bool FireWeapon();		
};
