// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTwordsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Ticking"));
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not posessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player possessing: %s"), *ControlledTank->GetName());
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Beginplay"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTwordsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter

	//UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}

	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(0.1);
	FHitResult Hit;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FVector RayEnd;
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;


	GetControlledTank()->GetController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);

	GetControlledTank()->ActorLineTraceSingle(Hit, PlayerViewPointLocation, RayEnd, ECollisionChannel::ECC_PhysicsBody, TraceParameters);
	
	HitLocation = PlayerViewPointLocation;
	

	return false;
}