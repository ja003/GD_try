// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FloorPawn.generated.h"

UCLASS()
class GD_TRY_API AFloorPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFloorPawn();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RotateRight(float Value);

	void RotateForward(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
