// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Ess_EnemyAI.h"
#include "AI_Ess_EnemyChar.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"



AAI_Ess_EnemyAI::AAI_Ess_EnemyAI()
{

	//BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	//BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

}

void AAI_Ess_EnemyAI::Possess(APawn * InPawn)
{

	Super::OnPossess(InPawn);

	AAI_Ess_EnemyChar* Char = Cast<AAI_Ess_EnemyChar>(InPawn);

	if (Char && Char->BotBehavior)
	{

		BlackboardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		enemyKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorComp->StartTree(*Char->BotBehavior);

	}


}


