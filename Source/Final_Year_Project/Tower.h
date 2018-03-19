// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class FINAL_YEAR_PROJECT_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Attributes")
	bool EnemyOwner;
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void Upgrade();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		float damage = 10;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		int level = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
		float nextFire = 5;// sec

	
};
