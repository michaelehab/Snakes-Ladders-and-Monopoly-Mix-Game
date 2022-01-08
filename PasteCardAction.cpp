#include "PasteCardAction.h"
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


PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp) {
	pastedCard = NULL;
}

void PasteCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (pGrid->GetClipboard() == NULL) {
		pGrid->PrintErrorMessage("There is nothing in the clipboard to paste! Click to continue... ");
		pastedCard = NULL;
	}
	else {
			pastedCard = pGrid->GetClipboard();
	}

}

void PasteCardAction::Execute() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();

	if (pastedCard == NULL)
		return;

	pOut->PrintMessage("Click on the destination cell of the card ");

	CellPosition cardPosition = pIn->GetCellClicked();

	pOut->ClearStatusBar();

	Cell* pCell = pGrid->GetCellFromCellPosition(cardPosition);

	int cardNumber = pastedCard->GetCardNumber();

	if (cardPosition.IsValidCell()) {
		if (pCell->GetGameObject() == NULL) {
			

			if(pGrid->AddObjectToCell(pastedCard))
			pOut->PrintMessage("The card has been pasted to the selected cell. Click to continue... ");
			
			pIn->GetCellClicked();
			pOut->ClearStatusBar();
		}
		else {
			pGrid->PrintErrorMessage("The selected cell has a game object! Click to continue...");
			 
		}
	}
	else {
			pGrid->PrintErrorMessage("The selected cell is not valid! Click to continue...");

	}

}

PasteCardAction::~PasteCardAction() {

}