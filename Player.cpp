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
	this->turnsInPrison = -1;
	this->specialAttacksUsed = 0;
	this->burned = false;
	this->burnedTurns = 0;
	this->poisoned = false;
	this->poisonedTurns = 0;
	this->usedFire = false;
	this->usedIce = false;
	this->usedPoison = false;
	this->usedLightning = false;
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

void Player::PutInPrison()
{
	prevented = true;
	turnsInPrison = 1;
}

bool Player::IsInPrison() const
{
	if (IsPrevented() && turnsInPrison != -1) return true;
	return false;
}

void Player::GetOutOfPrison() {
	prevented = false;
	turnsInPrison = -1;
}

bool Player::Pay(int amount) {
	if (amount > wallet) return false;

	this->SetWallet(GetWallet() - amount);
	return true;
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
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if(!IsInPrison()) turnCount++;
	if (this->burned) {
		this->Pay(20);
		burnedTurns++;
		if (burnedTurns == 3)
		{
			burned = false;
			burnedTurns = 0;
		}
	}
	if (this->poisoned) {
		diceNumber--;
		poisonedTurns++;
		if (poisonedTurns == 5)
		{
			poisoned = false;
			poisonedTurns = 0;
		}
	}
	if (IsInPrison()) {
		pOut->PrintMessage("Player : " + to_string(GetPlayerNum()) + " is in prison.");
		turnsInPrison++;
		if (turnsInPrison == 4) {
			pOut->PrintMessage("Player : " + to_string(GetPlayerNum()) + " is now out of prison.");
			this->GetOutOfPrison();
		}
	}
	// If the player is prevented from moving he won't move this turn
	else if (IsPrevented()) {
		pOut->PrintMessage("Player : " + to_string(GetPlayerNum()) + " is prevented from rolling this turn.");
		this->PreventNextTurn(false);
	}
	// If the player has money less than 1 he can't move
	else if (wallet < 1) {
		pGrid->PrintErrorMessage("Player: " + to_string(playerNum) + " Can't move for having money less than 1, Click to continue...");
	}
	// If it's recharge turn the player won't move
	else if (turnCount % 3 == 0 && turnCount != 0) {
		pGrid->PrintErrorMessage("It's wallet recharge turn for player " + to_string(GetPlayerNum()) + ". Click to continue...");
		if (specialAttacksUsed < 3) {
			pOut->PrintMessage("Do You Wish To Launch A Special Attack Instead Of Recharging ? y/n");
			string choice = pIn->getString(pOut);

			if (tolower(choice[0]) == 'y'){
				string msg = "Choose one of the following available attacks : ";

				if (!usedIce) msg += "  1-Ice";
				if (!usedFire) msg += "  2-Fire";
				if (!usedPoison) msg += "  3-Poison";
				if (!usedLightning) msg += "  4-Lightning";

				pOut->PrintMessage(msg);
				int attack = pIn->GetInteger(pOut);
				while (attack < 0 || attack > 5) {
					pOut->PrintMessage(msg);
				}
				LaunchSpecialAttack(attack, pGrid);
			}
			else {
				wallet = 10 * diceNumber + wallet;
				pOut->PrintMessage("Player: " + to_string(playerNum) + " Increased Money By: " + to_string(diceNumber * 10));
			}
		}
		else {
			wallet = 10 * diceNumber + wallet;
			pOut->PrintMessage("Player: " + to_string(playerNum) + " Increased Money By: " + to_string(diceNumber * 10));
		}
	}
	else {
		justRolledDiceNum = diceNumber;
		CellPosition pos = pCell->GetCellPosition();
		pos.AddCellNum(justRolledDiceNum);
		pGrid->UpdatePlayerCell(this, pos);

		pGameObject = pCell->GetGameObject();
		if (pCell->HasCard() || pCell->HasLadder() || pCell->HasSnake()) 
			pGameObject->Apply(pGrid, this);

		if (CellPosition::GetCellNumFromPosition(pCell->GetCellPosition()) == NumHorizontalCells * NumVerticalCells) {
			pGrid->SetEndGame(true);
			pOut->PrintMessage("Game Over! Player : " + to_string(GetPlayerNum()) + " Won!");
		}
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + "$, ";
	playersInfo += to_string(turnCount) + ", ";
	if(this->IsInPrison()) playersInfo += "Prison, ";
	if(this->IsPrevented() && !this->IsInPrison()) playersInfo += "Prevented, ";
	if(this->burned) playersInfo += "Fire, ";
	if (this->poisoned) playersInfo += "Poison, ";
	playersInfo += to_string(2 - specialAttacksUsed) + ")";
}

int Player::getJustRolledDiceNumber()const
{
	return justRolledDiceNum;
}
void Player::Reset()
{
	SetWallet(100);                     // Initial Values for turncount , wallet and Prevented
	this->turnCount = 0;
	prevented = false;
	specialAttacksUsed = 0;
	burned = false;
	poisoned = false;
}

void Player::UseIceSpecialAttack(Player * p, Output * pOut)
{
	if (specialAttacksUsed < 2 && !usedIce) {
		p->prevented = true;
		pOut->PrintMessage("Player: " + to_string(p->GetPlayerNum()) + " is now Frozen by player : " + to_string(this->GetPlayerNum()));
		usedIce = true;
		specialAttacksUsed++;
	}
	else {
		pOut->PrintMessage("Player : " + to_string(this->GetPlayerNum()) + " used all his special attacks!");
	}
}

void Player::UseFireSpecialAttack(Player* p, Output* pOut)
{
	if (specialAttacksUsed < 2 && !usedFire) {
		p->burned = true;
		pOut->PrintMessage("Player: " + to_string(p->GetPlayerNum()) + " is now burned by player : " + to_string(this->GetPlayerNum()));
		usedFire = true;
		specialAttacksUsed++;
	}
	else {
		pOut->PrintMessage("Player : " + to_string(this->GetPlayerNum()) + " used all his special attacks, Click to continue...");
	}
}

void Player::UsePoisonSpecialAttack(Player* p, Output* pOut)
{
	if (specialAttacksUsed < 2 && !usedPoison) {
		p->poisoned = true;
		pOut->PrintMessage("Player: " + to_string(p->GetPlayerNum()) + " is now poisoned by player : " + to_string(this->GetPlayerNum()));
		usedPoison = true;
		specialAttacksUsed++;
	}
	else {
		pOut->PrintMessage("Player : " + to_string(this->GetPlayerNum()) + " used all his special attacks, Click to continue...");
	}
}

void Player::UseLightningSpecialAttack(Output* pOut, Grid * pGrid)
{
	if (specialAttacksUsed < 2 && !usedLightning) {
		string msg = "Players : ";
		for (int i = 0; i < MaxPlayerCount; i++) {
			if (i != playerNum) {
				pGrid->GetPlayerByPlayerNum(i)->Pay(20);
				msg += to_string(i) + ", ";
			}
		}
		pOut->PrintMessage(msg + "lost 20 coins!");
		specialAttacksUsed++;
	}
	else {
		pOut->PrintMessage("Player : " + to_string(this->GetPlayerNum()) + " used all his special attacks, Click to continue...");
	}

}

void Player::LaunchSpecialAttack(int type, Grid* pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (type == 4) {
		UseLightningSpecialAttack(pOut, pGrid);
	}
	else {
		string msg = "Choose one of the following players to attack : ";
		for (int i = 0; i < MaxPlayerCount; i++) {
			if (i != playerNum) msg += to_string(i);
		}
		pOut->PrintMessage(msg);
		int num = pIn->GetInteger(pOut);
		while (num < 0 || num > 3 || num == playerNum)
		{
			pOut->PrintMessage(msg);
			num = pIn->GetInteger(pOut);
		}
		Player* p = pGrid->GetPlayerByPlayerNum(num);
		if (type == 1) {
			// Getting a valid player number
			num = pIn->GetInteger(pOut);
			while (num < 0 || num > 3 || num == playerNum)
			{
				pOut->PrintMessage(msg);
				num = pIn->GetInteger(pOut);
			}
			// Making sure that the player is not already frozen
			while (p->IsPrevented()) {
				p = pGrid->GetPlayerByPlayerNum(num);
				pOut->PrintMessage("Player: " + to_string(p->GetPlayerNum()) + " Is Already Frozen! Try another player");
				num = pIn->GetInteger(pOut);
			}
			UseIceSpecialAttack(p, pOut);
		}
		else if (type == 2) UseFireSpecialAttack(p, pOut);
		else if (type == 3) UsePoisonSpecialAttack(p, pOut);
		else pOut->PrintMessage("The Attack type is invalid!");
	}
}