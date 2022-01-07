#include "SwitchToDesignModeAction.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void SwitchToDesignModeAction::ReadActionParameters()
{

}
void SwitchToDesignModeAction::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Are you sure you want to end this game? y/n");
	string choice = pIn->getString(pOut);
	if (tolower(choice[0]) == 'y') {
		pOut->ClearStatusBar();
		pOut->CreateDesignModeToolBar();
		pManager->ExecuteAction(NEW_GAME);
	}
	else if(tolower(choice[0]) == 'n'){
		pOut->ClearStatusBar();
	}
	else {
		pGrid->PrintErrorMessage("The value you entered is invalid, Try again with a valid one, Click to continue...");
	}
}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{
}