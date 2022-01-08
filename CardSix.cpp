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

	pOut->PrintMessage("New CardSix: Click on the cell to move to");
	CellToMoveTo = pIn->GetCellClicked();
	// 3- Validation to click inside the grid area
	while (!CellToMoveTo.IsValidCell() || CellToMoveTo.GetCellNum() == this->GetPosition().GetCellNum())
	{
		pOut->PrintMessage("Please click on a valid cell!");

		CellToMoveTo = pIn->GetCellClicked();
	}

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); //Call Apply() of the base class Card to print the message that you reached this card number

	//sets the new position of the player as the position of the cell to move to
	pGrid->UpdatePlayerCell(pPlayer, CellToMoveTo);


	if (pPlayer->GetCell()->GetGameObject())
	{
		string msg;
		msg = "Player : " + to_string(pPlayer->GetPlayerNum()) + " Will take a ";
		if (pPlayer->GetCell()->HasLadder()) msg += "ladder";
		else if (pPlayer->GetCell()->HasSnake()) msg += "snake";
		else if (pPlayer->GetCell()->HasCard()) msg += "card";
		msg += ". Click to continue...";
		pGrid->PrintErrorMessage(msg);
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);
	}
	else if(CellToMoveTo.GetCellNum() == NumHorizontalCells * NumVerticalCells) 
	{
		pGrid->SetEndGame(true);
		pGrid->PrintErrorMessage("Game Over! Player : " + to_string(pPlayer->GetPlayerNum()) + " Won!");
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

