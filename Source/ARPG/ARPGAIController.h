// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ARPGAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API AARPGAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AARPGAIController();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void FollowPlayer();

protected:
	// Called when the game starts or when spawned
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	//virtual void BeginPlay() override;
	

};
