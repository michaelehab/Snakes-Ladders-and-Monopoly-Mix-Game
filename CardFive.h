#pragma once
#include"Card.h"
class CardFive :public Card
{
public:
	CardFive(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* GetCopy(const CellPosition&);

	void Save(ofstream& outFile, ObjectType ObjType);

	void Load(ifstream& InFile);

	virtual ~CardFive(); // A Virtual Destructor
};