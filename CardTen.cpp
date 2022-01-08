#include "CardTen.h"

int CardTen::CardPrice = 0;
int CardTen::fees = 0;
Player* CardTen::p = NULL;
bool CardTen::IsBought = 0;

CardTen::CardTen(const CellPosition& pos) : Cards_9_11(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number (9 here)

}

Card* CardTen::GetCopy(const CellPosition& pos)
{
	return new CardTen(pos);
}

Player* CardTen::GetPlayer() {
	return p;
}

int CardTen::GetCardPrice() {
	return CardPrice;
}

void CardTen::SetPlayer(Player* player) {
	p = player;
}
void CardTen::ReadCardParameters(Grid* pGrid)
{
	Cards_9_11::ReadCardParameters(pGrid, CardPrice, fees, p, IsBought);
}

Card* CardTen::GetCopy() {
	return new CardTen(cardNumber, CardPrice, fees, p, IsBought);
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Cards_9_11::Apply(pGrid, pPlayer, CardPrice, fees, p, IsBought);
}

bool CardTen::CheckInputValidity()
{
	bool validity = Cards_9_11::CheckInputValidity(CardPrice, fees);
	return validity;
}


void CardTen::Save(ofstream& outFile, ObjectType ObjType)
{
	Cards_9_11::Save(outFile, ObjType, CardPrice, fees);
}

void CardTen::Load(ifstream& InFile)
{
	Cards_9_11::Load(InFile, CardPrice, fees);
}

CardTen::~CardTen(void)
{
}