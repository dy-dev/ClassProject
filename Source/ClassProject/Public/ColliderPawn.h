// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ColliderPawn.generated.h"

UCLASS()
class CLASSPROJECT_API AColliderPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AColliderPawn();

    UPROPERTY(EditAnywhere, Category = "Mesh")
        class USphereComponent* SphereComponent;
    UPROPERTY(EditAnywhere, Category = "Mesh")
        class UStaticMeshComponent* StaticMeshComponent;
  //  UPROPERTY(EditAnywhere, Category = "Mesh")
   //     class USkeletalMeshComponent* SkeletalMeshComponent;
    UPROPERTY(EditAnywhere, Category = "Mesh")
        class UCameraComponent* CameraComponent;

    UPROPERTY(EditAnywhere, Category = "Critter")
        float MaxSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveVertical(float InValue);
    void MoveHorizontal(float InValue);

private:
    FVector CurrentVelocity;
};
