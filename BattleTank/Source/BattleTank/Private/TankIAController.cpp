// Fill out your copyright notice in the Description page of Project Settings.

#include "TankIAController.h"
#include "Engine/World.h"

void ATankIAController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AICotnroller can't find player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

void ATankIAController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetPlayerAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}

ATank* ATankIAController::GetPlayerAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankIAController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}