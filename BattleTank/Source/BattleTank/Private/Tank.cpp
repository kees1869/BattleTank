// Copyright 2016 Rogue Gnome.

#include "BattleTank.h"
#include "Tank.h"


float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

ATank::ATank()
{
 	// set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;

	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Error, TEXT("TANK DESTROYED!!!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Damage: %i, Health: %i"), DamageToApply, CurrentHealth)
	}
	return DamageToApply;
}
