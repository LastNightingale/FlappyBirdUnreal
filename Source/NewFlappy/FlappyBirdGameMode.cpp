// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBirdGameMode.h"
#include "Bird.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

void AFlappyBirdGameMode::BeginPlay()
{
	Super::BeginPlay();

	/*ABird* PlayerBird = Cast<ABird>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (PlayerHUDClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}*/
}


AFlappyBirdGameMode::AFlappyBirdGameMode() : Super()
{
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT(""))
	DefaultPawnClass = ABird::StaticClass();

	//HUDClass = ABird::
}
