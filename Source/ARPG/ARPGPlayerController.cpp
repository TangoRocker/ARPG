// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ARPGPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"

#include "Engine/World.h"

#include "EngineGlobals.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "ARPGWeapon.h"

AARPGPlayerController::AARPGPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AARPGPlayerController::BeginPlay() {
	Super::BeginPlay();
	MyPawn = Cast<AARPGCharacter>(GetPawn());
}

void AARPGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (MyPawn->skillList[0]->isActive) {
		MyPawn->skillList[0]->executeAction();
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


void AARPGPlayerController::OnSetDestinationPressed() {
	if (MyPawn->skillList[0] != NULL) {
		MyPawn->skillList[0]->onBindingPress();
	}
	
}

void AARPGPlayerController::OnSetDestinationReleased() {
	MyPawn->skillList[0]->onBindingRelease();
}

void AARPGPlayerController::OnInvetoryShow() {

}

void AARPGPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AARPGPlayerController::OnAction_1() {
	if (GetPawn()) {
		MyPawn->takeDamage(10);
	}
}

void AARPGPlayerController::OnAction_2() {
	if (GetPawn()) {
		MyPawn->Weapon->Fire();
	}
}

void AARPGPlayerController::OnAction_3() {
	if (GetPawn()) {
		MyPawn->Weapon->PullTrigger();
	}
}

void AARPGPlayerController::OnAction_4() {

}

void AARPGPlayerController::OnAction_5() {

}