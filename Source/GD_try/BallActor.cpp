// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "MazeGameModeBase.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	
	AMazeGameModeBase* mazeGameMode = Cast<AMazeGameModeBase>(GetWorld()->GetAuthGameMode());
	if (mazeGameMode == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid game mode"));
		return;
	}
	mazeGameMode->Ball = this;
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

