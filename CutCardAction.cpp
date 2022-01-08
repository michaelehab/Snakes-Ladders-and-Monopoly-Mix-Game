#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include"CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	cutCard = NULL;
}


void CutCardAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please select the card that you want to cut ");

	CellPosition pos = pIn->GetCellClicked();
	Cell* pCell = pGrid->GetCellFromCellPosition(pos);
	if (!pCell->HasCard()) {
		pGrid->PrintErrorMessage("The selected cell has no card! Click to continue...  ");

	}

	else if (pos.IsValidCell()) {
		cutCard = pCell->HasCard()->GetCopy();
	}
	else {

		pOut->PrintMessage("The clicked position is out of range. click to continue..");

	}

	pOut->ClearStatusBar();
}

void CutCardAction::Execute() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();
	if (cutCard == NULL)
		return;

	pGrid->SetClipboard(cutCard);
	pGrid->RemoveObjectFromCell(cutCard->GetPosition());
	pOut->PrintMessage("Card " + to_string(cutCard->GetCardNumber()) + " is cut to the clipboard. Click to continue...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

CutCardAction::~CutCardAction() {
	delete cutCard;
}