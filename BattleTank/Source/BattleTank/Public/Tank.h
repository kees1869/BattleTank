// Copyright 2016 Rogue Gnome.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

/**
*
*/
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	// Sets default values for this pawn's properties
	ATank();
};
