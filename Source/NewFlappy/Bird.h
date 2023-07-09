// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/UserWidget.h"
#include "Bird.generated.h"


UCLASS()
class NEWFLAPPY_API ABird : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABird();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(/*BlueprintPure, Category = "Counter"*/)
	void AddPoint();

	UFUNCTION(BlueprintPure, Category = "Counter")
	int GetPoints();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Counter", Meta = (BlueprintProtected = true))
		TSubclassOf<class UUserWidget> PauseHUDClass;

	UPROPERTY()
		class UUserWidget* PauseWidget;

private:
	FVector MovementDirection;
	/*UPROPERTY(EditAnywhere, Category = "Movement")
		float MovementSpeed = 5000.f;*/

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* BirdMesh;

	int Points = 0;


	void Fall(float DeltaTime);
	void Jump();
	void Pause();

	UFUNCTION()
		void OnKillZoneEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpForce = 250.f;         // Сила скачка пташки

	UPROPERTY(EditAnywhere, Category = "Movement")
	float FallAcceleration = 9;  // Прискорення падіння пташки

	UPROPERTY(EditAnywhere, Category = "Movement")
	float CurrentVelocity = 1000.f;   // Поточна вертикальна швидкість пташки

	bool bIsJumping = false;

	//UFUNCTION()
	//	void HitMesh(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
