// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Obstacle.generated.h"

UCLASS()
class NEWFLAPPY_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	UPROPERTY(EditAnywhere, Category = "Visual")
	UStaticMesh* ObstacleMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* BotMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* TopMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	UBoxComponent* PointBox;


	UPROPERTY(EditAnywhere, Category = "Gameplay")
	float TubeHeight = 800;

	UPROPERTY(EditAnywhere, Category = "Gameplay")
	float Tear = 300;

	float TearOffset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
