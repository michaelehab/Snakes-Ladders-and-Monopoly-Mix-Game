#include "NewGameAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

NewGameAction::~NewGameAction()
{
}

void NewGameAction::ReadActionParameters()
{
	// No Action Parameters for the new game action.
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->StartNewGame();
}
