// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "GameFramework/GameState.h"
#include "My_CPP_GameState.generated.h"


/**
 * 
 */
UCLASS()
class FINAL_YEAR_PROJECT_API AMy_CPP_GameState : public AGameState
{
	GENERATED_BODY()

public:
		AMy_CPP_GameState();

		UFUNCTION()
			void SetScore(uint32 NewScore);

		UFUNCTION()
			uint32 GetScore();
private:
	UPROPERTY()
		uint32 CurrentScore;
	
};
