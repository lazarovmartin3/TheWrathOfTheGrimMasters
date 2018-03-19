// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Root component
	UBoxComponent* BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
	RootComponent = BoxComp;
	BoxComp->InitBoxExtent(FVector(40, 40, 40));
	BoxComp->SetCollisionProfileName(TEXT("Tower"));

	//Mesh
	UStaticMeshComponent* TowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	TowerMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TowerMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (TowerMeshAsset.Succeeded())
	{
		TowerMesh->SetStaticMesh(TowerMeshAsset.Object);
		TowerMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		TowerMesh->SetWorldScale3D(FVector(0.8f));
	}
	


}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATower::Upgrade()
{
	level++;

	short percent = 18;

	//Set up stats
	//Increase the damage with % according to the level
	damage = (damage * ((percent + level) / 100)) + damage;


}


