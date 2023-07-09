// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpawnMesh = CreateDefaultSubobject<UStaticMeshComponent>("SpawnMesh");
	SpawnBox = CreateDefaultSubobject<UBoxComponent>("Spawn Box");
	SetRootComponent(SpawnBox);
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Time += DeltaTime;

	if (Time >= 2.5)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.bNoFail = true;
		FTransform TubeSpawnTransform;
		TubeSpawnTransform.SetLocation(GetActorLocation());
		TubeSpawnTransform.SetScale3D(FVector(1.f));
		GetWorld()->SpawnActor<AObstacle>(TubeClass, TubeSpawnTransform, SpawnParams);
		Time = 1.f;
	}
}

