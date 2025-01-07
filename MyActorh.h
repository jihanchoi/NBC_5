// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TEST_API AMyActor : public AActor
{
	GENERATED_BODY()
private:
	FVector2D start;
	int32 evCnt;
	float totDist;
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32_t step() {
		int32 randomV = FMath::RandRange(0, 1);
		return randomV;
	}
	int32_t createEvent() {
		return ++evCnt;
	}

	void move() {
		FVector2D first = start;
		start = FVector2D(start.X + step(), start.Y + step());
		UE_LOG(LogTemp, Warning, TEXT("Coordinates : %.1f, %.1f"),start.X, start.Y);
		UE_LOG(LogTemp, Warning, TEXT("Travel Distance : %.2f"), distance(first, start));
		if (step() % 2 == 0){
			UE_LOG(LogTemp, Warning, TEXT("Event! / Count : %d"), createEvent());  
		}
	}

	float distance(FVector2D first, FVector2D second) {
		float dis = sqrt(pow(second.X - first.X, 2) + pow(second.Y - first.Y, 2));
		totDist += dis;
		return dis;
	}

	float totalDis() const {
		return totDist;
	}
};
