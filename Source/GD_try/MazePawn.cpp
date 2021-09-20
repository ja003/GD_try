// Fill out your copyright notice in the Description page of Project Settings.


#include "MazePawn.h"
#include <GD_try/MazeGameModeBase.h>
#include "Kismet/GameplayStatics.h"

// Sets default values
AMazePawn::AMazePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMazePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("RotatePitch", this, &AMazePawn::RotateFloorPitch);
	InputComponent->BindAxis("RotateRoll", this, &AMazePawn::RotateFloorRoll);
}

void AMazePawn::RotateFloorPitch(float Value) {

	AMazeGameModeBase* mazeGameMode = Cast<AMazeGameModeBase>(GetWorld()->GetAuthGameMode());
	mazeGameMode->Floor->RotatePitch(Value);
}

void AMazePawn::RotateFloorRoll(float Value) {

	AMazeGameModeBase* mazeGameMode = Cast<AMazeGameModeBase>(GetWorld()->GetAuthGameMode());
	mazeGameMode->Floor->RotateRoll(Value);
}
