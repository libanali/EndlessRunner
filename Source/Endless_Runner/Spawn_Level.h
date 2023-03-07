// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawn_Level.generated.h"

class ABase_Level;

UCLASS()
class ENDLESS_RUNNER_API ASpawn_Level : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawn_Level();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:

	UFUNCTION()
		void SpawnLevel(bool isFirst);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



protected:

	APawn* Player;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level1;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level2;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level3;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level4;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level5;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level6;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level7;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level8;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level9;


	UPROPERTY(EditAnywhere)
		TSubclassOf<ABase_Level> Level10;


	TArray<ABase_Level*> LevelList;


public:

	int RandomLevel;

	FVector SpawnLocation = FVector();
	FRotator SpawnRotation = FRotator();
	FActorSpawnParameters SpawnInfo = FActorSpawnParameters();

};
