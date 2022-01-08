#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"


CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please select the card you want to cut");
	cardpos = pIn->GetCellClicked();
	if (cardpos.HCell() == -1)
	{
		pGrid->PrintErrorMessage("Please click on a valid cell, Click to continue...");
	}
	else {

		pOut->PrintMessage("The clicked position is out of range. click to continue..");

	}

void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();
	pCard = pGrid->GetCardFromPosition(cardpos);
	if (pCard == NULL)
	{
		pOut->PrintMessage("There is no card here!");
	}
	else {
		pGrid->SetClipboard(pCard->GetCopy(cardpos));
		pGrid->RemoveObjectFromCell(cardpos);
		pOut->PrintMessage("Card Cut!");
	}
}

CutCardAction::~CutCardAction()
{
}