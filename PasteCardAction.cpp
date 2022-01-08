#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{

}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the destination cell");
	cardPosition = pIn->GetCellClicked();

}
void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	Card* pCard;
	pCard = pGrid->GetClipboard();
	if (!pCard)
	{
		pGrid->PrintErrorMessage("There is no copied card!");
		return;
	}
	Card* pnew_card;
	pnew_card = pCard->GetCopy(cardPosition);
	bool val = pGrid->AddObjectToCell(pnew_card);

	if (!val) pGrid->PrintErrorMessage("Error: There's already an object in this cell ! Click to continue ...");
	else {
		pnew_card->Draw(pGrid->GetOutput());
		pGrid->GetOutput()->PrintMessage("Card Pasted!");
	}
}
PasteCardAction::~PasteCardAction()
{

}