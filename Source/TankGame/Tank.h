// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class TANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	// called by the engine when actor damage is dealt
	virtual float TakeDamage ( float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser ) override;

	ATank();

	// Return current healthas a percentage of starting health, between 0 and 1 
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;


};
