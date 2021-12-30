#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardSeven, Click to continue.");
	pIn->GetPointClicked(x, y);
	//Clear the status bar
	pOut->ClearStatusBar();
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	//Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//Get a pointer to the first player whose cell is after the current player in the grid
	Player* NextPlayer = pGrid->GetNextPlayer(pPlayer);   
	CellPosition* CellPositionToMoveTo;
	if(NextPlayer !=NULL)
	//restarts the game for the first player whose cell is after the current player in the grid
		pGrid->UpdatePlayerCell(NextPlayer, CellPositionToMoveTo->GetCellPositionFromNum(1));

}

void CardSeven::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		
	}
}

void CardSeven::Load(ifstream& InFile) {
	Card::Load(InFile);

}
