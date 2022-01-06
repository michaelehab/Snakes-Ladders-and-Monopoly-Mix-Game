#pragma once
#include "Cards_9_11.h"
class CardEleven : public Cards_9_11
{
	static int CardPrice;            //the price of the card
	static int fees;                 // the fees that the player pay  
	static Player* p;                //a pointer to the player that will buy the card
	static bool IsBought;            //indicates whether this station is bought or not
public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTen

	void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player

	bool CheckInputValidity();


	void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function

	void Load(ifstream& InFile); // Overriding the Card Load member function


	static Player* GetPlayer();

	static int GetCardPrice();

	static void SetPlayer(Player* player);

	virtual ~CardEleven(); // A Virtual Destructor
};


