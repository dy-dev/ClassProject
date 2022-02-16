// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderPawn.h"     
#include "ColliderMovementComponent.h"     
#include <Components/SphereComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/MovementComponent.h>
#include <Camera/CameraComponent.h>


// Sets default values
AColliderPawn::AColliderPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SetRootComponent(SphereComponent);
    SphereComponent->InitSphereRadius(40.f);
    SphereComponent->SetCollisionProfileName(TEXT("Pawn"));
    ColliderMovementComponent = CreateDefaultSubobject< UColliderMovementComponent>(TEXT("ColliderMovementComponent"));
    ColliderMovementComponent->UpdatedComponent = GetRootComponent();
    AutoPossessPlayer = EAutoReceiveInput::Player0;


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
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->SetRelativeRotation(FRotator(-45, 0, 0));
    SpringArmComponent->TargetArmLength = 400;
    SpringArmComponent->bEnableCameraLag = true;
    SpringArmComponent->CameraLagSpeed = 3;;




    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);





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

    FRotator Rotation = GetActorRotation();
    Rotation.Yaw += CameraInput.X;
    //Rotation.Pitch += CameraInput.Y;

    FRotator SpringArmRotation = SpringArmComponent->GetComponentRotation();
    SpringArmRotation.Pitch += CameraInput.Y;
    SpringArmRotation.Cl
    SpringArmComponent->SetWorldRotation(SpringArmRotation);

}

// Called to bind functionality to input
void AColliderPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveVertical", this, &AColliderPawn::MoveVertical);
    PlayerInputComponent->BindAxis("MoveHorizontal", this, &AColliderPawn::MoveHorizontal);
    PlayerInputComponent->BindAxis("CameraPitch", this, &AColliderPawn::PitchCamera);
    PlayerInputComponent->BindAxis("CameraYaw", this, &AColliderPawn::YawCamera);
}


void  AColliderPawn::MoveVertical(float InValue)
{
    FVector FwdDirection = GetActorForwardVector();
    UE_LOG(LogTemp, Warning, TEXT("%f"), InValue);

    ColliderMovementComponent->AddInputVector(FwdDirection * InValue * MaxSpeed, true);;
}

void  AColliderPawn::MoveHorizontal(float InValue)
{
    FVector RightDirection = GetActorRightVector();
    UE_LOG(LogTemp, Warning, TEXT("%f"), InValue);
    ColliderMovementComponent->AddInputVector(RightDirection * InValue * MaxSpeed, true);;

}

void AColliderPawn::YawCamera(float InValue)
{
    CameraInput.X = InValue;
}

void AColliderPawn::PitchCamera(float InValue)
{
    CameraInput.Y = InValue;
}

UPawnMovementComponent* AColliderPawn::GetMovementComponent() const
{
    return ColliderMovementComponent;
}