#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos): Card(pos){
	cardNumber = 5;
}

Card* CardFive::GetCopy(const CellPosition& pos)
{
	return new CardFive(pos);
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	pPlayer->Move(pGrid, -pPlayer->getJustRolledDiceNumber());
}

void CardFive::Save(ofstream& outFile, ObjectType ObjType) {
	if (ObjType == Cards)
	{
		// Calling the parent class save function that saves the type and cell to the file
		Card::Save(outFile, ObjType);

	}
}


void CardFive::Load(ifstream& InFile) {
	Card::Load(InFile);
}

CardFive:: ~CardFive() {

}