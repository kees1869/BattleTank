// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed and +1 is max up movement
	void MoveTo(float Pitch);
	
private:
	UPROPERTY(EditAnyWhere, Category = Setup)
	float MaxDegreesPerSecond = 20.f;

	UPROPERTY(EditAnyWhere, Category = Setup)
	float MinDegreesOfElevation = 0.f;

	UPROPERTY(EditAnyWhere, Category = Setup)
	float MaxDegreesOfElevation = 40.f;
};
