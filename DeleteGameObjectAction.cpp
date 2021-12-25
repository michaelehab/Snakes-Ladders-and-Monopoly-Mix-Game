#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please click on the cell to delete its game object");
	cellPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	bool deleted = pGrid->RemoveObjectFromCell(cellPosition);
	if (!deleted) pGrid->PrintErrorMessage("Error: The cell you clicked is already empty ! Click to continue ...");
}
