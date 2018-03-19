// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFirstCPPActor.h"
#include "ConstructorHelpers.h"


// Sets default values
AMyFirstCPPActor::AMyFirstCPPActor()
{
	/*
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Add a mesh component
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");

	//Add a defaut mesh
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));//The string is of the format "{ObjectType}'/Path/To/Asset.Asset'"
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	*/
}

// Called when the game starts or when spawned
void AMyFirstCPPActor::BeginPlay()
{
	Super::BeginPlay();

	//Create self Destructor timer
	//SetLifeSpan(10);

}

// Called every frame
void AMyFirstCPPActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

