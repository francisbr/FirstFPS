// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstFPS.h"
#include "FirstFPSProjectile.h"
#include "Gun.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::Fire() {
	// try and fire a projectile
		UWorld* const World = GetWorld();
		if (World != NULL) {
			const FVector CameraLocation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraLocation();
			const FVector LookDirection = FirstPersonCameraComponent->GetComponentRotation().Vector();


			FVector StartLocation = CameraLocation + (LookDirection * 100);
			FVector EndLocation = StartLocation + (LookDirection * 10000.f);

			//const FRotator SpawnRotation = GetControlRotation();
			const FRotator SpawnRotation = FirstPersonCameraComponent->GetComponentRotation();

			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = StartLocation;

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			AFirstFPSProjectile* Bullet = World->SpawnActor<AFirstFPSProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

	}

	
	// try and play the sound if specified
	if (FireSound != NULL) {
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL) {
		// Get the animation object for the arms mesh
		if (AnimInstance != NULL) {
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
	
}

