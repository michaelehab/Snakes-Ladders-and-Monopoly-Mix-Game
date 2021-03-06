#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos): Card(pos) {
	cardNumber = 12;
}

Card* CardTwelve::GetCopy(const CellPosition& pos)
{
	return new CardTwelve(pos);
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

void CardTwelve::Save(ofstream& outFile, ObjectType ObjType) {
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);
		// No Card Parameters here
		outFile << std::endl;
	}
}

void CardTwelve::Load(ifstream& InFile) {
	Card::Load(InFile);
}

CardTwelve:: ~CardTwelve() {} // A Virtual Destructor

