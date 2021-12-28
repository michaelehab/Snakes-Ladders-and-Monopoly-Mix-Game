#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)

}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the CellToMoveTo parameter with it

	pOut->PrintMessage("New CardSix: Enter the cell to move to ");
	CellNumToMoveTo = pIn->GetInteger(pOut);
	

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); //Call Apply() of the base class Card to print the message that you reached this card number
	CellPosition* CellPositionToMoveTo;
	Cell CellToMoveTo(CellPositionToMoveTo->GetCellPositionFromNum(CellNumToMoveTo));
	pPlayer->SetCell(&CellToMoveTo);      //sets the pCell of the player with the new cell position
}

void CardSix::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		outFile << CellNumToMoveTo << std::endl;
	}
}

void CardSix::Load(ifstream& InFile) {
	Card::Load(InFile);
	int CellNum;
	InFile >> CellNum;
	CellNumToMoveTo = CellNum;
}

CardSix:: ~CardSix()
{

}

