// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicSkill.h"

BasicSkill::BasicSkill() {};

BasicSkill::BasicSkill(bool interupt, bool async, bool animSkip, int priority, class AARPGCharacter *actor):
	isInterruptible(interupt),
	allowsAsync(async),
	allowsAnimationSkip(animSkip),
	priority(priority),
	owner(actor)
{
	this->isActive = false;
}
/*
void BasicSkill::executeAction(void) {};
void BasicSkill::onBindingPress(void) {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("onBindingPress BS.cpp"));
};
void BasicSkill::onBindingRelease(void) {};*/

BasicSkill::~BasicSkill() {

}