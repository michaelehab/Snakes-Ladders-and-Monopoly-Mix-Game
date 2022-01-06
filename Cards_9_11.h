#pragma once
#include "Card.h"
class Cards_9_11 :public Card
{
	
public:
	Cards_9_11(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid,int &CardPrice,int& fees, Player* &p,bool &IsBought); // Reads the parameters of CardTen

	virtual void Apply(Grid* pGrid, Player* pPlayer, int& CardPrice, int& fees, Player*& p, bool& IsBought); // Applies the effect of CardTen on the passed Player

	virtual bool CheckInputValidity(int& CardPrice, int& fees);


	virtual void Save(ofstream& outFile, ObjectType ObjType,int& CardPrice, int& fees); // Overriding the Card Save member function

	virtual void Load(ifstream& InFile, int& CardPrice, int& fees); // Overriding the Card Load member function

	virtual ~Cards_9_11(); // A Virtual Destructor
};

