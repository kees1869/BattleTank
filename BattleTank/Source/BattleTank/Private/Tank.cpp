// Copyright 2016 Rogue Gnome.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
void ATank::BeginPlay()
{
	Super::BeginPlay(); // needed for BP BeginPlay to run!
}

ATank::ATank()
{
 	// set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}
