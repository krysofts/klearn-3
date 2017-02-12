// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AimTwordsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Ticking"));
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/*auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI not posessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possessing: %s"), *GetPlayerTank()->GetName());
	}*/
	//UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *GetPlayerTank()->GetName());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Not Found"));
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}


