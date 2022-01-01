#pragma once
#include"Card.h"
class CardFive :public Card
{
public:
	CardFive(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void Save(ofstream& outFile, ObjectType ObjType);

	void Load(ifstream& InFile);

	virtual ~CardFive(); // A Virtual Destructor
};