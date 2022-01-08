#include "CardFour.h"


CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; //sets the inherited cardNumber data member with the card number
}


void CardFour::ReadCardParameters(Grid* pGrid)
{
	//No Parameters for CardFour
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	// Printing a message showing the player the details of card four
	pGrid->PrintErrorMessage("This card prevents player " + to_string(pPlayer->GetPlayerNum()) + " from rolling next turn. Click to continue...");

	// Preventing the player from rolling next turn
	pPlayer->PreventNextTurn(true);
}


void CardFour::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		// No Card Parameters here
		outFile << std::endl;
	}
}

void  CardFour::Load(ifstream& InFile)
{
	Card::Load(InFile);
}

CardFour::~CardFour(void)
{
}