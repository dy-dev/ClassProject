// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/MovementComponent.h>
#include <GameFramework/CharacterMovementComponent.h>

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraBoom->SetupAttachment(GetRootComponent());
	//CameraBoom->SetRelativeRotation(FRotator(-30, 0, 0));
	CameraBoom->TargetArmLength = 550;
	//CameraBoom->bEnableCameraLag = true;
	//CameraBoom->CameraLagSpeed = 3;
	CameraBoom->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//Rotate arm base on the controller, not the pawn
	CameraComponent->bUsePawnControlRotation = false;

	//Init values for turning capacities
	BaseTurnRate = 65.f;
	BaseLookupRate = 65.f;


	/**********/

	//To prevent the character to rotate with the controller which must affect only the camera
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	/**********/

	RotationRate = 540.f;
	JumpZVelocity = 650.f;
	AirControl = 0.2f;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; //Character move in the direction to the movement...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, RotationRate, 0.f); //... at this rotation rate

	GetCharacterMovement()->JumpZVelocity = JumpZVelocity;
	GetCharacterMovement()->AirControl = AirControl;
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ACharacter::StopJumping);
	
	PlayerInputComponent->BindAxis("MoveVertical", this, &AMainCharacter::MoveVertical);
	PlayerInputComponent->BindAxis("MoveHorizontal", this, &AMainCharacter::MoveHorizontal);

	//Camera management with up / left / right / down keys
	PlayerInputComponent->BindAxis("TurnRate", this, &AMainCharacter::TurnRate);
	PlayerInputComponent->BindAxis("LookupRate", this, &AMainCharacter::LookupRate);

	//Camera management with mouse
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput); 
}


void AMainCharacter::LookupRate(float InValue)
{
	UE_LOG(LogTemp, Warning, TEXT("Lookup : %f"), InValue);
	//BaseLookupRate is 65 ° by seconds, we have to multiply it by delta seconds and 
	// by the speed ratio
	AddControllerPitchInput(InValue * BaseLookupRate * GetWorld()->GetDeltaSeconds());
}

void AMainCharacter::TurnRate(float InValue)
{
	UE_LOG(LogTemp, Warning, TEXT("Turn : %f"), InValue);
	AddControllerYawInput(InValue * BaseTurnRate * GetWorld()->GetDeltaSeconds());

}

/** Make the caracter move in the direction in which the camera is facing
  * Since the camera is linked to the camera boom and the cameraboom is attached 
  * to the controller what we need is actually where is the controller is facing
  */
void AMainCharacter::MoveVertical(float value)
{
	if (Controller != nullptr && value != 0.0) {
		//Find the forward vector
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.);
		//We get the rotation matrix from the rotator to extrac the X axis which will give the forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AMainCharacter::MoveHorizontal(float value)
{
	if (Controller != nullptr && value != 0.0) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation = FRotator(0.f, Rotation.Yaw, 0.);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}

