#include "Cards_9_11.h"

Cards_9_11::Cards_9_11(const CellPosition& pos) : Card(pos) // set the cell position of the card
{

	

}

Cards_9_11::~Cards_9_11(void)
{
}

void Cards_9_11::ReadCardParameters(Grid* pGrid, int& CardPrice, int& fees, Player*& p, bool& IsBought)
{

	// Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Sets the price of this card
	if ((CardPrice == 0) && (fees == 0))
	{
		pOut->PrintMessage("New Card " + to_string(cardNumber) + " : Enter the Card price. ");
		CardPrice = pIn->GetInteger(pOut);
		if (CardPrice < 0)
		{

			int x, y;
			pOut->PrintMessage("you entered invalid value, Click to continue.");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			return;
		}

		// sets the fees that the player pays to the owner of the card
		pOut->PrintMessage("Please enter the fees.");
		fees = pIn->GetInteger(pOut);
		if (fees < 0)
		{

			int x, y;
			pOut->PrintMessage("you entered invalid value, Click to continue.");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			return;
		}
	}
	else
	{
		int x, y;
		pOut->PrintMessage("New Card " + to_string(cardNumber) + ", Click to continue.. ");
		pIn->GetPointClicked(x, y);
	}
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
bool Cards_9_11::CheckInputValidity(int& CardPrice, int& fees)
{
	if (CardPrice < 0 || fees < 0)
	{
		CardPrice = 0;
		fees = 0;
		return 0;
	}
	return 1;
}


void Cards_9_11::Apply(Grid* pGrid, Player* pPlayer,int& CardPrice, int& fees, Player*& p, bool& IsBought)
{
	//Call Apply() of the base class Card to print the message that you reached this card number
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);

	//indicates whether a player bought the station or not
	//if no player bought the station ,then it asks the player whether he would like to buy it or not

	if (p == NULL)
	{
		pOut->PrintMessage("Do you want to buy this station? y/n");
		string choice = pIn->getString(pOut);
		//if the player wants to buy the station, then it sets the pointer(p) to the current player 
		if (tolower(choice[0]) == 'y') {
			IsBought = true;
			p = pPlayer;
			int currentwallet = pPlayer->GetWallet();
			pPlayer->SetWallet(currentwallet - CardPrice);          //Deduct the card price from the player`s wallet
		}
	}

	//if the current player is not the owner of the card then deduct the fees from the current player`s wallet
	//and add the fees to the wallet of the the owner of the station
	if ((pPlayer != p) && (p != NULL))
	{
		int currentPlayerWallet = pPlayer->GetWallet();
		pPlayer->SetWallet(currentPlayerWallet - fees);
		int cardOwnerWallet = p->GetWallet();
		p->SetWallet(cardOwnerWallet + fees);
	}

}

void Cards_9_11::Save(ofstream& outFile, ObjectType ObjType, int& CardPrice, int& fees)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		outFile << CardPrice << std::endl;
		outFile << fees << std::endl;


	}
}

void Cards_9_11::Load(ifstream& InFile, int& CardPrice, int& fees) {
	Card::Load(InFile);

	int price;
	InFile >> price;
	CardPrice = price;

	int payedfees;
	InFile >> payedfees;
	fees = payedfees;

}