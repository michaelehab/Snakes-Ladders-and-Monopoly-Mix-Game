#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::CardTwo(int cardNumber):Card(NULL)
{
	this->cardNumber = cardNumber;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//No Parameters for CardTwo
}

Card* CardTwo::GetCopy() {
	return new CardTwo(cardNumber);
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Ladder * next_ladder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	if (next_ladder != NULL) {
		Cell next_ladder_cell(next_ladder->GetPosition());
		pPlayer->SetCell(&next_ladder_cell);
	}
}

void CardTwo::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		// No Card Parameters here
	}
}

void CardTwo::Load(ifstream& InFile) {
	Card::Load(InFile);
}

CardTwo::~CardTwo(void)
{
}