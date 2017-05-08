// Copyright 2016 Rogue Gnome.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
// called by the engine, when actor damage is dealt
// in other words: the projectile causes damage to this object and this member function is called to process that damage
virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;
};
