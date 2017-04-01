// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();
	
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing Tank: %s\n"), *ControlledTank->GetName());
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Tank not possessed by Player Controller!\n"));
	}

	//UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play\n"));
}


ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
