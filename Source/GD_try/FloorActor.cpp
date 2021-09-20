// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorActor.h"
#include <GD_try/MazeGameModeBase.h>
#include "Kismet/GameplayStatics.h"


// Sets default values
AFloorActor::AFloorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AFloorActor::RotateRight(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("RotateRight %f"), Value);
	FRotator NewRotation = FRotator(Value, 0, 0);
	FQuat QuatRotation = FQuat(NewRotation);

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

// Called when the game starts or when spawned
void AFloorActor::BeginPlay()
{
	Super::BeginPlay();

	AMazeGameModeBase* mazeGameMode = Cast<AMazeGameModeBase>(GetWorld()->GetAuthGameMode());
	if (mazeGameMode == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid game mode"));
		return;
	}
	mazeGameMode->Floor = this;

}

// Called every frame
void AFloorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

