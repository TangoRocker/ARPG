// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ARPGCharacter.h"


#include "ARPGPlayerController.generated.h"


UCLASS()
class AARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AARPGPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	AARPGCharacter *MyPawn;

	

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	UFUNCTION(BlueprintCallable)
	void OnInvetoryShow();

	UFUNCTION(BlueprintCallable)
	void OnAction_1();

	UFUNCTION(BlueprintCallable)
	void OnAction_2();

	UFUNCTION(BlueprintCallable)
	void OnAction_3();

	UFUNCTION(BlueprintCallable)
	void OnAction_4();

	UFUNCTION(BlueprintCallable)
	void OnAction_5();


	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


