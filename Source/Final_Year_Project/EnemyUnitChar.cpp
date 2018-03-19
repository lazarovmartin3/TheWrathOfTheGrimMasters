// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyUnitChar.h"


// Sets default values
AEnemyUnitChar::AEnemyUnitChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyUnitChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyUnitChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyUnitChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int AEnemyUnitChar::GetLevel()
{
	return Level;
}

void AEnemyUnitChar::Level_Up()
{

	if (Level < 10)
		Level++;

}


float AEnemyUnitChar::GetDamage()
{
	return Damage;
}

float AEnemyUnitChar::GetHealth()
{
	return Health;
}

void AEnemyUnitChar::TakeHealth(float Damage)
{
	Health -= Damage;
}

