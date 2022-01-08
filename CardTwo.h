#pragma once

#include "Card.h"
#include"Ladder.h"
// CardTwo :
// Moves the player forward to the start of the next ladder in the grid.
// If no ladders ahead, do nothing.
// Its Parameters: No Parameters

class CardTwo : public Card
{
	//No card parameters

public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position
	CardTwo(int cardNumber);
	virtual void ReadCardParameters(Grid* pGrid); // Reads nothing

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  // by moving him/her to the next ladder in the grid;

	virtual Card* GetCopy(const CellPosition&);

	void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function

	void Load(ifstream& InFile); // Overriding the Card Load member function

	virtual ~CardTwo(); // A Virtual Destructor
};

