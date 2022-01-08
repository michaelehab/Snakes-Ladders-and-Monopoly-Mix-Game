#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)

}


CardSix::CardSix(int cardNumber, int CellNummToMoveTo):Card(NULL) {
	this->cardNumber = cardNumber;
	this->CellNumToMoveTo = CellNummToMoveTo;
}
void CardSix::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the CellToMoveTo parameter with it

	pOut->PrintMessage("New CardSix: Click on the cell to move to");

	CellToMoveTo = pIn->GetCellClicked();
	// 3- Validation to click inside the grid area
	if (!CellToMoveTo.IsValidCell() || CellToMoveTo.GetCellNum() == this->GetPosition().GetCellNum())
	{
		int x, y;
		pOut->PrintMessage("You clicked on an invalid cell, Click to continue.");
		pIn->GetPointClicked(x, y);

	}

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
bool CardSix::CheckInputValidity()
{
	if (CellNumToMoveTo <= 0 || CellNumToMoveTo > 99)
		return 0;
	return 1;
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); //Call Apply() of the base class Card to print the message that you reached this card number
	if (!(!CellToMoveTo.IsValidCell() || CellToMoveTo.GetCellNum() == this->GetPosition().GetCellNum()))
	{
		int newposition = CellToMoveTo.GetCellNum() - (pPlayer->GetCell()->GetCellPosition().GetCellNum());

		pPlayer->Move(pGrid, newposition);

		pPlayer->SetTurnCount(pPlayer->GetTurnCount() - 1);
	}
}

void CardSix::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		outFile << this->CellToMoveTo.GetCellNum() << std::endl;
	}
}

void CardSix::Load(ifstream& InFile) {
	Card::Load(InFile);
	int CellNum;
	InFile >> CellNum;
	this->CellToMoveTo = CellPosition::GetCellPositionFromNum(CellNum);
}

CardSix:: ~CardSix()
{

}
bool CardSix::CheckInputValidity()
{
	if (!CellToMoveTo.IsValidCell() || CellToMoveTo.GetCellNum() == this->GetPosition().GetCellNum())
		return 0;
	return 1;
}
