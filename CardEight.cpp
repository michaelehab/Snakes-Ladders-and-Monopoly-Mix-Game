#include "CardEight.h"


CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; //sets the inherited cardNumber data member with the card number
}


void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the amount of money to get out of prison.");
	amount = pIn->GetInteger(pOut);
	if (amount < 0){
		pGrid->PrintErrorMessage("The amount you entereed is invalid, Click to continue.");
	}
	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);		//printing a statement that tells the player he/she stands on card Eight
	int Player_Num = pPlayer->GetPlayerNum();		//Getting the number of the player ( 0 to 3 )
	pGrid->PrintErrorMessage("This Card is a Prison. Click to continue...");
	string choice;
	pOut->PrintMessage("Do you want to pay " + to_string(amount) + " to get out of prison? 'y' for yes and 'n' for no");
	choice = pIn->getString(pOut);
	if (choice == "y") {
		if (pPlayer->Pay(amount)) {
			pGrid->PrintErrorMessage("Player : " + to_string(Player_Num) + " is now out of prison. Click to continue...");
		}
		else {
			pGrid->PrintErrorMessage("Player : " + to_string(Player_Num) + " does not have this amount of money, the player is now in prison. Click to continue...");
		}
	}
	else if (choice == "n") {
		pPlayer->PutInPrison();
		pGrid->PrintErrorMessage("Player : " + to_string(Player_Num) + " is now in prison. Click to continue...");
	}
	else {
		pGrid->PrintErrorMessage("You entered an invalid choice, Click to continue...");
	}
}


void CardEight::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		outFile << amount << std::endl;
	}
}

void CardEight::Load(ifstream& InFile)
{
	Card::Load(InFile);
	int a;
	InFile >> a;
	amount = a;
}

CardEight::~CardEight(void)
{
}