#include "CardEleven.h"
int CardEleven::CardPrice = 0;
int CardEleven::fees = 0;
Player* CardEleven::p = NULL;
bool CardEleven::IsBought = 0;
CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (11 here)

}

CardEleven::~CardEleven(void)
{
}


Player* CardEleven::GetPlayer() {
	return p;
}


int CardEleven::GetCardPrice() {
	return CardPrice;
}

void CardEleven::SetPlayer(Player* player) {
	p = player;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{

	//Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Sets the price of this card
	if ((CardPrice == 0) && (fees == 0))
	{
		pOut->PrintMessage("New CardEleven: Enter the Card price. ");
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
		pOut->PrintMessage("New CardEleven, Click to continue.. ");
		pIn->GetPointClicked(x, y);
	}
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
bool CardEleven::CheckInputValidity()
{
	if (CardPrice < 0 || fees < 0)
	{
		CardPrice = 0;
		fees = 0;
		return 0;
	}
	return 1;
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	//Call Apply() of the base class Card to print the message that you reached this card number
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);

	//indicates whether a player bought the station or not
	//if no player bought the station ,then it asks the player whether he would like to buy it or not

	if (p == NULL)
	{
		pOut->PrintMessage(" Press 1 if you want to buy this station and 0 if you don`t want. ");
		//if the player wants to buy the station, then it sets the pointer(p) to the current player 
		IsBought = pIn->GetInteger(pOut);
		if (IsBought)
		{
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

void CardEleven::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		outFile << CardPrice << std::endl;
		outFile << fees << std::endl;


	}
}

void CardEleven::Load(ifstream& InFile) {
	Card::Load(InFile);

	int price;
	InFile >> price;
	CardPrice = price;

	int payedfees;
	InFile >> payedfees;
	fees = payedfees;

}