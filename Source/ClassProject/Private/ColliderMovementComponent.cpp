// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderMovementComponent.h"

void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
        return;

    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(20.0);
    if (!DesiredMovementThisFrame.IsNearlyZero()) {
        FHitResult HitResult;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, HitResult);
        //If bump into something, slide along the side of it
        if (HitResult.IsValidBlockingHit()) {
            SlideAlongSurface(DesiredMovementThisFrame, 1.f - HitResult.Time, HitResult.Normal, HitResult);
        }
    }

}

