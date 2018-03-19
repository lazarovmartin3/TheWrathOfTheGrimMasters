// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Final_Year_ProjectGameMode.h"
#include "Final_Year_ProjectPlayerController.h"
#include "Final_Year_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "My_First_Actor.h"
#include "MyFirstCPPActor.h"
#include "Engine/World.h"
#include "MyHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"



AFinal_Year_ProjectGameMode::AFinal_Year_ProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AFinal_Year_ProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}


	//GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Actor Spawning"));

	//FTransform SpawnLocation;
	////GetWorld()->SpawnActor<AMyFirstCPPActor>(AMyFirstCPPActor::StaticClass(), &SpawnLocation);
	//GetWorld()->SpawnActor<AMyFirstCPPActor>(AMyFirstCPPActor::StaticClass());


}

void AFinal_Year_ProjectGameMode::BeginPlay()
{
	//Impliment destroyer and assign the actor
	/*GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Actor Spawning"));

	SpawnedActor = GetWorld()->SpawnActor<AMyFirstCPPActor>(AMyFirstCPPActor::StaticClass());

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this, &AFinal_Year_ProjectGameMode::DestroyActorFunction, 10);*/
	
	if (PlayerHUDClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}

	}

}

void AFinal_Year_ProjectGameMode::DestroyActorFunction()
{

	if (SpawnedActor != nullptr)
	{
		SpawnedActor->Destroy();
	}

}

