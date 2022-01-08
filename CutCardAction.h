#pragma once
#include "Card.h"
#include "Action.h"
class CutCardAction:public Action
{
private:
	Card* cutCard;
public:
	CutCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CutCardAction();

};

