#pragma once
#include "Action.h"
class CutCardAction : public Action
{
	CellPosition cardpos;
	Card* pCard;
public:
	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads  action parameters (cardNumber, cardPosition)

	virtual void Execute(); // copy a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~CutCardAction(); // A Virtual Destructor
};