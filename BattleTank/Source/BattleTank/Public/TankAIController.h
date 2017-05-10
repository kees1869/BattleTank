// Copyright 2016 Rogue Gnome.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:	// the blueprint class is a child of the C++ class, this (protected) ensures the children can read this
	// how close can the AI tank get?
	UPROPERTY(EditDefaultsOnly, Category = "Setup") // consider using EditDefaultsOnly
	float AcceptanceRadius = 8000; // in centimeters, so 8000 is 80 meters

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();
};
