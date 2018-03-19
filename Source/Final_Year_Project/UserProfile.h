// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "UObject/NoExportTypes.h"
#include "UserProfile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)

class FINAL_YEAR_PROJECT_API UUserProfile : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
		TSubclassOf<UObject> UClassOfPlayer; //Displays any UClasses
	
	// Displays string names of UCLASSes that derive from
    // the GameMode C++ base class
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit)
		FStringClassReference UClassGameMode;

	//ObjectType* object = ConstructObject<ObjectType>(UClassReference);

	void DoSomthing();
};
