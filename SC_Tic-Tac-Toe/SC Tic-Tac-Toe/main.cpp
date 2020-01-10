//
//  main.cpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#include <iostream>
#include "MenuH.h"
#include "GridH.h"
#include "MenuItemH.h"

// Using statement that allows me to use the streams/keywords in the
// std:: namespace without needing the std:: prefix
using namespace std;

//
// Checks to see if any player could have won. Returns true is so, and false if not.
//
bool checkVictory(Grid g)
{
    return ((g.getBlank1() == g.getBlank2() && g.getBlank2() == g.getBlank3() && (g.getBlank1() != " ")) ||
        (g.getBlank4() == g.getBlank5() && g.getBlank5() == g.getBlank6() && (g.getBlank4() != " ")) ||
        (g.getBlank7() == g.getBlank8() && g.getBlank8() == g.getBlank9() && (g.getBlank7() != " ")) ||
        (g.getBlank1() == g.getBlank4() && g.getBlank4() == g.getBlank7() && (g.getBlank1() != " ")) ||
        (g.getBlank2() == g.getBlank5() && g.getBlank5() == g.getBlank8() && (g.getBlank2() != " ")) ||
        (g.getBlank3() == g.getBlank6() && g.getBlank6() == g.getBlank9() && (g.getBlank3() != " ")) ||
        (g.getBlank1() == g.getBlank5() && g.getBlank5() == g.getBlank9() && (g.getBlank1() != " ")) ||
        (g.getBlank3() == g.getBlank5() && g.getBlank5() == g.getBlank7() && (g.getBlank3() != " ")));
}

//
// Checks to see if a box is filled. If so, returns true. If not, false
//
bool boxFilled(int boxSelected, int moveArray[])
{
    for (int i = 0; i < 9; i++) {
        if (moveArray[i] == boxSelected) {
            cout << "ERROR, select a valid grid" << endl;
            return true;
        }
    }
    return false;
}

//
// Updates the square with the move of the current player.
// Additionally increases the move counter moveCount.
//
void makeMove(int (&PreviousMoves)[9], int &moveCount, Grid &grid, int num)
{
    PreviousMoves[moveCount] = num;
    grid.updateGrid(num);
    grid.changeIsX();
    moveCount++;
}

//
// Runs a single player variant of Tic-Tac-Toe
//
void singlePlayer(Grid spGrid)
{
    PlayerMove promptedMove;
    int moveCount = 0;
    int PreviousMoves[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // CPU always makes first move
    PreviousMoves[moveCount] = 1;
    spGrid.updateGrid(1);
    spGrid.changeIsX();
    moveCount++;
    
    // Loop until the game ends
    do {
            
        // Show the grid to the user
        spGrid.showTurn();
        spGrid.showGrid();
        
        // Get a value from the user
        promptedMove = spGrid.promptMove();

        // Take action based on what the user entered
        switch (promptedMove)
        {
            case cSquareOne:
                if (!boxFilled(1, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, spGrid, 1);
                break;

            case cSquareTwo:
                if (!boxFilled(2, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, spGrid, 2);
                break;
            
            case cSquareThree:
                if (!boxFilled(3, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, spGrid, 3);
                break;
        
            case cSquareFour:
                if (!boxFilled(4, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, spGrid, 4);
                break;
                
            case cSquareFive:
                if (!boxFilled(5, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, spGrid, 5);
                break;
                
            case cSquareSix:
                if (!boxFilled(6, PreviousMoves))
                    makeMove(PreviousMoves, moveCount, spGrid, 6);
                break;
                
            case cSquareSeven:
                if (!boxFilled(7, PreviousMoves))
                    makeMove(PreviousMoves, moveCount, spGrid, 7);
                break;
                
            case cSquareEight:
                if (!boxFilled(8, PreviousMoves))
                    makeMove(PreviousMoves, moveCount, spGrid, 8);
                break;
                
            case cSquareNine:
                if (!boxFilled(9, PreviousMoves))
                    makeMove(PreviousMoves, moveCount, spGrid, 9);
                break;

          case cUnknownSquare:
            cout << "ERROR, unknown move selected" << endl;
        }
        
        // Determine CPU move
        if (spGrid.getIsX()) {
            
            // THIRD MOVE
            if (moveCount == 2) { // Choose second move based on user's first move
                
                // CASE 1
                if (PreviousMoves[1] != 9) {
                // If user did not choose 9, CPU chooses 9
                    makeMove(PreviousMoves, moveCount, spGrid, 9);
                
                // CASE 2
                } else {
                // If user chose 9, CPU chooses 3
                    makeMove(PreviousMoves, moveCount, spGrid, 3);
                }
            
            // FIFTH MOVE
            } else if (moveCount == 4) { // Choose third move based on user's first two moves
                
                // Prevent user from winning
                if (spGrid.userCanWinInNextMove()) {
                  makeMove(PreviousMoves, moveCount, spGrid, spGrid.proactiveSquareNum());
                    
                // Make winning move
                } else if (spGrid.compCanWinInNextMove()) {
                    makeMove(PreviousMoves, moveCount, spGrid, spGrid.winningMove());
                    break;
                    
                // Make strategic move
                } else {
                    // CASE 1
                    if (PreviousMoves[2] == 9) {
                    // If CPU previously choose 9
                        if (PreviousMoves[1] != 3 && PreviousMoves[3] != 3) {
                        // if square 3 is available, CPU chooses 3
                            makeMove(PreviousMoves, moveCount, spGrid, 3);
                        } else {
                        // if square 3 is taken, choose 7
                            makeMove(PreviousMoves, moveCount, spGrid, 7);
                        }
                    
                    // CASE 2
                    } else if (PreviousMoves[2] == 3) {
                    // If CPU previously chose 3
                        if (PreviousMoves[1] != 2 && PreviousMoves[3] != 2) {
                        // if 2 is available, choose 2
                            makeMove(PreviousMoves, moveCount, spGrid, 2);
                            break;
                        } else {
                        // if square 2 is taken, choose 7
                            makeMove(PreviousMoves, moveCount, spGrid, 7);
                        }
                    }
                }
            
            // SEVENTH MOVE
            } else if (moveCount == 6) { // Choose fourth move based on user's first three moves
    
                // Make winning move
                if (spGrid.compCanWinInNextMove()) {
                    makeMove(PreviousMoves, moveCount, spGrid, spGrid.winningMove());
                    break;

                // Prevent user from winning
                } else if (spGrid.userCanWinInNextMove()) {
                    makeMove(PreviousMoves, moveCount, spGrid, spGrid.proactiveSquareNum());
                    
                // Make strategic move
                } else {
                    // CASE 1
                    if ((PreviousMoves[2] == 9 && PreviousMoves[4] == 3) ||
                        (PreviousMoves[2] == 3 && PreviousMoves[4] == 9)) {
                    // If CPU has squares 9 and 3, CPU chooses 2, 5, or 6
                        if (PreviousMoves[1] != 2 && PreviousMoves[3] != 2 && PreviousMoves[5] != 2) {
                        // if square 2 is available, choose 2
                            makeMove(PreviousMoves, moveCount, spGrid, 2);
                            break;
                        } else if (PreviousMoves[1] != 5 && PreviousMoves[3] != 5 && PreviousMoves[5] != 5) {
                        // else if square 5 is available, choose 5
                            makeMove(PreviousMoves, moveCount, spGrid, 5);
                            break;
                        } else if (PreviousMoves[1] != 6 && PreviousMoves[3] != 6 && PreviousMoves[5] != 6){
                        // else if square 6 is available, choose 6
                            makeMove(PreviousMoves, moveCount, spGrid, 6);
                            break;
                        }
                    
                    // CASE 2
                    } else if ((PreviousMoves[2] == 9 && PreviousMoves[4] == 7) ||
                               (PreviousMoves[2] == 7 && PreviousMoves[4] == 9)) {
                    // If CPU has squares 9 and 7, CPU chooses 4, 5, or 8
                        if (PreviousMoves[1] != 4 && PreviousMoves[3] != 4 && PreviousMoves[5] != 4) {
                        // if square 4 is available, choose 4
                            makeMove(PreviousMoves, moveCount, spGrid, 4);
                            break;
                        } else if (PreviousMoves[1] != 5 && PreviousMoves[3] != 5 && PreviousMoves[5] != 5) {
                        // else if square 5 is available, choose 5
                            makeMove(PreviousMoves, moveCount, spGrid, 5);
                            break;
                        } else if (PreviousMoves[1] != 8 && PreviousMoves[3] != 8 && PreviousMoves[5] != 8){
                        // else if square 8 is available, choose 8
                            makeMove(PreviousMoves, moveCount, spGrid, 8);
                            break;
                        }
                        
                    // CASE 3
                    } else if ((PreviousMoves[2] == 3 && PreviousMoves[4] == 7) ||
                               (PreviousMoves[2] == 7 && PreviousMoves[4] == 3)) {
                    // If CPU has squares 3 and 7, CPU chooses 2, 4, or 5
                        if (PreviousMoves[1] != 2 && PreviousMoves[3] != 2 && PreviousMoves[5] != 2) {
                        // if square 2 is available, choose 2
                            makeMove(PreviousMoves, moveCount, spGrid, 2);
                            break;
                        } else if (PreviousMoves[1] != 4 && PreviousMoves[3] != 4 && PreviousMoves[5] != 4) {
                        // else if square 4 is available, choose 4
                            makeMove(PreviousMoves, moveCount, spGrid, 4);
                            break;
                        } else if (PreviousMoves[1] != 5 && PreviousMoves[3] != 5 && PreviousMoves[5] != 5) {
                        // else if square 5 is available, choose 5
                            makeMove(PreviousMoves, moveCount, spGrid, 5);
                            break;
                        }
                    }
                }
            // NINTH/LAST MOVE
            } else if (moveCount == 8) { // Choose fifth move based on user's first four moves
                
                // Make winning move
                if (spGrid.compCanWinInNextMove()) {
                    makeMove(PreviousMoves, moveCount, spGrid, spGrid.winningMove());
                    break;

                // Prevent user from winning
                } else if (spGrid.userCanWinInNextMove()) {
                    makeMove(PreviousMoves, moveCount, spGrid, spGrid.proactiveSquareNum());
                    
                // Make strategic move
                } else {
                    makeMove(PreviousMoves, moveCount, spGrid, spGrid.chooseNextEmptyBlock());
                    break;
                }
            }
        }
        
      // Stay in the loop until the grid is filled up
    } while (moveCount != 9 && checkVictory(spGrid) == false);
    
    if (checkVictory(spGrid) == true)
    {
        char icon;
        if (spGrid.getIsX()) { icon = 'O'; }
        else { icon = 'X'; }
        
        //
        // FIGURE OUT HOW TO MAKE A BELL NOISE
        //
        
        cout << "\n%%%%%%%%%%%%%%%%%%%%" << endl;
        cout << "********************" << endl;
        cout << "--------------------\n" << endl;
        cout << "THE COMPUTER WINS!!!" << endl;
        spGrid.showGrid();
        cout << "\n--------------------" << endl;
        cout << "********************" << endl;
        cout << "%%%%%%%%%%%%%%%%%%%%\n" << endl;
    } else {
        cout << "\nCAT'S GAME!!!" << endl;
        spGrid.showGrid();
        cout << "\n";

    }
}

//
// Runs multiplayer variant of Tic-Tac-Toe
//
void multiplayer(Grid mpGrid)
{
    PlayerMove promptedMove;
    int moveCount = 0;
    int PreviousMoves[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Loop until the game ends
    do {

        // Show the grid to the user
        mpGrid.showTurn();
        mpGrid.showGrid();

        // Get a value from the user
        promptedMove = mpGrid.promptMove();


        // Take action based on what the user entered
        switch (promptedMove)
        {
            case cSquareOne:
                if (!boxFilled(1, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 1);
                break;

            case cSquareTwo:
                if (!boxFilled(2, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 2);
                break;
            
            case cSquareThree:
                if (!boxFilled(3, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 3);
                break;
        
            case cSquareFour:
                if (!boxFilled(4, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 4);
                break;
                
            case cSquareFive:
                if (!boxFilled(5, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 5);
                break;
                
            case cSquareSix:
                if (!boxFilled(6, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 6);
                break;
                
            case cSquareSeven:
                if (!boxFilled(7, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 7);
                break;
                
            case cSquareEight:
                if (!boxFilled(8, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 8);
                break;
                
            case cSquareNine:
                if (!boxFilled(9, PreviousMoves))
                  makeMove(PreviousMoves, moveCount, mpGrid, 9);
                break;

          case cUnknownSquare:
            cout << "ERROR, unknown move selected" << endl;
            break;
        }
      // Stay in the loop until the grid is filled up
    } while (moveCount != 9 && checkVictory(mpGrid) == false);
    
    if (checkVictory(mpGrid) == true)
    {
        char icon;
        if (mpGrid.getIsX()) { icon = 'O'; }
        else { icon = 'X'; }
        
        //
        // FIGURE OUT HOW TO MAKE A BELL NOISE
        //
        
        cout << "\n%%%%%%%%%%%%%%%%%" << endl;
        cout << "*****************" << endl;
        cout << "-----------------\n" << endl;
        cout << "PLAYER " << icon << " WINS!!!" << endl;
        mpGrid.showGrid();
        cout << "\n-----------------" << endl;
        cout << "*****************" << endl;
        cout << "%%%%%%%%%%%%%%%%%\n" << endl;
    } else {
        cout << "\nCAT'S GAME!!!" << endl;
        mpGrid.showGrid();
        cout << "\n";

    }
}

int main() {
    MenuItem menuItems[] = { MenuItem("Single Player",'s'), MenuItem("Multiplayer",'m'), MenuItem("Quit", 'q')};
    Menu appMenu(menuItems,3); // An instance of our Menu object
    char promptedVal;   // An instance of the prompted value enumeration
    Grid spGrid;
    Grid mpGrid;
    
    // Loop until the user quits
    do {
        
      // Show the menu to the user
      appMenu.showMenu();

      // Get a value from the user
      promptedVal = appMenu.promptUser();

      // Take action based on what the user entered
      switch (promptedVal)
        {
          case 's':
                singlePlayer(spGrid);
                break;

          case 'm':
                multiplayer(mpGrid);
                break;
            
          case 'q':
            cout << "*smacks lips* Quitter..." << endl;
            break;

          default:
            cout << "ERROR, unknown item selected" << endl;
            break;
        }
      // Stay in the loop until we get a cQuitItem
    } while (promptedVal != 'q');
    
    cout << "Done" << endl;
    return 0;
}
