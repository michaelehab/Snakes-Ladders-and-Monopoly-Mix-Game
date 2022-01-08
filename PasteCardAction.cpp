#include "PasteCardAction.h"
#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Card.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{

PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp) {
	pastedCard = NULL;
}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the cell to paste card.");
	cardPosition = pIn->GetCellClicked();

	if (pGrid->GetClipboard() == NULL) {
		pGrid->PrintErrorMessage("There is nothing in the clipboard to paste! Click to continue... ");
		pastedCard = NULL;
	}
void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();
	Card* pCard;
	pCard = pGrid->GetClipboard();
	if (!pCard)
	{
		pGrid->PrintErrorMessage("There is no copied card!");
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