#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "Player.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

bool Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		if (CellList[pos.VCell()][pos.HCell()]->GetGameObject() != NULL) {
			// Delete the existing game object
			delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();
			// Points to NULL to show that the cell is now empty
			CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
			return true; // indicating that removal is done
		}
	}
	return false; // if not a valid position
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	Clipboard = pCard;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

bool Grid::SetCurrentPlayer(int p) {
	if (p < 0 || p >= MaxPlayerCount) return false; // if the player number is invalid
	else currPlayerNumber = p;
	return true;
}


// ========= Other Getters =========

Player* Grid::GetPlayerWithLeastCoins() const {
	Player* playerminCoins = PlayerList[0];

	for (int i = 1; i < MaxPlayerCount; i++)

		if (PlayerList[i]->GetWallet() < playerminCoins->GetWallet())

			playerminCoins = PlayerList[i];

	return playerminCoins;
}

Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Card* Grid::GetCardFromPosition(const CellPosition& position)
{
	if (CellList[position.VCell()][position.HCell()]->HasCard())
		return CellList[position.VCell()][position.HCell()]->HasCard();
	return NULL;
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasLadder() != NULL) return CellList[i][j]->HasLadder();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
void Grid::GetNextPlayer(Player* currentPlayer,Player* NextPlayers[])
{
	CellPosition* currentCellPosition;
	//Gets the cell number of the current player 
	int currentCellNum = currentCellPosition->GetCellNumFromPosition((currentPlayer->GetCell())->GetCellPosition());
	int NextPlayerIndex[4] = { -1,-1,-1,-1 };   //the index of the next players in front of the current player
	int Index = 0;                              //the index of NextPlayerIndex
	int MinCellNum = 1000;                      //the cell number of the player directly after the current player 
	for (int i = 0; i < MaxPlayerCount; i++)
		if (currentPlayer != PlayerList[i])
		{
			NextPlayerIndex[0] = PlayerList[i]->GetNextPlayer(MinCellNum, currentCellNum, i, NextPlayerIndex[0]);
		}
	CellPosition* CellNum;
	//Loops on the Playerlist to get all the players that are at the same cell directly after the current player`s cell 
	for (int i = 0; i < MaxPlayerCount; i++)
		if (CellNum->GetCellNumFromPosition((PlayerList[i]->GetCell())->GetCellPosition()) == MinCellNum && NextPlayerIndex[0] != -1)
		{
			Index++;
			NextPlayerIndex[Index] = i; //sets NextPlayerIndex with the indexs of all the Players that are at the same cell directly after the current player`s cell 
		}
	//sets the NextPlayers pointer array with all the Players that are at the same cell directly after the current player`s cell 
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (NextPlayerIndex[i] != -1)
	
			NextPlayers[i]= PlayerList[NextPlayerIndex[i]];
		else
			NextPlayers[i] = NULL;  
	}
	
}

void Grid::ClearGrid() {
	for (int i = 0; i < NumVerticalCells; ++i) {
		for (int j = 0; j < NumHorizontalCells; ++j) {
			RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
		}
	}
}

void Grid::ResetGrid() {
	// Returns to the first player
	SetCurrentPlayer(0);
	// Changing the clipboard back to NULL
	SetClipboard(NULL);
	// Changing the endgame back to false
	SetEndGame(false);
}

Player* Grid::GetPlayerByPlayerNum(int num) {
	return PlayerList[num];
}

int Grid::GetNumberOfObjects(ObjectType ObjType) {
	int count = 0;

	for (int i = NumVerticalCells - 1; i >= 0; i--) {
		for (int j = 0; j < NumHorizontalCells; j++) {
			switch (ObjType) {
			case Ladders:
				if (CellList[i][j]->HasLadder()) count++;
				break;

			case Snakes:
				if (CellList[i][j]->HasSnake()) count++;
				break;

			case Cards:
				if (CellList[i][j]->HasCard()) count++;
				break;
			}
		}
	}
	// The total number of the passed object type
	return count;
}

Cell* Grid::GetCellFromCellPosition(const CellPosition& position) const {
	Cell cell(position);
	for (int i = 0; i < NumVerticalCells; i++) {
		for (int j = 0; j < NumHorizontalCells; j++) {
			if (CellList[i][j]->GetCellPosition().HCell() == cell.GetCellPosition().HCell() && CellList[i][j]->GetCellPosition().VCell() == cell.GetCellPosition().VCell())
			{
				return CellList[i][j];
			}
		}
	}
	return NULL;
}

bool Grid::thisColumnHasLadder(const CellPosition& startPos, const CellPosition& endPos) const {
	for (int i = startPos.VCell(); i > endPos.VCell(); i--) {
		if (dynamic_cast<Ladder*>(CellList[i][startPos.HCell()]->GetGameObject()) != NULL)
			return true;
	}
	return false;
}


bool Grid::thisColumnHasSnake(const CellPosition& startPos, const CellPosition& endPos) const {
	for (int i = startPos.VCell(); i < endPos.VCell(); i++) {
		if (dynamic_cast<Snake*>(CellList[i][startPos.HCell()]->GetGameObject()) != NULL)
			return true;
	}
	return false;
}

// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | P" + to_string(currPlayerNumber) + "'s Turn";

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::SaveAll(ofstream& outFile, ObjectType ObjType) {
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->GetGameObject()) CellList[i][j]->GetGameObject()->Save(outFile, ObjType);
		}
	}

}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}