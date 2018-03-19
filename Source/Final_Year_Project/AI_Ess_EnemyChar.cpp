// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Ess_EnemyChar.h"


// Sets default values
AAI_Ess_EnemyChar::AAI_Ess_EnemyChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_Ess_EnemyChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Ess_EnemyChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Ess_EnemyChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

