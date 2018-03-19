// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerUnitChar.generated.h"

UCLASS()
class FINAL_YEAR_PROJECT_API APlayerUnitChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerUnitChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**Accessor function for Level */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		int GetLevel();

	/**Accessor function for Damage */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetDamage();

	/**Accessor function for Health */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetCurrentHealth();

	/**Accessor function for Taking Damage */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void TakeHealth(float Damage);

private:

	//Enemy Health
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float Health = 100;

	//Enemy level
	UPROPERTY(EditAnywhere, Category = "Attributes")
		int Level = 1;

	//Enemy damage
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float Damage = 10;
	
};
