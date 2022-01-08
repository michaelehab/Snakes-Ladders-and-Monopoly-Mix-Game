#include "CopyCardAction.h"
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

CopyCardAction::CopyCardAction(ApplicationManager* pApp): Action(pApp) 
{
	copiedCard = NULL;
}


void CopyCardAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please select the card that you want to copy ");

	CellPosition pos = pIn->GetCellClicked();
	Cell* pCell = pGrid->GetCellFromCellPosition(pos);
	if (!pCell->HasCard()) {
		pGrid->PrintErrorMessage("The selected cell has no card! Click to continue...  ");
		
	}

	else if (pos.IsValidCell()) {
		copiedCard = pCell->HasCard()->GetCopy();
	}
	else {

		pOut->PrintMessage("The clicked position is out of range, click to continue..");
	
	}

	pOut->ClearStatusBar();
}

void CopyCardAction::Execute() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	ReadActionParameters();
	if (copiedCard == NULL)
		return;

	pGrid->SetClipboard(copiedCard);
	pOut->PrintMessage("Card " + to_string(copiedCard->GetCardNumber()) + " Copied to the clipboard. Click to continue...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

CopyCardAction::~CopyCardAction() {
	delete copiedCard;
}