// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	
	auto ControlledTank = GetControlledTank();
	
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing Tank: %s\n"), *ControlledTank->GetName());
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Tank not possessed by PlayerController!\n"));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play\n"));
}


ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
