// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalActor.h"
#include "Components/BoxComponent.h"

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
}

void AGoalActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == nullptr || OtherActor == this || OtherComponent == nullptr)
		return;
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("hit: %s"), *OtherActor->GetName()));
	UE_LOG(LogTemp, Error, TEXT("It's a collision!"));
}

// Called every frame
void AGoalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

