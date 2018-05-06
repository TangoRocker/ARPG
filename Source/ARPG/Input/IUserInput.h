#pragma once
class ARPG_API IUserInput
{
	public:
		void executeAction(void);
		void onBindingPress(void);
		void onBindingRelease(void);
};
