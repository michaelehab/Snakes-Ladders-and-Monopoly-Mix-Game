
#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"
InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) :Action(pApp)
{

}

void InputDiceValueAction::ReadActionParameters()
{
	// A pointer to the Input/Output interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please Enter a dice value between 1-6 . ");
	int value = pIn->GetInteger(pOut);        //store the passed integer in (value)

	//Verification on the input dice value
	if (value > 0 && value < 7)
	{
		DiceValue = value;                    //sets the dice value with the input value
	}

	//if the dice value is out of range
	else
	{
		int x, y;
		DiceValue = -1;
		pOut->PrintMessage("The Dice value you entered is out of range, Click to continue. ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();

	}

	// clears the status bar
	pOut->ClearStatusBar();

}

void InputDiceValueAction::Execute()
{

	ReadActionParameters();
	// Check if the Game is ended
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	bool gameEnded = pGrid->GetEndGame();

	// -- If not ended && Dice value is within the range
	if ((!gameEnded) && (DiceValue != -1))
	{
		int x, y;
		pOut->PrintMessage("The dice value you entered is " + to_string(DiceValue)+", click to continue.");
		pIn->GetPointClicked(x,y);
		// Get the "current" player from pGrid
		Player* currentPlayer = pGrid->GetCurrentPlayer();
		// Move the currentPlayer using function Move of class player
		currentPlayer->Move(pGrid, DiceValue);
		// Advance the current player number of pGrid
		pOut->ClearStatusBar();
		pGrid->AdvanceCurrentPlayer();
	}

	// if the game ended or the dice value is out of range (or both)
	else
		return;


}

InputDiceValueAction:: ~InputDiceValueAction()
{

}