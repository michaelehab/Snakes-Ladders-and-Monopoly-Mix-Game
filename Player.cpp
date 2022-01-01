#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
	this->justRolledDiceNum = 0;
	this->pGrid = NULL;
	this->pGameObject = NULL;
	this->prevented = false;
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet >= 0)
		this->wallet = wallet;
	else
		wallet = 0;

}

void Player::PreventNextTurn(bool choice)
{
	prevented = choice;
}

bool Player::IsPrevented() const
{
	return prevented;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetPlayerNum() const
{
	return playerNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it) **
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{
	turnCount++;
	// If the player is prevented from moving he won't move this turn
	if (IsPrevented()) {
		pGrid->PrintErrorMessage("Player : " + to_string(GetPlayerNum()) + " is prevented from rolling this turn.");
		this->PreventNextTurn(false);
	}
	// If the player has money less than 1 he can't move
	else if (wallet < 1)
	{
		pGrid->PrintErrorMessage("Player: " + to_string(playerNum) + " Can't move for having money less than 1");
	}
	// If it's recharge turn the player won't move
	else if (turnCount == 3) {
		pGrid->PrintErrorMessage("It's wallet recharge turn for player " + to_string(GetPlayerNum()) + ". Click to continue...");
		turnCount = 0;
		wallet = 10 * diceNumber+wallet;
		return;
	}
	else {
		justRolledDiceNum = diceNumber;
		CellPosition pos = pCell->GetCellPosition();
		pos.AddCellNum(justRolledDiceNum);
		pGrid->UpdatePlayerCell(this, pos);

		pGameObject = pCell->GetGameObject();
		if (pCell->HasCard() || pCell->HasLadder() || pCell->HasSnake())
			pGameObject->Apply(pGrid, this);

		if (CellPosition::GetCellNumFromPosition(pCell->GetCellPosition()) == NumHorizontalCells * NumVerticalCells) pGrid->SetEndGame(true);
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

int Player::getJustRolledDiceNumber()const
{
	return justRolledDiceNum;
}
void Player::Reset()
{
	SetWallet(100);                     // Initial Values for turncount , wallet and Prevented
	this->turnCount = 0;
	PreventNextTurn(false);
}