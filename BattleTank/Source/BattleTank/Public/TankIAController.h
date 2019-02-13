// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankIAController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankIAController : public AAIController
{
	GENERATED_BODY()

public:
	ATank*  GetPossessedAITank() const;

	virtual void BeginPlay() override;

};
