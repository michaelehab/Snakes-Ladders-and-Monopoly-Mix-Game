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
	Output* pOut = pGrid->GetOutput();

	const CellPosition* start = new CellPosition(1);       // Creating A New CellPosition With CellNum 1
	Player* p;

	for (int i = 0; i < MaxPlayerCount; i++)          // Looping On All Players
	{
		p = pGrid->GetCurrentPlayer();				  // Gets Current PLayer's Address
		p->Reset();                                   // Resets All Parameters
		pGrid->UpdatePlayerCell(p, *start);              // Resets Player Cell To 1
		pGrid->AdvanceCurrentPlayer();				  // Advances Player To Reset Other Players
	}
	delete start;

	pGrid->SetCurrentPlayer(0);                       // start with the first player
	pGrid->SetClipboard(NULL);                  	  // Initialize Clipboard with NULL
	pGrid->SetEndGame(false);                   	  // Initialize endGame with false
}
