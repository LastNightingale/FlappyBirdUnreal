// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.h"
#include "Components/BoxComponent.h"
#include "Spawner.generated.h"

UCLASS()
class NEWFLAPPY_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	/*UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* SpawnMesh;*/

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* SpawnBox;

	UPROPERTY(EditAnywhere, Category = "Shooting")
	TSubclassOf<class AObstacle> TubeClass;

	float Time = 1.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
