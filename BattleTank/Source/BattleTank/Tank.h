// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent* TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent* BarrelFromBP);

private:
	// Rotate turret at speed, -ve values for CCW
	void RotateTurret(float Speed);

	// Rotate Barrel at speed, -ve values
	void RotateBarrel(float Speed);

	// A reference from Turret in Blueprint
	UChildActorComponent* Turret = nullptr;
	
	// A reference from Barrel in Blueprint
	UChildActorComponent* Barrel = nullptr;
	

};
