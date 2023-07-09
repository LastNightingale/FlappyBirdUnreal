// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FlappyBirdGameMode.generated.h"

/**
 * 
 */
UCLASS()
class NEWFLAPPY_API AFlappyBirdGameMode : public AGameMode
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
public:
	AFlappyBirdGameMode();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Counter", Meta = (BlueprintProtected = true))
	TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};
