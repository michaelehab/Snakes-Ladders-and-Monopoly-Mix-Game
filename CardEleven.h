#pragma once
#include "Card.h"
class CardEleven : public Card
{
		static int CardPrice;            //the price of the card
		static int fees;                 // the fees that the player pay  
		static Player* p;                //a pointer to the player that will buy the card
		static bool IsBought;            //indicates whether this station is bought or not
	public:
		CardEleven(const CellPosition& pos); // A Constructor takes card position

		virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven

		virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player
		
		virtual bool CheckInputValidity();

		void Save(ofstream& outFile, ObjectType ObjType); // Overriding the Card Save member function

		void Load(ifstream& InFile); // Overriding the Card Load member function

		virtual ~CardEleven(); // A Virtual Destructor

};

