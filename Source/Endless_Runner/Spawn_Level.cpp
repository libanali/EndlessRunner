#include "Spawn_Level.h"

#include "Engine.h"
#include "Base_Level.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"


// Sets default values
ASpawn_Level::ASpawn_Level()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawn_Level::BeginPlay()
{
	Super::BeginPlay();

	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);
}

// Called every frame
void ASpawn_Level::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawn_Level::SpawnLevel(bool isFirst)
{

	SpawnLocation = FVector(0.0f, 1000.0f, 0.0f);
	SpawnRotation = FRotator(0.0f, 90.0f, 0.0f);

	if (!isFirst)
	{
		ABase_Level* LastLevel = LevelList.Last();
		SpawnLocation = LastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}

	RandomLevel = FMath::RandRange(1, 10);
	ABase_Level* NewLevel = nullptr;

	if (RandomLevel == 1)
	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level1, SpawnLocation,
			SpawnRotation, SpawnInfo);
	}

	else if (RandomLevel == 2)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level2, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}

	else if (RandomLevel == 3)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level3, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}

	else if (RandomLevel == 4)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level4, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}

	else if (RandomLevel == 5)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level5, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}


	else if (RandomLevel == 6)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level6, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}


	else if (RandomLevel == 7)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level7, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}


	else if (RandomLevel == 8)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level8, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}


	else if (RandomLevel == 9)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level9, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}


	else if (RandomLevel == 10)

	{
		NewLevel = GetWorld()->SpawnActor<ABase_Level>(Level10, SpawnLocation,
			SpawnRotation, SpawnInfo);

	}

	if (NewLevel)
	{


		if (NewLevel->GetTrigger())
		{

			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ASpawn_Level::OnOverlapBegin);

		}

	}

	LevelList.Add(NewLevel);

	if (LevelList.Num() > 5)
	{
		LevelList.RemoveAt(0);
	}


}



void ASpawn_Level::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	SpawnLevel(false);
}

