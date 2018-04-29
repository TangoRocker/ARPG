// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARPGWeapon.h"
#include "ARPGEnemy.generated.h"

UCLASS()
class ARPG_API AARPGEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARPGEnemy();

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
