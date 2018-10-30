// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GEPProjectile.h"

bool AProjectileWeapon::FireWeapon()
{
	if (mCanFire)
	{
		if (UseAmmo && Ammo <= 0) return false;

		if (ProjectileClass != NULL)
		{
			UWorld* const World = GetWorld();
			if (World != NULL)
			{
				const FRotator SpawnRotation = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((MuzzleLocation != nullptr) ? MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AGEPProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

				if (UseAmmo)
					Ammo -= 1;

				// try and play the sound if specified
				if (FireSound != NULL)
				{
					UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
				}

				return true;
			}
		}
	}

	return false;
}


