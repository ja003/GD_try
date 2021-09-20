// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorCharacter.h"

// Sets default values
AFloorCharacter::AFloorCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloorCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFloorCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

