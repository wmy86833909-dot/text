// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingBall.generated.h"
class UStaticMeshComponent;

UCLASS()
class TEXT_API AMovingBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, Category = "MovingBall")
	UStaticMeshComponent* BallMesh;
public:
	double Sin(double x) {
		double A;
		if (x <= PI / 2) {
			A= 0.4*x+(FMath::Sin(x) / 2.0);
		}
		else if (x > PI / 2) {
			A = 0.4*x+((-FMath::Sin(x) + 2) / 2.0);
		}
		return A;
	}
	FVector Point(int x, double y,FVector a,FVector b){
		FVector CPoint;
		if (x == 1) {
			CPoint = FMath::Lerp(a, b,y);
		}
		else {
			CPoint = FMath::Lerp(a, b, 1 -y);
		}
		return CPoint;
	}
	UPROPERTY(EditAnywhere)
	FVector StartPoint;
	UPROPERTY(EditAnywhere)
	FVector EndPoint;
	UPROPERTY(EditAnywhere)
	double speed;
	UPROPERTY(EditAnywhere)
	double WaitTime;
private:
	double PassedWaitTime, Progress,Alpha;
	int Direction;
	bool Wait;
	FVector CurrentPoint;
};
