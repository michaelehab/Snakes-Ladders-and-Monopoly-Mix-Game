#include "AddCardAction.h"
#include "CardTwo.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardSix.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardSeven.h"
AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Please enter a card number between 1 and 12 ");
	cardNumber = pIn->GetInteger(pOut);
	if (cardNumber > 0 && cardNumber < 13)
	{
		CellPosition position;
		// 3- Read the "cardPosition" parameter (its cell position) and set its data member
		pOut->PrintMessage("Please choose a cell to insert the card");
		position = pIn->GetCellClicked();
		// 4- Make the needed validations on the read parameters
		bool isValid = position.IsValidCell();
		if (isValid)
		{
			cardPosition = position;     //if the card position is valid
		}
		else
		{
			//if the card position is not valid (by default the cardposition is constructed with hcell= -1 and vcell= -1)
			int x, y;
			pOut->PrintMessage("The clicked position is out of range, click to continue..");
			pIn->GetPointClicked(x, y);

		}
	}
	else
	{
		//if the user entered invalid card number
		int x, y;
		cardNumber = -1;
		pOut->PrintMessage("You entered invalid card number, Click to continue..");
		pIn->GetPointClicked(x, y);


	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL;  // will point to the card object type
	if (cardPosition.IsValidCell())   //if cardposition is valid position
	{
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
			// A- Add the remaining cases
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			break;
		case 10:
			pCard = new CardTen(cardPosition);
			break;
		case 11:
			pCard = new CardEleven(cardPosition);
			break;
			

		}
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
