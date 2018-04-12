// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ARPGPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "ARPGCharacter.h"
#include "Engine/World.h"

AARPGPlayerController::AARPGPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AARPGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AARPGPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AARPGPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AARPGPlayerController::OnSetDestinationReleased);

	InputComponent->BindAction("ActionButton1", IE_Pressed, this, &AARPGPlayerController::OnAction_1);
	InputComponent->BindAction("ActionButton2", IE_Pressed, this, &AARPGPlayerController::OnAction_2);
	InputComponent->BindAction("ActionButton3", IE_Pressed, this, &AARPGPlayerController::OnAction_3);
	InputComponent->BindAction("ActionButton4", IE_Pressed, this, &AARPGPlayerController::OnAction_4);
	InputComponent->BindAction("ActionButton5", IE_Pressed, this, &AARPGPlayerController::OnAction_5);

	InputComponent->BindAction("InventoryButton", IE_Pressed, this, &AARPGPlayerController::OnInvetoryShow);


}

void AARPGPlayerController::OnInvetoryShow() {

}

void AARPGPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AARPGPlayerController::OnAction_1() {
	if (AARPGCharacter* MyPawn = Cast<AARPGCharacter>(GetPawn())) {
		MyPawn->updateCurrentHealth(MyPawn->health_CURRENT - 10);
	}
}

void AARPGPlayerController::OnAction_2() {
	if (AARPGCharacter* MyPawn = Cast<AARPGCharacter>(GetPawn())) {
		MyPawn->updateCurrentHealth(MyPawn->health_CURRENT + 10);
	}
}

void AARPGPlayerController::OnAction_3() {

}

void AARPGPlayerController::OnAction_4() {

}

void AARPGPlayerController::OnAction_5() {

}



void AARPGPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AARPGCharacter* MyPawn = Cast<AARPGCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UNavigationSystem::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AARPGPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AARPGPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AARPGPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AARPGPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
