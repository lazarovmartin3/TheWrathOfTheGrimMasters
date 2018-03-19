// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyFirstCPPActor.h"
#include "Final_Year_ProjectGameMode.generated.h"

UCLASS(minimalapi)
class AFinal_Year_ProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

	
public:
	AFinal_Year_ProjectGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY()
		class UUserWidget* CurrentWidget;

private:
	UPROPERTY()
		AMyFirstCPPActor* SpawnedActor;
	UFUNCTION()
		void DestroyActorFunction();

};



