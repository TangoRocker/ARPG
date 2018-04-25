// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once




#include "CoreMinimal.h"
#include "ARPGWeapon.h"
#include "GameFramework/Character.h"
#include "ARPGCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthUpdateDelegate);

UCLASS(Blueprintable)
class AARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AARPGCharacter();

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite)
	FHealthUpdateDelegate healthDelegate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health_MAX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health_CURRENT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mana_MAX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mana_CURRENT;

	UFUNCTION(BlueprintCallable)
	void updateCurrentHealth(float value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AARPGWeapon *Weapon;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

private:

	void initUnrealEngine();

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;
};

