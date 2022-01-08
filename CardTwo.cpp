#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

Card* CardTwo::GetCopy(const CellPosition& pos)
{
	return new CardTwo(pos);
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//No Parameters for CardTwo
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);	
	// Printing a message showing the player the details of card two
	pGrid->PrintErrorMessage("This card moves you to the start of the next ladder. Click to continue...");

	Ladder* next_ladder = pGrid->GetNextLadder(this->GetPosition()); // Getting a pointer to the next ladder

	// If there's no ladders ahead show an informative message
	if (!next_ladder)
	{
		pGrid->PrintErrorMessage("There is no ladder ahead! Click to continue...");
	}
	else {
		pGrid->UpdatePlayerCell(pPlayer, next_ladder->GetPosition());	// Moving the player to the start of the next ladder
		next_ladder->Apply(pGrid, pPlayer); // Applying the Ladder to the player
	}
}

void CardTwo::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and card position to the file
		Card::Save(outFile, ObjType);
		// No Card Parameters here
		outFile << std::endl;
	}
}

void CardTwo::Load(ifstream& InFile) {
	Card::Load(InFile);
}

CardTwo::~CardTwo(void)
{
}