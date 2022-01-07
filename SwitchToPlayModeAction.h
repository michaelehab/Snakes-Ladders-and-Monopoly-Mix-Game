#pragma once
#include "Action.h"

class SwitchToPlayModeAction : public Action
{
public:
	SwitchToPlayModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~SwitchToPlayModeAction();
};
