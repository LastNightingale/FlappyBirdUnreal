// Fill out your copyright notice in the Description page of Project Settings.


#include "Bird.h"
#include "Obstacle.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"


class AObstacle;


//class Obstacle;

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	BirdMesh = CreateDefaultSubobject<UStaticMeshComponent>("BirdMesh");
}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();
	
	/*BirdMesh->OnComponentHit.AddDynamic(this, &ABird::HitMesh);*/
	BirdMesh->OnComponentBeginOverlap.AddDynamic(this, &ABird::OnKillZoneEnter);
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bIsJumping)
	{
		Fall(DeltaTime);		
	}
}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction(TEXT("Fly"), IE_Pressed, this, &ABird::Jump);
	InputComponent->BindAction(TEXT("Pause"), IE_Pressed, this, &ABird::Pause);
}

void ABird::AddPoint()
{
	Points++;
}

int ABird::GetPoints()
{
	return Points;
}

void ABird::Fall(float DeltaTime)
{
	//MovementDirection.Z += -150.f;
	CurrentVelocity -= FallAcceleration;

	// Оновити позицію пташки на основі поточної вертикальної швидкості
	FVector NewLocation = GetActorLocation() + FVector(0.f, 0.f, CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);
}

void ABird::Jump()
{	
	//bIsJumping = false;

	CurrentVelocity = JumpForce;

	bIsJumping = true;

}

void ABird::Pause()
{
	ABird* PlayerBird = Cast<ABird>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (PauseHUDClass != nullptr)
	{
		PauseWidget	= CreateWidget<UUserWidget>(GetWorld(), PauseHUDClass);

		if (PauseWidget != nullptr)
		{
			PauseWidget->AddToViewport();
			APlayerController* BirdPlayer = UGameplayStatics::GetPlayerController(this, 0);
			UGameplayStatics::SetGamePaused(this, true);
			BirdPlayer->SetShowMouseCursor(true);
			//UWidgetBlueprintLibrary::SetInputMode_GameOnly(BirdPlayer);
			UWidgetBlueprintLibrary::SetInputMode_UIOnly(BirdPlayer, PauseWidget);
		}
	}
}

void ABird::OnKillZoneEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	//UE_LOG(LogTemp, Warning, TEXT("Overlapped Obstacle"));
	if (AObstacle* Obstacle = Cast<AObstacle>(OtherActor))
	{
		if (UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(OtherComp))
		{
			//Destroy();
			UGameplayStatics::OpenLevel(GetWorld(), *GetWorld()->GetName(), false);
		}
		else
		{
			AddPoint();
		}			
	}
	else
	{
		UGameplayStatics::OpenLevel(GetWorld(), *GetWorld()->GetName(), false);
	}
		
}

//void ABird::HitMesh(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Hit Obstacle"));
//	Destroy();
//}



