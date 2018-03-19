// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "myBarrack.generated.h"

UCLASS()
class FINAL_YEAR_PROJECT_API AmyBarrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmyBarrack();

	UPROPERTY()
		UStaticMeshComponent* BuildingMesh;
	UPROPERTY()
		UParticleSystemComponent* SpawnPoint;

	UPROPERTY()
		UClass* UnitToSpawn;

	UPROPERTY()
		float SpawnInterval;

	UFUNCTION()
		void SpawnUnit();

	UFUNCTION()
		void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY()
		FTimerHandle SpawnTimerHandle;

	UPROPERTY()
		UParticleSystemComponent* VisualRepresentation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
