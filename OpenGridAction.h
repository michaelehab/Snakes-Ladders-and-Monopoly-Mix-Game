#pragma once

#include "Action.h"

class OpenGridAction : public Action
{
	string FileName; // The name of the file that contains the grid details

public:
	OpenGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads OpenGridAction action parameters (FileName)

	virtual void Execute(); //  Reads the Parameters of OpenGridAction and fill the game grid with the saved game objects

	virtual ~OpenGridAction(); // A Virtual Destructor

};