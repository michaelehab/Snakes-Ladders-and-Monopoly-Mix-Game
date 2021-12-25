#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Ladder * next_ladder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	if (next_ladder != NULL) {
		Cell next_ladder_cell(next_ladder->GetPosition());
		pPlayer->SetCell(next_ladder_cell);
	}
}
