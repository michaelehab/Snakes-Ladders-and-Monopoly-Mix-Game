# Snakes & Ladders and Monopoly Mix Game - Fall 2021
This is an educational Project for Programming Techniques(OOP) course taken during fall 2021 semester.

In this project we made a simple game application that is a mixture between the Snakes &amp; Ladders and Monopoly games.

## Game Description
<ul>
  <li>There is four players moving in a grid having snakes, ladders, and Cards. </li>
  <li>The player goal is to get to the last cell before anyone else. </li>
  <li>He also takes advantage of the special cells to boost his game and obstruct his opponents. </li>
  <li>The game ends when a player reaches the last cell.</li>
</ul>

### There are two modes in the game:
<ol>
  <li>Design mode : Where the user is able to build the playing grid.</li>
  <li>Play mode : Where he plays the game itself. </li>
</ol>
In the Design mode, the player can add, copy, cut, paste, and delete any game object. He
can also save a grid and load a previously saved grid.

In the Play mode, the player is moving in a grid of 99 cells divided into rows and columns.
Each cell has a number from 1 to 99. They are divided to 9 rows and 11 columns.

Grid cells may contain:
<ol>
  <li>Ladder</li>
  <li>Snake</li>
  <li>Card making the cell a special cell</li>
</ol>

## Players
<ul>
  <li>The Game has four players.</li>
  <li>Each player has:
    <ul>
      <li>Steps’ count (initially step 0). This holds the value of the current cell the player is in.</li>
      <li>Wallet (initially contains 100 coins).The player can only move if there is at least 1 coin in his wallet. If he has zero or less coins, he must wait till his wallet is recharged with coins.</li>
    </ul>
  </li>
  <li>Players take turn rolling the dice, one after another.</li>
  <li>After a player rolls the dice, he moves from his n cell to n + t, where t is the result of rolling
the dice. For example, if the player gets 4 after rolling the dice and he is in cell 25, he
    moves to cell 29.</li>
  <li>Every 3 turns, a player dice roll is used to add money to his wallet instead of moving. A
    player gets 10*t coins (where t is the result of rolling the dice). For example:
    <ul>
      <li>The game starts and player 0 has 100 coins. He rolls the dice to get 5. He moves
to cell 5.</li>
      <li>In his next turn he gets 2 and moves to cell 7.</li>
      <li>In his third turn, he rolls the dice and gets 4. Then, 40 coins are added to his wallet,
        <b>and he will not move to cell 11.</b> This happens every three turns, i.e., turn 3, 6, 9,
... etc.</li>
    </ul>
  </li>
  <li>The player’s target in the game is to reach the last cell before any opponent reaches it.</li>
  <li>Winning Player : Is the first player to reach cell #100.</li>
</ul>
A Game cell contains players’ objects and game objects. It can hold multiple player objects, and at
most one game object.

A Game object is the fixed objects placed in the grid’s cells.
You cannot place game objects in the first or last cell.

## Game Objects:
<ol>
  <li>
    Ladders:
    <ul>
      <li>Ladders occupies exactly two cells, the start and end cells.</li>
      <li>If a player moves to the start cell, it will transfer him to the end cell.</li>
      <li>The start cell should be before the end cell in the grid.</li>
      <li>For simplicity, the start and end cell should be in the same column.</li>
      <li>The start cell cannot be a special cell (a card cell), nor a cell in the last row.</li>
      <li>Two ladders or more cannot overlap.</li>
      <li>The end cell of a ladder cannot be the start cell of another ladder or snake.</li>
    </ul>
  </li>
  <li>
    Snakes:
    <ul>
      <li>Snakes occupy exactly two cells, the start and end cells.</li>
      <li>If a player moves to the start cell, it will transfer him to the end cell.</li>
      <li>The start cell should be after the end cell in the grid.</li>
      <li>For simplicity, the start and end cell should be in the same column.</li>
      <li>The start cell cannot be a special cell (a card cell), nor a cell in the first row.</li>
      <li>Two snakes or more cannot overlap.</li>
      <li>The end cell of a snake cannot be the start cell of another ladder or snake.</li>
    </ul>
  </li>
  <li>
    Cards:
    <ul>
      <li>A card placed in a cell makes it a special cell.</li>
      <li>Each card instructs the player stopping at it to do a specific action.</li>
      <li>Any cell can’t have more than one card.</li>
      <li>A card can be placed only on an empty cell or at the end of a ladder or a snake. This
means that a card cannot be placed at the start cell of a ladder or a snake.</li>
    </ul>
  </li>
</ol>

## Cards:
<ul>
  <li>Card1:
    <ul>
      <li>Decrements the value of the passing player’s wallet by a value specified when creating the grid.</li>
      <li>Input data in design mode: i.Value to decrement</li>
    </ul>
  </li>
  <li>Card2:
    <ul>
      <li>Moves the player forward to the start of the next ladder in the grid.</li>
      <li>If no ladders ahead, do nothing.</li>
    </ul>
  </li>
  <li>Card3 and Card4:
    <ul>
      <li>Card3 gives the player an extra dice roll.</li>
      <li>Card4 prevents the player from rolling the next turn.</li>
      <li>Both the extra dice roll or the canceled dice roll count normally towards recharging the wallet turn (both increment the count of player turns).</li>
    </ul>
  </li>
  <li>Card5:
    <ul>
      <li>Moves the player backward with the same number of steps that he just rolled.</li>
      <li>If he reaches a ladder, a snake, or a card at the end of moving, take it.</li>
    </ul>
  </li>
  <li>Card6:
    <ul>
      <li>Instructs the player to go to a specific cell.</li>
      <li>If the destination cell contains a ladder, snake, or card, take it.</li>
      <li>Input data in design mode: i. Cell to move to</li>
    </ul>
  </li>
   <li>Card7:
    <ul>
      <li>Restarts the game for the first player whose cell is after the current player in the grid.</li>
      <li>Restarting the game for a player makes him go to cell number 1.</li>
    </ul>
  </li>
  <li>Card8:
    <ul>
      <li>This card is a prison.</li>
      <li>When a player stops at a Card8 cell, the player should choose either to pay specific amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.</li>
      <li>Input data in design mode: i. The amount of coins needed to go out of the prison</li>
    </ul>
  </li>
   <li>Cards [from 9 to 11]:
    <ul>
      <li>Gives the player the option to buy this cell and all cells containing a card with the same number. For example, if a player chooses to buy a cell with Card10, he will own all cells having a Card10.</li>
      <li>This cell is considered a station for a specific price.</li>
      <li>This specific price is deducted from the player’s wallet in case he chooses to buy the cell.</li>
      <li>Whenever another player stops at a cell owned by another player, he has to pay fees to the player who owns the cell.</li>
      <li>The price of the cell and the fees are taken as input during grid design.</li>
      <li>Input data in design mode is only taken if it is the first time to insert a card with the same number. For example, user will insert price and fees of Card10 only once.</li>
      <li>Input data in design mode: i. Card price ii. Fees to pay by passing players</li>
    </ul>
  </li>
  <li>Card12:
    <ul>
      <li>This card moves the ownership of the most expensive station that the current user owns from the current user to the player that has the least amount of coins in his wallet.</li>
  </li>
</ul>

#### Important Note: all the above cards are executed only if the current player stops at it (not passing on it on his way).

## Special Attacks:
<ul>
  <li>Each player has 4 special attacks that he can use throughout the game.</li>
  <li>A player can choose during his “recharge the wallet” turn to launch a special attack instead of recharging his wallet. (If he is not denied from rolling dice)
    <ul>
      <li>A message is shown, “Do you wish to launch a special attack instead of recharging? y/n”</li>
    </ul>
  </li>
  <li>Each player can use two unique special attacks at most throughout the game. This means a single player cannot use the same special attack twice.</li>
  <li>If a player chooses to launch a special attack, he is prompted to choose his special attack type.</li>
  <li>
  The 4 special attacks are:
    <ul>
      <li>Ice: Choose a player to prevent from rolling the next turn.</li>
      <li>Fire: Choose a player to burn. Deduct 20 coins from his wallet for his next 3 turns (total 60).</li>
      <li>Poison: Choose a player to poison. For 5 turns, deduct 1 number from his dice roll.</li>
      <li>Lightning: Deduct 20 coins from all other players.</li>
    </ul>
  </li>
</ul>

## Grid Sample (Design Mode)
![Grid Sample](https://github.com/michaelehab/Snakes-Ladders-and-Monopoly-Mix-Game/blob/Final/images/grid_sample.jpg)

## Game Sample (Play Mode)
![Game Sample](https://github.com/michaelehab/Snakes-Ladders-and-Monopoly-Mix-Game/blob/Final/images/game_sample.jpg)

## The Sample grid text file :
```
4
10 32
16 71
46 68
75 86
4
34 23
59 37
78 56
85 30
9
1 4 50
9 13 50 10
8 19 50
6 28 97
8 36 50
4 51 
9 54 50 10
9 81 50 10
1 84 50
```
