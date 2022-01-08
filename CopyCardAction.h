#pragma once
#include"Action.h"
#include"Card.h"
class CopyCardAction:public Action
{
private:
	Card* copiedCard;
public:
	CopyCardAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~CopyCardAction();


};

