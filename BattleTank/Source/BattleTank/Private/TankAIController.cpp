// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
	// aim towards the player
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank)
	{
		// move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in CM

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// fire when ready
		ControlledTank->Fire(); // TODO limit firing rate
	}
}
