// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Critter.generated.h"

UCLASS()
class CLASSPROJECT_API ACritter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACritter();

    UPROPERTY(EditAnywhere, Category="Mesh")
    class USkeletalMeshComponent* SkeletalMeshComponent;
    UPROPERTY(EditAnywhere, Category="Mesh")
    class UCameraComponent* CameraComponent;

    UPROPERTY(EditAnywhere, Category="Critter")
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
