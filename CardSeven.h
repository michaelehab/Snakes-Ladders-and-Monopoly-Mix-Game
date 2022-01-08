#pragma once
#include "Card.h"
class CardSeven : public Card
{
public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSeven

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSeven on the passed Player

	virtual Card* GetCopy(const CellPosition&);

	void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function

	void Load(ifstream& InFile); // Overriding the Card Load member function

	virtual ~CardSeven(); // A Virtual Destructor
};

