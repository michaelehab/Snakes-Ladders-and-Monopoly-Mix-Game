#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"


CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please select the card you want to copy");
	cardpos = pIn->GetCellClicked();
	if(cardpos.HCell() == -1)
	{
		pGrid->PrintErrorMessage("Please click on a valid cell, Click to continue...");
	}

	else if (pos.IsValidCell()) {
		copiedCard = pCell->HasCard()->GetCopy();
	}
	else {

void CopyCardAction::Execute()
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
		pGrid->SetClipboard(pCard);
		pOut->PrintMessage("Card Copied!");
	}
}

CopyCardAction::~CopyCardAction()
{
}