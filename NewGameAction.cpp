#include "NewGameAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

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

	// Creating A New CellPosition With CellNum 1
	const CellPosition start(1);
	Player* p;

	// Looping On All Players
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		// Gets Current Player's address
		p = pGrid->GetCurrentPlayer();
		// Resets every player
		p->Reset();
		// Makes all the players return to cell number 1
		pGrid->UpdatePlayerCell(p, start);
		// Advances the player to reset the next one
		pGrid->AdvanceCurrentPlayer();
	}
	// Resets the grid
	pGrid->ResetGrid();
}
