// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class CLASSPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	/** Camera to look at the character*/
	UPROPERTY(EditAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
	/** Stick on which the camera is attach and on which we will apply pitch rotation*/
	UPROPERTY(EditAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

public:
	// Sets default values for this character's properties
	AMainCharacter();

	/**Base turn rates to scale turning functions for the camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseTurnRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseLookupRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RotationRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpZVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AirControl;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Called via input to turn at a given rate
	  * @Param Rate : This is the normalized rate, i.e 1.0 means 100% of desired look up / down rate
	*/
	void LookupRate(float Rate);
	
	/** Called via input to turn at a given rate
	  * @Param Rate : This is the normalized rate, i.e 1.0 means 100% of desired turn right / left rate
	*/
	void TurnRate(float Rate);

	/** Called for foward / backward movement */
	void MoveVertical(float value);
	/** Called for side to side movement */
	void MoveHorizontal(float value);
};
