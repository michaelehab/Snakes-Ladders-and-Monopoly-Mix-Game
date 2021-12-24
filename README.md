# Snakes-Ladders-and-Monopoly-Mix-Game
A simple game application that is a mixture between the Snakes &amp; Ladders and Monopoly games.
## There are two modes in the game:
<ol>
  <li>Design mode : Where the user is able to build the playing grid.</li>
  <li>Play mode : Where he plays the game itself. </li>
</ol>

## The general idea of the game:
There is four players moving in a grid having snakes, ladders, and Cards. 
The player goal is to get to the last cell before anyone else. 
He also takes advantage of the special cells to boost his game and obstruct his opponents. 
The game ends when a player reaches the last cell.
## Game Description
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

### Players
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

### There are 3 types of Game Objects:
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
