// Fill out your copyright notice in the Description page of Project Settings.

#include "ARPGEnemy.h"
#include "ARPGWeapon.h"


// Sets default values
AARPGEnemy::AARPGEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->health_MAX = 100;
	this->health_CURRENT = 100;
}

// Called when the game starts or when spawned
void AARPGEnemy::BeginPlay()
{
	//Super::BeginPlay();
	
}

// Called every frame
void AARPGEnemy::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}

void AARPGEnemy::updateCurrentHealth(float value) {
	this->health_CURRENT = value;
	//healthDelegate.Broadcast();
}

