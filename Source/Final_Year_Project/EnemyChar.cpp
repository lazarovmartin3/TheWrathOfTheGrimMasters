// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyChar.h"


// Sets default values
AEnemyChar::AEnemyChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int AEnemyChar::GetLevel()
{
	return Level;
}

float AEnemyChar::GetDamage()
{
	return Damage;
}

float AEnemyChar::GetHealth()
{
	return Health;
}

void AEnemyChar::TakeHealth(float Damage)
{
	Health -= Damage;
}

void AEnemyChar::AddExperience(int Exp)
{

	Experience += Exp;

}

