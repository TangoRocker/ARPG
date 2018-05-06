// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerMovement.h"

PlayerMovement::PlayerMovement()
{
}


PlayerMovement::PlayerMovement(bool interupt, bool async, bool animSkip, int priority, class AARPGCharacter *actor):
	BasicSkill(interupt, async, animSkip, priority, actor)
{

}

void PlayerMovement::onBindingPress(){

}

void PlayerMovement::onBindingRelease() {

}

void PlayerMovement::executeAction() {

}

void PlayerMovement::SetNewMoveDestination(const FVector DestLocation) {

}

PlayerMovement::~PlayerMovement()
{
}