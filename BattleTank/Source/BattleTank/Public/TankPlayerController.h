// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float) override;

	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	void AimTwordsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;
};
