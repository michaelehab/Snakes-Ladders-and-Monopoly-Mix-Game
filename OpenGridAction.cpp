#include "OpenGridAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
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
#include <fstream>

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

OpenGridAction::~OpenGridAction()
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please Enter the name of the saved file, and press ENTER.");
	FileName = pIn->getString(pOut);
	pOut->ClearStatusBar();
}

void OpenGridAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();

	ifstream InFile(FileName + ".txt");

	if (!InFile) {
		pGrid->PrintErrorMessage("ERROR: The file name you entered does not exist, Click to continue ... ");
		return;
	}

	int number_of_ladders;
	InFile >> number_of_ladders;
	GameObject* pNewObject;

	for (int i = 0; i < number_of_ladders; i++)
	{
		pNewObject = new Ladder(0, 0); // The startCellPos and endCellPos will be changed with each ladder in the file
		pNewObject->Load(InFile);
		pGrid->AddObjectToCell(pNewObject);
	}

	int number_of_snakes;
	InFile >> number_of_snakes;
	for (int i = 0; i < number_of_snakes; i++)
	{
		pNewObject = new Snake(0, 0); // The startCellPos and endCellPos will be changed with each snake in the file
		pNewObject->Load(InFile);
		pGrid->AddObjectToCell(pNewObject);
	}

	int number_of_cards;
	InFile >> number_of_cards;
	for (int i = 0; i < number_of_cards; i++)
	{
		int CardNumber;
		InFile >> CardNumber;
		switch (CardNumber)
		{
		case 1:
			pNewObject = new CardOne(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 2:
			pNewObject = new CardTwo(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 3:
			pNewObject = new CardThree(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 4:
			pNewObject = new CardFour(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 5:
			pNewObject = new CardFive(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 6:
			pNewObject = new CardSix(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 7:
			pNewObject = new CardSeven(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 8:
			pNewObject = new CardEight(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 9:
			pNewObject = new CardNine(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 10:
			pNewObject = new CardTen(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 11:
			pNewObject = new CardEleven(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		case 12:
			pNewObject = new CardTwelve(0); // The Card Position will be changed with each card in the file
			pNewObject->Load(InFile);
			pGrid->AddObjectToCell(pNewObject);
			break;
		}
	}

	InFile.close();
}