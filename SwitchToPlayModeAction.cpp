#include "SwitchToPlayModeAction.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void SwitchToPlayModeAction::ReadActionParameters()
{

}
void SwitchToPlayModeAction::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Do you want to save the gird before playing? y/n");
	string choice = pIn->getString(pOut);
	if (tolower(choice[0]) == 'y') {
		pManager->ExecuteAction(SAVE_GRID);
		pOut->ClearStatusBar();
		pOut->CreatePlayModeToolBar();
	}
	else if (tolower(choice[0]) == 'n') {
		pOut->ClearStatusBar();
		pOut->CreatePlayModeToolBar();
	}
	else {
		pGrid->PrintErrorMessage("The value you entered is invalid, Try again with a valid one, Click to continue...");
	}

}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{
}