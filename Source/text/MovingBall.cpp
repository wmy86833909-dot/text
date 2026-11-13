// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingBall.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
// Sets default values
AMovingBall::AMovingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	RootComponent = BallMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereMeshAsset.Succeeded()) {
		BallMesh->SetStaticMesh(SphereMeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> SphereMatAsset(
		TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
	if (SphereMatAsset.Succeeded()) {
		BallMesh->SetMaterial(0, SphereMatAsset.Object);
	}
}

// Called when the game starts or when spawned
void AMovingBall::BeginPlay()
{
	Super::BeginPlay();
	Wait = false;
	PassedWaitTime = 0.0;
	Progress = 0.0;
	Direction = 1;
	CurrentPoint = StartPoint;
}

// Called every frame
void AMovingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Wait) {
		PassedWaitTime += DeltaTime;
		if (PassedWaitTime >= WaitTime) {
			Wait = false;
			PassedWaitTime = 0;
			Direction *= -1;
			Progress = 0;
		}
		return;
	}
	Progress += DeltaTime * speed;
	Alpha = Sin(Progress);
	CurrentPoint = Point(Direction, Alpha, StartPoint, EndPoint);
	SetActorLocation(CurrentPoint);
	if (Progress >= PI) {
		Wait = true;
	}
}

