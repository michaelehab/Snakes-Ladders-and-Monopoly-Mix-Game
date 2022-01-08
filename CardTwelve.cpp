#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos): Card(pos) {
	cardNumber = 12;
}

CardTwelve::CardTwelve(int cardNumber) :Card(NULL) {
	this->cardNumber = cardNumber;
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer) {
	if (pGrid->GetPlayerWithLeastCoins() == pPlayer)
		return;
	if (CardNine::GetPlayer()==pPlayer||CardTen::GetPlayer() == pPlayer||CardEleven::GetPlayer()==pPlayer)
	{
		for (int i = 0; i <= MaxPlayerCount; i++) {

		}

		int Expensivest_Station = max(CardNine::GetCardPrice(), CardTen::GetCardPrice(),CardEleven::GetCardPrice());
		if (CardNine::GetCardPrice() == Expensivest_Station)

			CardNine::SetPlayer(pGrid->GetPlayerWithLeastCoins());

		else if(CardTen::GetCardPrice() == Expensivest_Station)

			CardTen::SetPlayer(pGrid->GetPlayerWithLeastCoins());

		else if(CardEleven::GetCardPrice() == Expensivest_Station)

			CardEleven::SetPlayer(pGrid->GetPlayerWithLeastCoins());
	}
}

Card* CardTwelve::GetCopy() {
	return new CardTwelve(cardNumber);
}

void CardTwelve::Save(ofstream& outFile, ObjectType ObjType) {
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
	}
}

void CardTwelve::Load(ifstream& InFile) {
	Card::Load(InFile);
}

CardTwelve:: ~CardTwelve() {} // A Virtual Destructor

