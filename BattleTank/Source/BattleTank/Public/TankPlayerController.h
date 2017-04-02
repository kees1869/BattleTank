// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
private:
ATank* GetControlledTank() const;

void BeginPlay() override;

// Called every frame
virtual void Tick(float DeltaTime) override;

// start the tank moving the barrel, so that a shot would hit where the crosshair intersects the world
void AimTowardsCrosshair();

bool GetSightRayHitLocation(FVector& HitLocation) const;

UPROPERTY(EditAnywhere)
float CrosshairXLocation = .5f;
UPROPERTY(EditAnywhere)
float CrosshairYLocation = .33333f;

FVector2D ScreenLocation;
};
