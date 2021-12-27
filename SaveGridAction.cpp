#include "SaveGridAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter the file name, then press ENTER");
	FileName = pIn->getString(pOut);
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	ofstream OutFile(FileName + ".txt");
	/*
		The outFile Format :
		Number_of_Ladders(n1)
		Ladder_1_start_cell Ladder_1_end_cell
		Ladder_2_start_cell Ladder_2_end_cell
		.................................................................
		Ladder_n1_start_cell Ladder_n1_end_cell
		Number_of_Snakes(n2)
		Snake_1_start_cell Snake_1_end_cell
		Snake_2_start_cell Snake_2_end_cell
		.................................................................
		Snake_n2_start_cell Snake_n2_end_cell
		Number_of_Cards(n3)
		Card_1_type Card_1_Cell Card_1_parameter_1(if any)
		.................................................................
		Card_n3_type Card_n3_Cell Card_n3_parameter_1(if any)
	*/

	OutFile << pGrid->GetNumberOfObjects(Ladders) << std::endl;
	pGrid->SaveAll(OutFile, Ladders);

	OutFile << pGrid->GetNumberOfObjects(Snakes) << std::endl;
	pGrid->SaveAll(OutFile, Snakes);

	OutFile << pGrid->GetNumberOfObjects(Cards) << std::endl;
	pGrid->SaveAll(OutFile, Cards);

	OutFile.close();
}