#include "Snake.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos) 
{
	this->endCellPos = endCellPos;
	///TODO: Do the needed validation

}
void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	///TODO (Done): Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click

	pOut->PrintMessage("You have reached a snake. Click to continue ...");
	pIn->GetCellClicked();

	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}
Snake::~Snake() {};