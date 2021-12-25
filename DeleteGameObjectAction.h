#pragma once

#include "Action.h"

class DeleteGameObjectAction : public Action
{
	// [Action Parameters]
	CellPosition cellPosition; // 1- cell position of the cell

public:
	DeleteGameObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cellPosition)

	virtual void Execute();

	virtual ~DeleteGameObjectAction(); // A Virtual Destructor
};

