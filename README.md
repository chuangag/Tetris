Tetris 
*************************

Authors
-------------------------
Gao Tong 

HUANG Chia-Hung 20309206

Description
-------------------------
This is a Tetris game. The goal of the game is to eliminate as many rows as possible and pursue for the higher level (max 10).
The game control is following:
arrow(up)
Start game
arrow(left)
Move block left
arrow(right)
Move block right
arrow(down)
Move block down
Z
Rotate block in clockwise direction
X
Rotate block in anti-clockwise direction

You can view your current score and level on the right side of the game board. The game board is formed by 10*20 grids. There are 7 types of piece, each has different shape but all contain 4 blocks. When They fill a row, the row will be eliminated.
 Also, the next piece will be shown on the right of the game board for reference.

Implementation
------------------------
Basically, we separate the game into 2 classes: MainWindow and GameBoard. 
MainWindow: It is the UI part of the game. The main function is to render the information from GameBoard with Qt when receiving changes or the Time signal. To achieve good OOP, we implement plenty of get functions so the variable can remain private.

GameBoard: It is the core of the game. We store the board in an 10*20 array with int 0-7. 0 means nothing in the block, 1 means type one, and so on. The different numbers between different type of blocks make rendering different color easier. What is special is we didn’t store the piece with array but a struct with an array of track and the position of the center. The using of track benefited our implementation a lot. Such as rotation become simple, and the checking loop of collision between blocks also simpler. There are also several signal in GameBoard such as changeScore() in order to update the UI.

Team Work
-------------------------
We use github for version control.
The main contribution done by:
GAO Tong: Come up the “track method” and implementation of the GameBoard and MainWindow. 
HUANG Chia-Hung: Design the overall classes and function and implementation of the MainWindow.


Others
------------------------
We found that there exists a bug in the example executable. When the landed blocks reach the top two row of the board, the next block will collide with the landed blocks and cover each other. However, refer to the requirement 8, this bug must happen. So we leaved it remain.



