#pragma once

#include "GameObject.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position

public:
	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of the ladder by moving player to ladder's end cell

	virtual void Save(ofstream& outFile, ObjectType ObjType); // Saves the start cell and the end cell of Ladder in a file

	virtual void Load(ifstream& InFile); // Loads the start cell and the end cell of Ladder from a file

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Ladder(); // Virtual destructor
};

