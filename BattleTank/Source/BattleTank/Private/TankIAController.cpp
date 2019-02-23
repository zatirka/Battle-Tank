// Fill out your copyright notice in the Description page of Project Settings.

#include "TankIAController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankIAController::BeginPlay()
{
	Super::BeginPlay();
}
	
void ATankIAController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO Move towards the player

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); // TODO don't fire every frame
	}
}

