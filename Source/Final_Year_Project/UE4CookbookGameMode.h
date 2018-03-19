// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UE4CookbookGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_YEAR_PROJECT_API AUE4CookbookGameMode : public AGameMode
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
