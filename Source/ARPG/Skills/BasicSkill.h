// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Input/IUserInput.h"

class AARPGCharacter;
/**
 * 
 */
class ARPG_API BasicSkill : public IUserInput
{
	public:

		bool isActive;
		bool isInterruptible;
		bool allowsAsync;
		bool allowsAnimationSkip;
		int priority;
		AARPGCharacter * owner;
		
		BasicSkill();
		BasicSkill(bool interupt, bool async, bool animSkip, int priority, class AARPGCharacter *actor);

		/*void executeAction(void);
		void onBindingPress(void);
		void onBindingRelease(void);*/

		virtual ~BasicSkill() = 0;
};
