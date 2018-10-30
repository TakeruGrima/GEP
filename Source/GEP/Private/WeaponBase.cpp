// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GEPProjectile.h"
#include "DrawDebugHelpers.h" 
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AWeaponBase::AWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	MeshComp->bCastDynamicShadow = false;
	MeshComp->CastShadow = false;
	RootComponent = MeshComp;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	MuzzleLocation->SetupAttachment(MeshComp);
	MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	Ammo = MaxAmmo;
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!mCanFire)
	{
		mTimeSinceLastFire += DeltaTime;

		if (mTimeSinceLastFire > (1 / Rate))
		{
			mCanFire = true;
			mTimeSinceLastFire = 0;

			if ((IsAutomatic && mFiringAutomatic))
				FireWeapon();
		}
	}
}

bool AWeaponBase::FireWeapon()
{
	if (UseAmmo && Ammo <= 0) return false;

	if (mCanFire)
	{
		//get the "owner" of the weapon, i.e the character holding it
		AActor* MyOwner = GetOwner();

		if (MyOwner)
		{
			//set the eye location and rotation by accessing the characters "Eyes view point" 
			//in 1st person this is the center of the viewport
			FVector EyeLocation;
			FRotator EyeRotation;
			MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

			//set a vector of huge length(or as far as you want bullets to hit) from the eye location outwards
			FVector TraceEnd = EyeLocation + (EyeRotation.Vector() * 10000);

			//get the position of the muzzle of the gun
			FVector MuzzlePos = MuzzleLocation->GetComponentLocation();

			//set up params to ignore the character and the weapon
			FCollisionQueryParams QueryParams;
			QueryParams.AddIgnoredActor(MyOwner);
			QueryParams.AddIgnoredActor(this);
			QueryParams.bTraceComplex = true;

			//create a hit structure to store data about the trace
			FHitResult hit;
			//trace from the eye location to the trace end
			if (GetWorld()->LineTraceSingleByChannel(hit, EyeLocation, TraceEnd, ECC_Visibility, QueryParams))
			{
				//draw a red line if it hits anything
				//DrawDebugLine(GetWorld(), MuzzlePos, TraceEnd, FColor::Red, false, 1.0f, 0, 1.0f);
				//Get the hit actor from hit
				AActor* hitActor = hit.GetActor();
				//hitActor->Destroy();

				// try and play the sound if specified
				if (FireSound != NULL)
				{
					UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
				}

				if (BloodSplatterEffect && hitActor != NULL)
				{
					//Spawn the particle effect at the muzzle socket and store it in a variable
					UParticleSystemComponent* BloodSplatterComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BloodSplatterEffect, hit.ImpactPoint);
				}
			}
			else
			{
				//draw a white line if it does not hit anything
				//DrawDebugLine(GetWorld(), MuzzlePos, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
			}

			if (BeamEffect)
			{
				//Spawn the particle effect at the muzzle socket and store it in a variable
				UParticleSystemComponent* BeamComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BeamEffect, MeshComp->GetSocketLocation("Muzzle"));

				//Set the vector parameter "BeamEnd" 
				//If the hit returns an actor set it to the impact point else set it to TraceEnd
				BeamComp->SetVectorParameter("BeamEnd", (hit.Actor != NULL) ? hit.ImpactPoint : TraceEnd);
			}

			if (FlashEffect)
			{
				//Spawn the particle effect at the muzzle socket and store it in a variable
				UParticleSystemComponent* FlashComp = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), FlashEffect, MeshComp->GetSocketLocation("Muzzle"));
			}

			GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(FireCamShake);

			mCanFire = false;

			if (UseAmmo)
				Ammo--;

			if (IsAutomatic && !mFiringAutomatic)
				mFiringAutomatic = true;

			return true;
		}
	}

	return false;
}

void AWeaponBase::StopFiring()
{
	mFiringAutomatic = false;
}

void AWeaponBase::OnReload()
{
	Ammo = MaxAmmo;
}

