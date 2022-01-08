#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

Card* CardSeven::GetCopy(const CellPosition& pos)
{
	return new CardSeven(pos);
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
	//array of pointers to all the players whose cells are directly after the current player`s cell
	Player* NextPlayers[MaxPlayerCount];
	pGrid->GetNextPlayer(pPlayer, NextPlayers);
	CellPosition* CellPositionToMoveTo;
	for (int i = 0; i < MaxPlayerCount; i++)
		if (NextPlayers[i] != NULL)
			//restarts the game for the all the players whose cells are directly after the current player`s cell
			pGrid->UpdatePlayerCell(NextPlayers[i], CellPositionToMoveTo->GetCellPositionFromNum(1));

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

CardSeven::~CardSeven(void)
{
}