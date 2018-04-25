// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARPGWeapon.generated.h"

UCLASS()
class ARPG_API AARPGWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARPGWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void PullTrigger();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void Fire();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon")
	void ReleaseTrigger();
};
