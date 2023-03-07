// Fill out your copyright notice in the Description page of Project Settings.


#include "Running_Character.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"

#include "Spikes.h"
#include "WallSpike.h"
#include "Engine.h"



// Sets default values
ARunning_Character::ARunning_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false; 

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Camera"));
	SideViewCamera->bUsePawnControlRotation = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);

	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.8f;
	GetCharacterMovement()->JumpZVelocity = 1000.0f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;

	tempPos = GetActorLocation();
	zPosition = tempPos.Z + 300.0f;

	Speed = 220.0f;

}

// Called when the game starts or when spawned
void ARunning_Character::BeginPlay()
{
	Super::BeginPlay();


	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ARunning_Character::OnOverlapBegin);

	CanMove = false;

	FTimerHandle BeginningTimer;

	GetWorld()->GetTimerManager().SetTimer(BeginningTimer, this, &ARunning_Character::StartingMovement, 1.0f, false, 3.0f);

	//SetActorRotation(FRotator(0.0f, 0.0f, 0.000719f));
	
}

// Called every frame
void ARunning_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	tempPos = GetActorLocation();
	tempPos.X -= 830.0f;
	tempPos.Z = zPosition;
	SideViewCamera->SetWorldLocation(tempPos);



	if (CanMove)
	{

		AddMovementInput(FVector(0, 60, 0), 1.0f, true);

	}
}

// Called to bind functionality to input
void ARunning_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &ARunning_Character::MoveRight);

}

void ARunning_Character::MoveRight(float value)
{

	//if (CanMove)
	//{
		//AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value);

		//AddMovementInput(GetActorForwardVector() + FVector(0, 20, 0), value);
//	}


}

void ARunning_Character::StartingMovement()
{
	CanMove = true;

}

void ARunning_Character::RestartLevel()
{

	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));


}

void ARunning_Character::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor != nullptr)
	{

		ASpikes* WallSpike = Cast<AWallSpike>(OtherActor);
		ASpikes* Spike = Cast<ASpikes>(OtherActor);


		if (WallSpike || Spike)
		{

			GetMesh()->Deactivate();
			GetMesh()->SetVisibility(false);

			CanMove = false;

			FTimerHandle GameTimer;

			GetWorld()->GetTimerManager().SetTimer(GameTimer, this, &ARunning_Character::RestartLevel, 1.0f, false);

		}


	}

}

