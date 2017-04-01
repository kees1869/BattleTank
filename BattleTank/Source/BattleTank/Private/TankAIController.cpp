// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();

	if (AIControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing Tank: %s\n"), *AIControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank not possessed by AI Controller!\n"));
	}
}

ATank* ATankAIController::GetAIControlledTank() const {
	return Cast<ATank>(GetPawn());
}
