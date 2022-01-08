#include "CardNine.h"

int CardNine::CardPrice = 0;
int CardNine::fees = 0;
Player* CardNine::p = NULL;
bool CardNine::IsBought = 0;

CardNine::CardNine(const CellPosition& pos) : Cards_9_11(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
}

Card* CardNine::GetCopy(const CellPosition& pos)
{
	return new CardNine(pos);
}

Player* CardNine::GetPlayer() {
	return p;
}

int CardNine::GetCardPrice() {
	return CardPrice;
}

void CardNine::SetPlayer(Player* player) {
	p = player;
}
void CardNine::ReadCardParameters(Grid* pGrid)
{
	Cards_9_11::ReadCardParameters(pGrid, CardPrice, fees, p, IsBought);
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Cards_9_11::Apply(pGrid, pPlayer, CardPrice, fees, p, IsBought);
}

bool CardNine::CheckInputValidity()
{
	bool validity = Cards_9_11::CheckInputValidity(CardPrice, fees);
	return validity;
}


void CardNine::Save(ofstream& outFile, ObjectType ObjType)
{
	Cards_9_11::Save(outFile, ObjType, CardPrice, fees);
}

void CardNine::Load(ifstream& InFile)
{
	Cards_9_11::Load(InFile, CardPrice, fees);
}

CardNine::~CardNine(void)
{
}