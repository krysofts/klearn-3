// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void Tick(float) override;

	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	void AimTwordsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0;

	bool GetLookVectorHitLocation(FVector, FVector&) const;
	bool GetLookDirection(FVector2D, FVector&) const;
};
