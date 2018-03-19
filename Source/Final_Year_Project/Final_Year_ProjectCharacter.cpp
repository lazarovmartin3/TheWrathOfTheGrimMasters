// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Final_Year_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"

AFinal_Year_ProjectCharacter::AFinal_Year_ProjectCharacter()
{

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AFinal_Year_ProjectCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (CursorToWorld != nullptr)
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UWorld* World = GetWorld())
			{
				FHitResult HitResult;
				FCollisionQueryParams Params;
				FVector StartLocation = TopDownCameraComponent->GetComponentLocation();
				FVector EndLocation = TopDownCameraComponent->GetComponentRotation().Vector() * 2000.0f;
				Params.AddIgnoredActor(this);
				World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
				FQuat SurfaceRotation = HitResult.ImpactNormal.ToOrientationRotator().Quaternion();
				CursorToWorld->SetWorldLocationAndRotation(HitResult.Location, SurfaceRotation);
			}
		}
		else if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FHitResult TraceHitResult;
			PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			CursorToWorld->SetWorldLocation(TraceHitResult.Location);
			CursorToWorld->SetWorldRotation(CursorR);
		}
	}

	//Raise the HP and Mana over time
	
	//CurrentMana += ((Level / 10) * 2.5);
	//CurrentExperience++;
	

}

int AFinal_Year_ProjectCharacter::GetExperience()
{
	return CurrentExperience;
}

int AFinal_Year_ProjectCharacter::GetLevel()
{
	return Level;
}

void AFinal_Year_ProjectCharacter::AddExperience()
{
	//Update current Experience
	CurrentExperience += 1;
	//Add Gold as Reward
	Gold += FMath::RandRange((int32) 0, (int32)Level * 10);

	//Levels
	if (CurrentExperience >= MaxExperience)
	{
		if (Level <= 90)
		{
			//Level Up
			Level++;
			//Update Max Experience
			MaxExperience *= 2;
			CurrentExperience = 0;
			//Update Health
			MaxHealth = (MaxHealth * 0.3) + MaxHealth;
			CurrentHealth = MaxHealth;
		}
		
	}
	

}

float AFinal_Year_ProjectCharacter::GetCurrentExperience()
{
	return CurrentExperience;
}

float AFinal_Year_ProjectCharacter::GetMaxExperience()
{
	return MaxExperience;
}

float AFinal_Year_ProjectCharacter::GetCurrentHealth()
{
	return CurrentHealth;
}

float AFinal_Year_ProjectCharacter::GetMaxHealth()
{
	return MaxHealth;
}

void AFinal_Year_ProjectCharacter::RaiseHealth(float DeltaSeconds)
{
	//CurrentHealth += ((Level / 10) * 2);
	if (CurrentHealth < MaxHealth)
	{
		float pace = (float)Level / 10;
		CurrentHealth += (pace * 2) * DeltaSeconds;
	}

}

float AFinal_Year_ProjectCharacter::GetCurrentMana()
{
	return CurrentMana;
}

float AFinal_Year_ProjectCharacter::GetMaxMana()
{
	return MaxMana;
}

void AFinal_Year_ProjectCharacter::RaiseMana(float DeltaSeconds)
{
	if (CurrentMana < MaxMana)
	{
		float pace = (float)Level / 10;
		CurrentMana += (pace * 2.5) * DeltaSeconds;
	}
}

void AFinal_Year_ProjectCharacter::TakeMana(float mana)
{
	CurrentMana -= mana;
}

void AFinal_Year_ProjectCharacter::TakeHealth(float Damage)
{

	//Defense
	Damage = Damage - (Damage * (Defense / 100));
	//Take HP
	CurrentHealth -= Damage;

	if (CurrentHealth <= 0)
	{
		isHeroDead = true;
		CurrentHealth = 0;
		//GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, 3.9, true);
		//isHeroDead = false;
	}
		

}

bool AFinal_Year_ProjectCharacter::GetIsHeroDead()
{
	return isHeroDead;
}

void AFinal_Year_ProjectCharacter::SetIsHeroLive()
{
	isHeroDead = false;
	CurrentHealth = MaxHealth;
}

int AFinal_Year_ProjectCharacter::GetGold()
{
	return Gold;
}

void AFinal_Year_ProjectCharacter::SetGold(int newGold)
{

	Gold = newGold;

}

void AFinal_Year_ProjectCharacter::CastHealingWave()
{
	

	//Cast only if have mana
	if (CurrentMana >= HealingWaveManaCost && CurrentHealth != MaxHealth)
	{
		ableToCastHealingWave = true;
		//Take mana
		TakeMana(HealingWaveManaCost);

		//Heal
		CurrentHealth += HealingAmount;

		if (CurrentHealth > MaxHealth)
			CurrentHealth = MaxHealth;
	}
	else
		ableToCastHealingWave = false;

}

void AFinal_Year_ProjectCharacter::HealingWaveLevelUp()
{

	if (HealingWaveLevel < 20)
	{
		//Raise the level
		HealingWaveLevel++;
		//Upddate the healing amount
		HealingAmount = HealingAmount + (HealingAmount * 0.3);
		//Update the mana cost
		HealingWaveManaCost = HealingWaveManaCost - (HealingWaveManaCost * 0.1);
	}
		

}

bool AFinal_Year_ProjectCharacter::IsAbleToCastHealingWave()
{
	return ableToCastHealingWave;
}

float AFinal_Year_ProjectCharacter::GetSwordDamage()
{
	return SwordDamage;
}

void AFinal_Year_ProjectCharacter::CastFireball()
{

	if (CurrentMana >= FireballManaCost)
	{
		TakeMana(FireballManaCost);
		ableToCastFireball = true;
	}
	else
	{
		ableToCastFireball = false;
	}

}

void AFinal_Year_ProjectCharacter::FireballLevelUp()
{

	if (FireballLevel < 20)
	{
		//Raise the level
		FireballLevel++;
		//Update the Damage
		FireballDamage = FireballDamage + (FireballDamage * 0.3);
		//Update the mana cost
		FireballManaCost = FireballManaCost - (FireballManaCost * 0.2);
	}
		

}

bool AFinal_Year_ProjectCharacter::IsAbleToCastFireball()
{
	return ableToCastFireball;
}

float AFinal_Year_ProjectCharacter::GetFireballDamage()
{
	return FireballDamage;
}

void AFinal_Year_ProjectCharacter::CastNova()
{

	if (CurrentMana >= NovaManaCost)
	{
		TakeMana(NovaManaCost);
		ableToCastNova = true;
	}
	else
	{
		ableToCastNova = false;
	}


}

void AFinal_Year_ProjectCharacter::NovaLevelUp()
{

	if (NovaLevel < 20)
	{
		//Raise the level
		NovaLevel++;
		//Update the Damage
		NovaDamage = NovaDamage + (NovaDamage * 0.4);
		//Update the mana cost
		NovaManaCost = NovaManaCost - (NovaManaCost * 0.2);
	}

}

bool AFinal_Year_ProjectCharacter::IsAbleToCastNova()
{
	return ableToCastNova;
}

float AFinal_Year_ProjectCharacter::GetNovaDamage()
{
	return NovaDamage;
}
