#include "CardEleven.h"
int CardEleven::CardPrice = 0;
int CardEleven::fees = 0;
Player* CardEleven::p = NULL;
bool CardEleven::IsBought = 0;
CardEleven::CardEleven(const CellPosition& pos) : Cards_9_11(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (9 here)

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
	Cards_9_11::ReadCardParameters(pGrid, CardPrice, fees, p, IsBought);
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Cards_9_11::Apply(pGrid, pPlayer, CardPrice, fees, p, IsBought);
}

bool CardEleven::CheckInputValidity()
{
	bool validity = Cards_9_11::CheckInputValidity(CardPrice, fees);
	return validity;
}


void CardEleven::Save(ofstream& outFile, ObjectType ObjType)
{
	Cards_9_11::Save(outFile, ObjType, CardPrice, fees);
}

void CardEleven::Load(ifstream& InFile)
{
	Cards_9_11::Load(InFile, CardPrice, fees);
}

