// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderPawn.h"     
#include <Components/SphereComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Camera/CameraComponent.h>


// Sets default values
AColliderPawn::AColliderPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SetRootComponent(SphereComponent);
    SphereComponent->InitSphereRadius(40.f);

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

    if (MeshComponentAsset.Succeeded()) {
        StaticMeshComponent->SetStaticMesh(MeshComponentAsset.Object);
    }
    StaticMeshComponent->SetupAttachment(GetRootComponent());
    StaticMeshComponent->SetWorldScale3D(FVector(0.8, 0.8, 0.8));
    StaticMeshComponent->SetRelativeLocation(FVector(0, 0, -40.f));

    //SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
   // SkeletalMeshComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(GetRootComponent());
    CameraComponent->SetRelativeLocation(FVector(-300, 0, 300));
    CameraComponent->SetRelativeRotation(FRotator(-45, 0, 0));

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AColliderPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColliderPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AColliderPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveVertical", this, &AColliderPawn::MoveVertical);
    PlayerInputComponent->BindAxis("MoveHorizontal", this, &AColliderPawn::MoveHorizontal);
}


void  AColliderPawn::MoveVertical(float InValue)
{
    FVector FwdDirection = GetActorForwardVector();
    
    AddMovementInput(FwdDirection * InValue);
}

void  AColliderPawn::MoveHorizontal(float InValue)
{
    FVector RightDirection = GetActorRightVector();
    AddMovementInput(RightDirection * InValue);
}

