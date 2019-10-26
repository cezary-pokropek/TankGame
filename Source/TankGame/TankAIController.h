// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

protected: 

	//How close can AI get to the Player
	UPROPERTY(EditDefaultsOnly , Category = "Setup")
	float AcceptanceRadius = 8000;

private:

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossesedTankDeath();

};
