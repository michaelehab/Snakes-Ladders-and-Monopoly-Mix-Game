#include "CardThree.h"


CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; //sets the inherited cardNumber data member with the card number
}


void CardThree::ReadCardParameters(Grid* pGrid)
{
	//No Parameters for CardThree
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);		//printing a statement that tells the player he/she stands on card Seven

	pGrid->PrintErrorMessage("This card gives you another dice roll. Click to continue...");

	int Player_Num = pPlayer->GetPlayerNum();		//Getting the number of the player ( 0 to 3 )

	Player_Num += 3;								//To make to turn return to the same player when 
													//RollDiceAction class increments the currplayernum 

	pGrid->SetCurrentPlayer(Player_Num);			//Setting the order of the player to roll to dice to the same player 

	pGrid->PrintErrorMessage("Another dice roll for player " + to_string(Player_Num - 3));
}


void CardThree::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		// No Card Parameters here
	}
}

void  CardThree::Load(ifstream& InFile)
{
	Card::Load(InFile);
}

CardThree::~CardThree(void)
{
}