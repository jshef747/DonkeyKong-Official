//
//
//// Include necessary headers
//#include <iostream>
//#include <windows.h>
//#include <conio.h>
//#include "gameConfig.h"
//#include "player.h"
//#include "boardGame.h"
//#include "barrel.h"
//
//// Define the escape key constant
//constexpr int ESC = 27;
//
//// Function declarations
//void initializeGame(player& mario, boardGame& board);
//void handleInput(player& mario, bool& running);
//void updateBarrels(boardGame& board, int& barrelCounter, int numBarrels, int iterationCounter);
//void gameLoop(player& mario, boardGame& board);
//
//// Main function
//int main()
//{
//    // Create game objects
//    player mario;
//    boardGame board;
//
//    // Initialize the game
//    initializeGame(mario, board);
//
//    // Start the game loop
//    gameLoop(mario, board);
//
//    // Move cursor to the bottom of the console
//    gotoxy(0, 27);
//    return 0;
//}
//
//// Function to initialize the game
//void initializeGame(player& mario, boardGame& board)
//{
//    // Hide the cursor in the console
//    showCurserOnConsole(false);
//
//    // Set the game board for the player
//    mario.setGameBoard(&board);
//
//    // Draw the initial game board
//    board.newDrawBoard();
//}
//
//// Function to handle user input
//void handleInput(player& mario, bool& running)
//{
//    // Check if a key has been pressed
//    if (_kbhit())
//    {
//        // Get the pressed key
//        char key = _getch();
//
//        // If the escape key is pressed, stop the game
//        if (key == ESC)
//            running = false;
//        else
//            // Otherwise, handle the key press for the player
//            mario.keyPressed(key);
//    }
//}
//
//// Function to update the barrels
//void updateBarrels(boardGame& board, int& barrelCounter, int numBarrels, int iterationCounter)
//{
//    // Update and draw each active barrel
//    for (int i = 0; i < barrelCounter; i++)
//    {
//        barrel* pBarrel = &board.getBarrel(i);
//        if (board.getBarrel(i).isActive()){
//        pBarrel->erase();
//        pBarrel->barrelFall();
//        pBarrel->draw(); 
//        }
//        else {
//            if (pBarrel->isBlastShowing())
//                if (pBarrel->getBlowCount() ==2) {//get blow count counts iterations before clearing explosion
//                    pBarrel->clearBlast();
//                }
//                else {
//                    pBarrel->updateBlowCounter();
//                }
//            
//        }
//    }
//
//    // Add a new barrel every 60 iterations
//    if (iterationCounter % 20 == 0 && barrelCounter < numBarrels)
//    {
//        barrel* pBarrel = &board.getBarrel(barrelCounter);
//        pBarrel->setBoard(&board);
//        pBarrel->draw();
//        barrelCounter++;
//    }
//}
//
//// Function containing the main game loop
//void gameLoop(player& mario, boardGame& board)
//{
//    int iterationCounter = 0;
//    int barrelCounter = 0;
//    const int numBarrels = board.getBarrelsNum();
//    bool running = true;
//
//    // Main game loop
//    while (running)
//    {
//        // Draw the player
//        mario.draw();
//
//        // Handle user input
//        handleInput(mario, running);
//
//        // Update the barrels
//        updateBarrels(board, barrelCounter, numBarrels, iterationCounter);
//
//        // Sleep for a short duration to control game speed
//        Sleep(100);
//        iterationCounter++;
//
//        // Erase the player and update its position
//        mario.erase();
//        mario.moveInBoard();
//    }
//}



#include "game.h"

int main()
{
	game g;
	g.runGame();
	return 0;
}