#pragma once

#include "Action.h"

class NewGameAction : public Action
{

public:
	NewGameAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~NewGameAction(); // A Virtual Destructor
};

