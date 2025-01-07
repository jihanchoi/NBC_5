#include "MyActor.h"
#include <iostream>

using namespace std;

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < 10; i++) {
		UE_LOG(LogTemp, Warning, TEXT("%d Temp"),i+1);
		move();
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Distance = %0.2f"),totalDis());
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}