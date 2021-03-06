#pragma once
#include "Card.h"

// CardEight :
// This card is a prison.
// When a player stops at a Card8 cell, the player should choose either to pay specific 
// amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.
// Its Parameters: The amount of coins needed to go out of the prison

class CardEight : public Card
{
	int amount;

public:
	CardEight(const CellPosition&); // A Constructor takes card position

	virtual void ReadCardParameters(Grid*); // Reads the amount of coins needed to go out of the prison

	virtual bool CheckInputValidity(); // Checks if the input taken is valid

	virtual void Apply(Grid*, Player*); //Applies the effect of CardEight on passed player

	virtual Card* GetCopy(const CellPosition&);

	virtual void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function 

	virtual void Load(ifstream& InFile); // Overriding the Card Load member function

	virtual ~CardEight(); // A Virtual Destructor
};
