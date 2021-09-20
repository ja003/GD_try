// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AMazeGameModeBase::Restart()
{
	UGameplayStatics::OpenLevel(GetWorld(), "L_Maze");
}
