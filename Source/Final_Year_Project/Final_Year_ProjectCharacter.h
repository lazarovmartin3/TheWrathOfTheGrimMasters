// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Final_Year_ProjectCharacter.generated.h"


UCLASS()
class AFinal_Year_ProjectCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFinal_Year_ProjectCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	/**Accessor function for Experience */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		int GetExperience();

	/**Accessor function for Experience */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		int GetLevel();

	/**Accessor function for Level */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void AddExperience();

	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetCurrentExperience();

	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetMaxExperience();

	/**Accessor function for Health */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetCurrentHealth();

	/**Accessor function for Health */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetMaxHealth();

	/**Accessor function for Health */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void RaiseHealth(float DeltaSeconds);

	/**Accessor function for Mana */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetCurrentMana();

	/**Accessor function for Mana */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		float GetMaxMana();

	/**Accessor function for Mana */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void RaiseMana(float DeltaSeconds);

	/**Accessor function for Taking Mana */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void TakeMana(float mana);

	/**Accessor function for applying Damage */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void TakeHealth(float Damage);

	UFUNCTION(BlueprintPure, Category = "Attributes")
		bool GetIsHeroDead();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void SetIsHeroLive();

	/**Accessor function for Gold */
	UFUNCTION(BlueprintPure, Category = "Attributes")
		int GetGold();

	/**Accessor function for Gold */
	UFUNCTION(BlueprintCallable, Category = "Attributes")
		void SetGold(int newGold);

	/**Accessor function for Skills */

	UFUNCTION(BlueprintCallable, Category = "Skills") // HEALING WAVE
		void CastHealingWave();

	UFUNCTION(BlueprintCallable, Category = "Skills") // HEALING WAVE
		void HealingWaveLevelUp();

	UFUNCTION(BlueprintPure, Category = "Skills") // HEALING WAVE
		bool IsAbleToCastHealingWave();

	//Sword Damage
	UFUNCTION(BlueprintPure, Category = "Skills")
		float GetSwordDamage();

	//Fireball
	UFUNCTION(BlueprintCallable, Category = "Skills") //Fireball
		void CastFireball();

	UFUNCTION(BlueprintCallable, Category = "Skills") //Fireball
		void FireballLevelUp();

	UFUNCTION(BlueprintPure, Category = "Skills") // Fireball
		bool IsAbleToCastFireball();

	UFUNCTION(BlueprintPure, Category = "Skills") // Fireball
		float GetFireballDamage();

	//Nova
	UFUNCTION(BlueprintCallable, Category = "Skills") //Nova
		void CastNova();

	UFUNCTION(BlueprintCallable, Category = "Skills") //Nova
		void NovaLevelUp();

	UFUNCTION(BlueprintPure, Category = "Skills") // Nova
		bool IsAbleToCastNova();

	UFUNCTION(BlueprintPure, Category = "Skills") // Nova
		float GetNovaDamage();

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	/* Player experience*/
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float CurrentExperience = 0;

	/* Player experience*/
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float MaxExperience = 10;

	/* Player level*/
	UPROPERTY(EditAnywhere, Category = "Attributes")
		int Level = 1;

	//Player Health
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float CurrentHealth = 100;

	//Player Health
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float MaxHealth = 100;
	
	UPROPERTY(EditAnywhere, Category = "Attributes")
		bool isHeroDead = false;

	//Player Gold
	UPROPERTY(EditAnywhere, Category = "Attributes")
		int Gold = 0;

	//Player Mana
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float MaxMana = 100;

	UPROPERTY(EditAnywhere, Category = "Attributes")
		float CurrentMana = 100;

	/* Defense point */
	UPROPERTY(EditAnywhere, Category = "Attributes")
		float Defense = 20;

	
	//Skills

	/* Healing Wave Spell */
	UPROPERTY(EditAnywhere, Category = "Skills")
		int HealingWaveLevel = 0;

	UPROPERTY(EditAnywhere, Category = "Skills")
		float HealingWaveManaCost = 40;

	UPROPERTY(EditAnywhere, Category = "Skills")
		float HealingAmount = 15;

	UPROPERTY(EditAnywhere, Category = "Skills")
		bool ableToCastHealingWave = false;

	/* Sword Attack */
	UPROPERTY(EditAnywhere, Category = "Skills")
		float SwordDamage = 3;

	/* Fireball */

	UPROPERTY(EditAnywhere, Category = "Skills")
		int FireballLevel = 0;

	UPROPERTY(EditAnywhere, Category = "Skills")
		float FireballManaCost = 30;

	UPROPERTY(EditAnywhere, Category = "Skills")
		float FireballDamage = 15;

	UPROPERTY(EditAnywhere, Category = "Skills")
		bool ableToCastFireball = true;

	/* NOVA */

	UPROPERTY(EditAnywhere, Category = "Skills")
		int NovaLevel = 0;

	UPROPERTY(EditAnywhere, Category = "Skills")
		float NovaManaCost = 40;

	UPROPERTY(EditAnywhere, Category = "Skills")
		float NovaDamage = 50;

	UPROPERTY(EditAnywhere, Category = "Skills")
		bool ableToCastNova = true;

};

