// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FloorActor.h"
#include "BallActor.h"
#include "MazePawn.h"


#include "MazeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GD_TRY_API AMazeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AFloorActor* Floor;
	AGoalActor* Goal;
	ABallActor* Ball;
	AMazePawn* MazePawn;

	void OnGoalHit();

	void Try();

};
