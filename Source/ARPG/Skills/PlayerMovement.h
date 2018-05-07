#pragma once
#include "BasicSkill.h"
#include "GameFramework/PlayerController.h"
#include "ARPGPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"

class ARPG_API PlayerMovement : public BasicSkill {

public:

	BasicSkill *trigger;
	AARPGPlayerController *controler;

	PlayerMovement();
	PlayerMovement(bool interupt, bool async, bool animSkip, int priority, class AARPGCharacter *actor);

	void onBindingPress(void);
	void onBindingRelease(void);
	void executeAction(void);
	void SetNewMoveDestination(const FVector DestLocation);

	~PlayerMovement();
};