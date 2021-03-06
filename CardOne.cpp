#include "CardOne.h"

CardOne::CardOne(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

Card* CardOne::GetCopy(const CellPosition& pos)
{
	Card* pCard = new CardOne(pos); // Create a new CardOne in the CellPosition passed to the function 
	((CardOne*)pCard)->walletAmount = this->walletAmount; // Copy the card data mamber to the new one
	return pCard; // Returning the new card 
}

void CardOne::ReadCardParameters(Grid* pGrid)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	
	pOut->PrintMessage("New CardOne: Enter the wallet amount to decrement ");
	walletAmount = pIn->GetInteger(pOut);
	if (walletAmount < 0)
	{
		int x, y;
		pOut->PrintMessage("you entered invalid value, Click to continue.");
		pIn->GetPointClicked(x, y);
	}

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
bool CardOne::CheckInputValidity()
{
	if (walletAmount < 0)
		return 0;
	return 1;
}


void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid,pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	int newWalletValue=pPlayer->GetWallet() - walletAmount; 
	pPlayer->SetWallet(newWalletValue);      //sets the new value of the wallet after the decrement
	
}

void CardOne::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		outFile << walletAmount << std::endl;
	}
}

void CardOne::Load(ifstream& InFile) {
	Card::Load(InFile);
	int wallet;
	InFile >> wallet;
	walletAmount = wallet;
}
