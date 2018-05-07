#pragma once
class ARPG_API IUserInput
{
	public:
		virtual void executeAction(void) = 0;
		virtual void onBindingPress(void) = 0;
		virtual void onBindingRelease(void) = 0;
};
