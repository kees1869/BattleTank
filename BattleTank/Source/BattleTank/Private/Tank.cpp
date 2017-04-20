// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"


// Sets default values

void ATank::BeginPlay()
{
	Super::BeginPlay(); // needed for BP BeginPlay to run!

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ BeginPlay()"), *TankName)
}

ATank::ATank()
{
 	// set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ Construct"), *TankName)
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankMovementComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool IsReloaded = FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds;
	if (Barrel && IsReloaded) {

		// spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
