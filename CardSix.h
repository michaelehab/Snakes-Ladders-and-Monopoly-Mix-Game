#pragma once
#include "Card.h"
class CardSix : public Card
{
	int CellNumToMoveTo;
public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix which is the cell to move the player to

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
													  //by instructing the player to move to a specific cell

	void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function

	virtual ~CardSix(); // A Virtual Destructor
};

