#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player.
	Grid* pGrid;		   // 
	GameObject *pGameObject;
	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1) 
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells 
	int wallet;		       // player's wallet (how many coins he has -- integer) 
	int justRolledDiceNum; // the current dice number which is just rolled by the player 
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll 
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet

	bool prevented;		   // indicates that the player is prevented from rolling the next turn.
	int turnsInPrison;	   // the number of turns the player spent in prison
	
	bool burned;		   // indicates that the player is burned by another player
	int burnedTurns;	   // the number of turns the player spent burned
	bool poisoned;		   // indicates that the player is poisoned by another player
	int poisonedTurns;	   // the number of turns the player spent poisoned

	int specialAttacksUsed; // the number of special attacks the player already used (MAX 2)
	bool usedFire;			// indicates that the player used his fire special attack
	bool usedIce;			// indicates that the player used his ice special attack
	bool usedPoison;		// indicates that the player used his poison special attack
	bool usedLightning;		// indicates that the player used his lightning special attack
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	void SetTurnCount(int count);	// A setter for the turnCount
	int GetTurnCount() const;		// A getter for the turnCount
	int GetPlayerNum() const;       // A getter for the playerNum

	int getJustRolledDiceNumber() const; //To get the justrolleddicenumber of the current player
	int GetNextPlayer(int &MinCellNum, int currentCellNum,int i,int NextPlayerIndex); //gets the next player index and sends it back to the grid


	void PreventNextTurn(bool choice); // Prevents the player from rolling the next turn
	bool IsPrevented() const; // Determines if the player is prevented
	void PutInPrison(); // Puts the player in prison for 3 turns
	bool IsInPrison() const; // Checks if the player is already in prison
	void GetOutOfPrison(); // Gets the player out of prison

	bool Pay(int amount); // Makes the player pay an amount of money

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)
													   
	// ====== Special Attack Functions =====
	void UseIceSpecialAttack(Player* p, Output* pOut);		// Makes the player use his ice special attack (if possible)
	void UseFireSpecialAttack(Player* p, Output* pOut);	// Makes the player use his fire special attack (if possible)
	void UsePoisonSpecialAttack(Player* p, Output* pOut);	// Makes the player use his poison special attack (if possible)
	void UseLightningSpecialAttack(Output* pOut, Grid* pGrid);	// Makes the player use his lightning special attack (if possible)
	void LaunchSpecialAttack(int type, Grid* pGrid); // Gets the suitable input to launch a special attack
	void Reset(); // Resets the player data members to the default ones

};

