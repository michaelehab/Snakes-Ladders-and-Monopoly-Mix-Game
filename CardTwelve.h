#pragma once
#include "Grid.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include <algorithm>
class CardTwelve:public Card
{
	//No parameters
public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position
	CardTwelve(int cardNumber);
	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual Card* GetCopy(const CellPosition&);

	void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function

	void Load(ifstream& InFile); // Overriding the Card Load member function

	virtual ~CardTwelve(); // A Virtual Destructor
};

