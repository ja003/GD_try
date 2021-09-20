// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AMazeGameModeBase::Restart()
{
	//UGameplayStatics::OpenLevel(GetWorld(), "L_Maze");
	FVector origin;
	FVector extents;
	Floor->GetActorBounds(false, origin, extents);
	const float offset = 10;
	float topLeftX = origin.X - extents.X / 2 + offset;
	float topLeftY = origin.Y - extents.Y / 2 - offset;
	float botRightX = origin.X + extents.X / 2 - offset;
	float botRightY = origin.Y + extents.Y / 2 + offset;

	Goal->SetActorLocation(FVector(FMath::RandRange(topLeftX, botRightX), FMath::RandRange(topLeftY, botRightY), 0));
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMazeGameModeBase::Try, 1, false);
}

void AMazeGameModeBase::Try() {

	UE_LOG(LogTemp, Error, TEXT("Try"));
	Ball->SetActorLocation(FVector(0, 0, 100)); //this doesnt happen!
	Ball->Reset();
	//Ball->SetActorTickEnabled(true);
}
