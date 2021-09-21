// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MazePawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, float, Score);

UCLASS()
class GD_TRY_API AMazePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMazePawn();

	UPROPERTY(BlueprintAssignable, Category = "Test")
	FOnScoreChanged OnScoreChanged;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void RotateFloorPitch(float Value);

	void RotateFloorRoll(float Value);

	class AMazePlayerState* playerState;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnGoalHit();
};
