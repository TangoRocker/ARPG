// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerMovement.h"
#include "Engine.h"
#include "Engine/LocalPlayer.h"

PlayerMovement::PlayerMovement()
{
	this->isActive = false;
}


PlayerMovement::PlayerMovement(bool interupt, bool async, bool animSkip, int priority, class AARPGCharacter *actor):
	BasicSkill(interupt, async, animSkip, priority, actor)
{
	this->isActive = false;
	if (owner) {
		this->controler = Cast<AARPGPlayerController>(owner->GetController());
	}
}

void PlayerMovement::onBindingPress(){
	this->isActive = true;
}

void PlayerMovement::onBindingRelease() {
	this->isActive = false;
}

void PlayerMovement::executeAction() {
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (owner->GetCursorToWorld())
		{
			UNavigationSystem::SimpleMoveToLocation(this->controler, owner->GetCursorToWorld()->GetComponentLocation());
		}
		
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		this->controler->GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "el else del execute");
		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void PlayerMovement::SetNewMoveDestination(const FVector DestLocation) {
	if (owner)
	{
		UNavigationSystem* const NavSys = this->controler->GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, owner->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this->controler, DestLocation);
		}
	}
}

PlayerMovement::~PlayerMovement()
{
}