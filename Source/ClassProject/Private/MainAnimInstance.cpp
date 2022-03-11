// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "MainCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime\CoreUObject\Public\Templates\Casts.h"


void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			MainCharacter = Cast<AMainCharacter>(Pawn);
		}
	}
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
		if (Pawn)
		{
			MainCharacter = Cast<AMainCharacter>(Pawn);
		}
	}
	if (Pawn != nullptr)
	{
		if (MainCharacter)
		{
			MovementSpeed = MainCharacter->GetCharacterMovement()->MaxWalkSpeed;
		}
		/*FVector Speed = Pawn->GetVelocity();
		FVector HorizontalSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = HorizontalSpeed.Size();*/
		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
	}
}
