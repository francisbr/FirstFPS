// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstFPS.h"
#include "FirstFPSCharacter.h"
#include "Bullet.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	RootComponent = RootComp;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	Velocity = GetActorRotation().Vector() * 150;
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult HitResult;

	
	FVector StartTrace = this->GetActorLocation();
	FVector EndTrace = (Velocity * DeltaTime) + StartTrace;
	EndTrace.Z += this->GetActorRotation().Pitch;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Pawn, CollisionParams)) {
		//HIT
		if (HitResult.GetActor()) {
			//hit actor

			AFirstFPSCharacter* PlayerHit = Cast<AFirstFPSCharacter>( HitResult.GetActor() );
			if (PlayerHit) {
				//UGameplayStatics::ApplyDamage(HitResult.GetActor(), 25, );
				UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *PlayerHit->GetName());
				DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 2.f, 10, FColor::Red, false, .5f);

				PlayerHit->MyTakeDamage(25);

			} else {
				DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 7.f, 10, FColor::Red, false, 120.f);
			}
		}
		Destroy();

	} else {
		//NO HIT
		BulletExpiry += DeltaTime;

		//DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, .1f);
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, true);

		SetActorLocation(EndTrace);

		//Velocity += FVector(0.f, 0.f, -200.f) * DeltaTime;

		if (BulletExpiry > 3) {
			Destroy();
		}
	}
}

