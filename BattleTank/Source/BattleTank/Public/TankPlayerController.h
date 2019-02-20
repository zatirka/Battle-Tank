// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Start a tank moving the barrel so that a shot would
	//it where the crosshair intersects the world
	void AimTowardsCrosshair();
public:
	ATank* GetControlledTank() const;

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere, Category = "ScreenLocation")
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere, Category = "ScreenLocation")
		float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere, Category = "ScreenLocation")
		float LineTraceRange = 1000000; // 10 km
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
