// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpike.h"

AWallSpike::AWallSpike()
{


}


void AWallSpike::BeginPlay()

{
	Super::BeginPlay();

	//this->GetRootComponent()->ComponentVelocity = FVector(0, 700, 0);

	CanMove = false;

	GetWorld()->GetTimerManager().SetTimer(BeginningTimer, this, &AWallSpike::StartMove, 1.0f, false, 3.0f);


}


void AWallSpike::StartMove()
{

	CanMove = true;

}

void AWallSpike::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);


	if (CanMove)

	{

		SetActorLocation(GetActorLocation() + FVector(0, 230 * DeltaTime, 0), true);
	}

}


