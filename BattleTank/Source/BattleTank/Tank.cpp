// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Components/InputComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret);
	PlayerInputComponent->BindAxis("Rotate_Barrel", this, &ATank::RotateBarrel);
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	Turret->AddRelativeRotation(FRotator(0, Speed, 0));	
}

void ATank::RotateBarrel(float Speed)
{
	if (!Barrel) { return; }
	Barrel->AddRelativeRotation(FRotator(Speed, 0, 0));
}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UChildActorComponent * BarrelFromBP)
{
	Barrel = BarrelFromBP;
}


