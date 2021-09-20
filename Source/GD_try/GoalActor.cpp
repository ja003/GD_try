// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalActor.h"
#include "Components/BoxComponent.h"
#include <GD_try/BallActor.h>
#include "MazeGameModeBase.h"

// Sets default values
AGoalActor::AGoalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	//BoxComp->SetSimulatePhysics(true);
	BoxComp->SetNotifyRigidBodyCollision(true);
	BoxComp->SetCollisionProfileName("BlockAllDynamic");
	BoxComp->OnComponentHit.AddDynamic(this, &AGoalActor::OnHit);

	RootComponent = BoxComp;
	//BoxComp->SetupAttachment(RootComponent);

	/*body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("body"));
	body->SetupAttachment(RootComponent);*/
}

// Called when the game starts or when spawned
void AGoalActor::BeginPlay()
{
	Super::BeginPlay();

	AMazeGameModeBase* mazeGameMode = Cast<AMazeGameModeBase>(GetWorld()->GetAuthGameMode());
	if (mazeGameMode == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid game mode"));
		return;
	}
	mazeGameMode->Goal = this;
}

void AGoalActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == nullptr || OtherActor == this || OtherComponent == nullptr)
		return;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("hit: %s"), *OtherActor->GetName()));

	if (Cast<ABallActor>(OtherActor)) {
		UE_LOG(LogTemp, Error, TEXT("It's a collision!"));
		AMazeGameModeBase* mazeGameMode = Cast<AMazeGameModeBase>(GetWorld()->GetAuthGameMode());
		mazeGameMode->Restart();
	}
}

// Called every frame
void AGoalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

