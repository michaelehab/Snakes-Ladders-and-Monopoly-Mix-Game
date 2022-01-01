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
	Card::Apply(pGrid, pPlayer);		//printing a statement that tells the player he/she stands on card Seven

	int Player_Num = pPlayer->GetPlayerNum();		//Getting the number of the player ( 0 to 3 )

	pGrid->PrintErrorMessage("This card prevents player " + to_string(Player_Num) + " from rolling next turn . Click to continue...");

	pPlayer->PreventNextTurn(true);
}


void CardFour::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		// No Card Parameters here
	}
}

void  CardFour::Load(ifstream& InFile)
{
	Card::Load(InFile);
}

CardFour::~CardFour(void)
{
}