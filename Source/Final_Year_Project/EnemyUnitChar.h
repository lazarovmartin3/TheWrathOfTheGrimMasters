// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyUnitChar.generated.h"

UCLASS()
class FINAL_YEAR_PROJECT_API AEnemyUnitChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyUnitChar();

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

	/**Accessor function for Level */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void Level_Up();

	/**Accessor function for Damage */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetDamage();

	/**Accessor function for Health */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetHealth();

	/**Accessor function for Taking Damage */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void TakeHealth(float Damage);

private:


	//Enemy Unit Health
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float Health = 100;

	//Enemy Unit Initial stamina
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float InitialStamina;

	//Enemy Unit current stamina
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float CurrentStamina;

	//Enemy Unit level
	UPROPERTY(EditAnywhere, Category = "Attributes")
		int Level = 1;

	//Enemy Unit damage
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float Damage = 10;
	
	
};
