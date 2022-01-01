#pragma once
#include "Card.h"

// CardFour :
// Prevents the player from rolling the next turn.
// Its Parameters: this card has no parameters to read

class CardFour : public Card
{
	//No card parameters

public:
	CardFour(const CellPosition&); // A Constructor takes card position

	virtual void ReadCardParameters(Grid*); // Reads nothing

	virtual void Apply(Grid*, Player*); //Applies the effect of CardFour on passed player
										//by preventing the player from rolling next turn 

	virtual void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function 

	virtual void Load(ifstream& InFile); // Overriding the Card Load member function

	virtual ~CardFour(); // A Virtual Destructor
};
