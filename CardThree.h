#pragma once
#include "Card.h"

// CardThree :
// Gives the player another dice roll.
// Its Parameters: this card has no parameters to read

class CardThree : public Card
{
	//No card parameters

public:
	CardThree(const CellPosition&); // A Constructor takes card position
	CardThree(int cardNumber);
	virtual void ReadCardParameters(Grid*); // Reads nothing

	virtual void Apply(Grid*, Player*); //Applies the effect of CardThree on passed player
										//by giving passed player another dice roll  

	Card* GetCopy();
	virtual void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function 

	virtual void Load(ifstream& InFile); // Overriding the Card Load member function

	virtual ~CardThree(); // A Virtual Destructor
};
