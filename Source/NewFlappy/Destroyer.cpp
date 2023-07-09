// Fill out your copyright notice in the Description page of Project Settings.


#include "Destroyer.h"

// Sets default values
ADestroyer::ADestroyer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DestroyerBox = CreateDefaultSubobject<UBoxComponent>("DestroyerBox");
}

// Called when the game starts or when spawned
void ADestroyer::BeginPlay()
{
	Super::BeginPlay();
	
	DestroyerBox->OnComponentBeginOverlap.AddDynamic(this, &ADestroyer::OnKillZoneEnter);
}

// Called every frame
void ADestroyer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestroyer::OnKillZoneEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Obstacle"))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Overlapped Obstacle"));
		OtherActor->Destroy();
	}
		
}

