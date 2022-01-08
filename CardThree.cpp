#include "CardThree.h"


CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; //sets the inherited cardNumber data member with the card number
}

Card* CardThree::GetCopy(const CellPosition& pos)
{
	return new CardThree(pos);
}


void CardThree::ReadCardParameters(Grid* pGrid)
{
	//No Parameters for CardThree
}

Card* CardThree::GetCopy() {
	return new CardThree(cardNumber);
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);		

	// Printing a message showing the player the details of card three
	pGrid->PrintErrorMessage("This card gives you another dice roll. Click to continue...");

	//Getting the player number
	int player_num = pPlayer->GetPlayerNum();

	// Advancing the player turn three times to get back to the same player
	for (int i = 0; i < 3; i++) pGrid->AdvanceCurrentPlayer();

	pGrid->PrintErrorMessage("Player " + to_string(player_num) + " Got an extra dice roll, Click to continue...");
}


void CardThree::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		// No Card Parameters here
		outFile << std::endl;
	}
}

void  CardThree::Load(ifstream& InFile)
{
	Card::Load(InFile);
}

CardThree::~CardThree(void)
{
}