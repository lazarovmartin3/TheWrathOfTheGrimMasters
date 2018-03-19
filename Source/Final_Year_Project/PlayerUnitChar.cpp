// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerUnitChar.h"


// Sets default values
APlayerUnitChar::APlayerUnitChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerUnitChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerUnitChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerUnitChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int APlayerUnitChar::GetLevel()
{
	return Level;
}

float APlayerUnitChar::GetDamage()
{
	return Damage;
}

float APlayerUnitChar::GetCurrentHealth()
{
	return Health;
}

void APlayerUnitChar::TakeHealth(float Damage)
{
	Health -= Damage;
}

