#include "CardEight.h"


CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; //sets the inherited cardNumber data member with the card number
	this->amount = 0;
}


void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the amount of money to get out of prison.");
	amount = pIn->GetInteger(pOut);
	if (amount <= 0){
		pGrid->PrintErrorMessage("The amount you entered is invalid, Click to continue...");
	}
	pOut->ClearStatusBar();
}


bool CardEight::CheckInputValidity()
{
	if (amount <= 0) return 0;
	return 1;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);

	int Player_Num = pPlayer->GetPlayerNum();
	// Printing a message showing the player the details of card eight
	pGrid->PrintErrorMessage("This Card is a Prison. Click to continue...");

	// Asking the user if he/she prefers to pay money instead of spending three turns in prison
	pOut->PrintMessage("Do you want to pay " + to_string(amount) + " to get out of prison? 'y' for yes and 'n' for no");
	string choice;
	choice = pIn->getString(pOut);
	// If the player wants to pay money we'll check if he/she has this amount of money
	if (choice == "y") {
		if (pPlayer->Pay(amount)) {
			pGrid->PrintErrorMessage("Player : " + to_string(Player_Num) + " is now out of prison. Click to continue...");
		}
		else {
			pGrid->PrintErrorMessage("Player : " + to_string(Player_Num) + " does not have this amount of money, the player is now in prison. Click to continue...");
		}
	}
	// If the player refuses to pay the money then he/she will spend three turns in prison
	else if (choice == "n") {
		pPlayer->PutInPrison();
		pGrid->PrintErrorMessage("Player : " + to_string(Player_Num) + " is now in prison. Click to continue...");
	}
	// Handling invalid choice from the user
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