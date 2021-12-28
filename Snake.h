#pragma once
#include"GameObject.h"
class Snake :public GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the Snake's "Start Cell Position"

	CellPosition endCellPos; // here is the Snake's End Cell Position
public:
	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut)const; // Draws a Snake going from the start cell to the end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of the Snake by moving player to the Snake's end cell

	void Save(ofstream& outFile, ObjectType ObjType); // Saves the start cell and the end cell of Snake in a file

	virtual void Load(ifstream& InFile); // Loads the start cell and the end cell of Snake from a file

	CellPosition GetEndPosition()const;

	virtual ~Snake();
};

