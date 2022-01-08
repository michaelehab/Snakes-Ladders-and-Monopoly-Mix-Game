#pragma once
#include"Card.h"
class CardFive :public Card
{
	//No parameters
public:
	CardFive(const CellPosition& pos);
	CardFive(int cardNumber);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	Card* GetCopy();
	void Save(ofstream& outFile, ObjectType ObjType);

	void Load(ifstream& InFile);

	virtual ~CardFive(); // A Virtual Destructor
};