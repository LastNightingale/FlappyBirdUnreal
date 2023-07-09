// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObstacleMesh = CreateDefaultSubobject<UStaticMesh>("Obstacle Mesh");
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	TopMesh = CreateDefaultSubobject<UStaticMeshComponent>("Top Mesh");
	BotMesh = CreateDefaultSubobject<UStaticMeshComponent>("Bot Mesh");

	PointBox = CreateDefaultSubobject<UBoxComponent>("Point Box");

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	FBox AllTube = ObstacleMesh->GetBoundingBox();
	FVector TubeVector = AllTube.Max - AllTube.Min;

	/*FBox LowTube = BotTube->GetBoundingBox();
	FVector LowVector = LowTube.Max - LowTube.Min;*/

	TearOffset = FMath::RandRange(TubeVector.Z, TubeHeight - TubeVector.Z - Tear);

	TopMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BotMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	PointBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	float BotPartScale = TearOffset / TubeVector.Z;
	float TopPartScale = (TubeHeight - Tear - TearOffset) / TubeVector.Z;

	BotMesh->SetRelativeScale3D({ 1.f, 1.f, BotPartScale });
	BotMesh->SetRelativeLocation({ 0.f, 0.f, BotPartScale * TubeVector.Z / 2.f });
	BotMesh->SetStaticMesh(ObstacleMesh);



	TopMesh->SetRelativeScale3D({ 1.f, 1.f, TopPartScale });
	TopMesh->SetRelativeLocation({ 0.f, 0.f, (TearOffset + Tear + TubeVector.Z + TopPartScale * TubeVector.Z / 2.f) });
	TopMesh->SetStaticMesh(ObstacleMesh);

	PointBox->SetRelativeScale3D({ 1.f, 1.f, Tear });
	PointBox->SetRelativeLocation({ 0.f, 0.f, BotPartScale * TubeVector.Z / 2.f  + Tear});
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector location = GetActorLocation();
	location.Y += 500.f * DeltaTime;
	SetActorLocation(location);
}

