// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Ess_EnemyAI.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_YEAR_PROJECT_API AAI_Ess_EnemyAI : public AAIController
{
	GENERATED_BODY()
	
		UPROPERTY(transient)
		class UBlackboardComponent* BlackboardComp;

	UPROPERTY(transient)
		class UBehaviorTreeComponent* BehaviorComp;
public:

	virtual void Possess(APawn* InPawn) override;
	
	AAI_Ess_EnemyAI();

	uint8 enemyKeyID;
	
};
