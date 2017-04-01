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

	auto PlayerPawn = GetPlayerTank();

	if (PlayerPawn) {
		UE_LOG(LogTemp, Warning, TEXT("Found Player Controller: %s\n"), *PlayerPawn->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("First Player Controller not found!\n"));
	}
}

ATank* ATankAIController::GetAIControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast <ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
