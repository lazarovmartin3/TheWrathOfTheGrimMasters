// Fill out your copyright notice in the Description page of Project Settings.

#include "myBarrack.h"
#include "BarracksUnit.h"
#include "ConstructorHelpers.h"




// Sets default values
AmyBarrack::AmyBarrack()
{
	/*
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("BuildingMesh");
	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	SpawnInterval = 10;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object != nullptr)
	{
		BuildingMesh->SetStaticMesh(MeshAsset.Object);

		//BuildingMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}

	/*auto ParticleSystem =
		ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/FINAL_YEAR_PROJECT/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));*/
	
	/*if (ParticleSystem.Object != nullptr)
	{
		SpawnPoint->SetTemplate(ParticleSystem.Object);
	}
	//SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	UnitToSpawn = ABarracksUnit::StaticClass(); */


	/*VisualRepresentation = CreateDefaultSubobject<UParticleSystemComponent>("SpawnPoint");
	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (ParticleSystem.Object != nullptr)
	{
		SpawnPoint->SetTemplate(ParticleSystem.Object);
	}
	SpawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;*/

}

void AmyBarrack::SpawnUnit()
{

	FVector SpawnLocation = SpawnPoint->GetComponentLocation();
	GetWorld()->SpawnActor(UnitToSpawn, &SpawnLocation);

}

void AmyBarrack::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

	Super::EndPlay(EndPlayReason);
	//GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);

}

// Called when the game starts or when spawned
void AmyBarrack::BeginPlay()
{
	Super::BeginPlay();
	/*
	RootComponent = BuildingMesh;
	SpawnPoint->AttachTo(RootComponent);
	SpawnPoint->SetRelativeLocation(FVector(150, 0, 0));

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AmyBarrack::SpawnUnit, SpawnInterval, true);
	*/

}

// Called every frame
void AmyBarrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

