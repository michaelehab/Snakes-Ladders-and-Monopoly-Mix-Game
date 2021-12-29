#include "CardNine.h"
int CardNine::CardPrice = 0;
int CardNine::fees = 0;
Player* CardNine::p = NULL;
bool CardNine::IsBought = 0;
CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
	
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Sets the price of this card
	if ((CardPrice == 0) && (fees == 0))
	{
		pOut->PrintMessage("New CardNine: Enter the Card price. ");
		CardPrice = pIn->GetInteger(pOut);

		// sets the fees that the player pays to the owner of the card
		pOut->PrintMessage("Please enter the fees.");
		fees = pIn->GetInteger(pOut);
	}
	else
	{
		int x, y;
		pOut->PrintMessage("New CardNine, Click to continue.. ");
		pIn->GetPointClicked(x, y);
	}
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	//Call Apply() of the base class Card to print the message that you reached this card number
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);

	//indicates whether a player bought the station or not
	//if no player bought the station ,then it asks the player whether he would like to buy it or not

	if (p != NULL)              
	{
		pOut->PrintMessage(" Press 1 if you want to buy this station and 0 if you don`t want. ");
		//if the player wants to buy the station, then it sets the pointer(p) to the current player 
		IsBought = pIn->GetInteger(pOut);
		if (IsBought)
		{
			p =pPlayer;
			int currentwallet = pPlayer->GetWallet();
			pPlayer->SetWallet(currentwallet - CardPrice);          //Deduct the card price from the player`s wallet

		}

	}

	//if the current player is not the owner of the card then deduct the fees from the current player`s wallet
	//and add the fees to the wallet of the the owner of the station
	if (pPlayer != p)
	{
		int currentPlayerWallet = pPlayer->GetWallet();     
		pPlayer->SetWallet(currentPlayerWallet - fees);
		int cardOwnerWallet = p->GetWallet();
		p->SetWallet(cardOwnerWallet + fees);
	}

}

void CardNine::Save(ofstream& outFile, ObjectType ObjType)
{
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		outFile << CardPrice << std::endl;
		outFile << fees << std::endl;
		outFile << p << std::endl;
		outFile << IsBought << std::endl;

	}
}

void CardNine::Load(ifstream& InFile) {
	Card::Load(InFile);

	int price;
	InFile >> price;
	CardPrice = price;

	int payedfees;
	InFile >> payedfees;
	fees = payedfees;

	/*Player* p1;
	InFile >> p1;
	p = p1;*/

	bool bought;
	InFile >>bought;
	IsBought = bought;

}