// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed, float Direction)
{

	//	auto tTime = GetWorld()->GetTimeSeconds();
	//	UE_LOG(LogTemp, Warning, TEXT("%f: BarrelElevateCalled at speed %.f"), tTime, RelativeSpeed);

//	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

//	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;

//	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
//	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
//	SetRelativeRotation(FRotator(Elevation, 0, 0));
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
	UE_LOG(LogTemp, Warning, TEXT("Rotate fired, Speed: %f"), RelativeSpeed);
}

