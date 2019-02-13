// Fill out your copyright notice in the Description page of Project Settings.

#include "TankIAController.h"

void ATankIAController::BeginPlay()
{
	Super::BeginPlay();
	auto PossessedTank = GetPossessedAITank();
	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AICotnroller not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s"), *(PossessedTank->GetName()));
	}
}

ATank* ATankIAController::GetPossessedAITank() const
{
	return Cast<ATank>(GetPawn());
}