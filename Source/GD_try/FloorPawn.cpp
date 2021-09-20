// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorPawn.h"

// Sets default values
AFloorPawn::AFloorPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloorPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFloorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("RotateRight", this, &AFloorPawn::RotateRight);

}

void AFloorPawn::RotateRight(float Value) 
{
	UE_LOG(LogTemp, Warning, TEXT("RotateRight %f"), Value);

	//FRotator CurrentRotation = GetActorRotation();
	//// on every frame change rotating for a smooth rotating actor
	//FRotator NewRotation = FRotator(CurrentRotation.Pitch + Value, CurrentRotation.Yaw, CurrentRotation.Roll);
	FRotator NewRotation = FRotator(Value, 0, 0);

	FQuat QuatRotation = FQuat(NewRotation);

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}


