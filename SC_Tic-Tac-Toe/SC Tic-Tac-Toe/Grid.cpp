//
//  Grid.cpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#include "GridH.h"
#include <iostream>

// Using statement that allows me to use the streams/keywords in the
// std:: namespace without needing the std:: prefix
using namespace std;

void Grid::showTurn()
{
    char icon = 'O';
    if (isX) { icon = 'X';}
    cout << "\nPLAYER " << icon <<"'s TURN!" << endl;
}

//
// Show the Grid to the user
//
void Grid::showGrid()
{
    cout << one <<"    |"<< two <<"    |" << three << "    " << endl;
    cout << "  " << blank1 << "  |  " << blank2 << "  |  " << blank3 << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "-----|-----|-----" << endl;
    cout << four <<"    |"<< five <<"    |" << six << "    " << endl;
    cout << "  " << blank4 << "  |  " << blank5 << "  |  " << blank6 << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "-----|-----|-----" << endl;
    cout << seven <<"    |"<< eight <<"    |" << nine << "    " << endl;
    cout << "  " << blank7 << "  |  " << blank8 << "  |  " << blank9 << "  " << endl;
    cout << "     |     |     " << endl;

//    cout << "1    |2    |3    " << endl;
//    cout << "     |     |     " << endl;
//    cout << "     |     |     " << endl;
//    cout << "-----|-----|-----" << endl;
//    cout << "4    |5    |6    " << endl;
//    cout << "     |     |     " << endl;
//    cout << "     |     |     " << endl;
//    cout << "-----|-----|-----" << endl;
//    cout << "7    |8    |9    " << endl;
//    cout << "     |     |     " << endl;
//    cout << "     |     |     \n" << endl;
}

//
// Prompt the User for integer input.   Return the proper
// enumerated value that represents what the user entered
//
PlayerMove Grid::promptMove()
{
    int input;
    char icon;
    if (isX) { icon = 'X'; }
    else { icon = 'O'; }
    cout << "Choose a numbered square to place your " << icon << "> ";
    
    cin >> input;

    if ((input < cSquareOne) || (input > cSquareNine))
      return cUnknownSquare;

    // If we know that the input is in range, we can just
    // return the integer value (it corresponds to the
    // enumeration value
      return (PlayerMove) input;
}

void Grid::updateGrid(int squareNum){
    switch (squareNum)
    {
        case 1:
            setOne(" ");
            if (isX) {setBlank1("X");}
            else {setBlank1("O");}
            break;

        case 2:
            setTwo(" ");
            if (isX) {setBlank2("X");}
            else {setBlank2("O");}
            break;
        
        case 3:
            setThree(" ");
            if (isX) {setBlank3("X");}
            else {setBlank3("O");}
            break;
            
        case 4:
            setFour(" ");
            if (isX) {setBlank4("X");}
            else {setBlank4("O");}
            break;

        case 5:
            setFive(" ");
            if (isX) {setBlank5("X");}
            else {setBlank5("O");}
            break;
            
        case 6:
            setSix(" ");
            if (isX) {setBlank6("X");}
            else {setBlank6("O");}
            break;
            
        case 7:
            setSeven(" ");
            if (isX) {setBlank7("X");}
            else {setBlank7("O");}
            break;
            
        case 8:
            setEight(" ");
            if (isX) {setBlank8("X");}
            else {setBlank8("O");}
            break;
            
        case 9:
            setNine(" ");
            if (isX) {setBlank9("X");}
            else {setBlank9("O");}
            break;

        default:
            cout << "ERROR, select a valid grid" << endl;
            break;
    }
    
}

bool Grid::changeIsX()
{
    isX = !isX;
    return isX;
}

bool Grid::getIsX()
{
    return isX;
}

// Detacts if user can win in their next move
bool Grid::userCanWinInNextMove() {
    if ((getBlank2() == "O" && getBlank2() == getBlank5() && getBlank8() == " ") ||
        (getBlank5() == "O" && getBlank5() == getBlank8() && getBlank2() == " ") ||
        (getBlank3() == "O" && getBlank3() == getBlank6() && getBlank9() == " ") ||
        (getBlank6() == "O" && getBlank6() == getBlank9() && getBlank3() == " ") ||
        (getBlank4() == "O" && getBlank4() == getBlank5() && getBlank6() == " ") ||
        (getBlank5() == "O" && getBlank5() == getBlank6() && getBlank4() == " ") ||
        (getBlank7() == "O" && getBlank7() == getBlank8() && getBlank9() == " ") ||
        (getBlank8() == "O" && getBlank8() == getBlank9() && getBlank7() == " ") ||
        (getBlank3() == "O" && getBlank3() == getBlank5() && getBlank7() == " ") ||
        (getBlank5() == "O" && getBlank5() == getBlank7() && getBlank3() == " ") ||
        (getBlank1() == "O" && getBlank1() == getBlank2() && getBlank3() == " ") ||
        (getBlank2() == "O" && getBlank2() == getBlank3() && getBlank1() == " ") ||
        (getBlank1() == "O" && getBlank1() == getBlank4() && getBlank7() == " ") ||
        (getBlank4() == "O" && getBlank4() == getBlank7() && getBlank1() == " ") ||
        (getBlank1() == "O" && getBlank1() == getBlank5() && getBlank9() == " ") ||
        (getBlank5() == "O" && getBlank5() == getBlank9() && getBlank1() == " ") ||
        (getBlank1() == "O" && getBlank1() == getBlank3() && getBlank2() == " ") ||
        (getBlank4() == "O" && getBlank4() == getBlank6() && getBlank5() == " ") ||
        (getBlank7() == "O" && getBlank7() == getBlank9() && getBlank8() == " ") ||
        (getBlank1() == "O" && getBlank1() == getBlank7() && getBlank4() == " ") ||
        (getBlank2() == "O" && getBlank2() == getBlank8() && getBlank5() == " ") ||
        (getBlank3() == "O" && getBlank3() == getBlank9() && getBlank6() == " ") ||
        (getBlank1() == "O" && getBlank1() == getBlank9() && getBlank5() == " ") ||
        (getBlank3() == "O" && getBlank3() == getBlank7() && getBlank5() == " ")) {
        return true;
    } else {
        return false;
    }
}

// Uses current move to prevent user from winning
int Grid::proactiveSquareNum() {
    if (getBlank2() == "O" && getBlank2() == getBlank5() && getBlank8() == " ") {
        return 8;
    } else if (getBlank5() == "O" && getBlank5() == getBlank8() && getBlank2() == " ") {
        return 2;
    } else if (getBlank3() == "O" && getBlank3() == getBlank6() && getBlank9() == " ") {
        return 9;
    } else if (getBlank6() == "O" && getBlank6() == getBlank9() && getBlank3() == " ") {
        return 3;
    } else if (getBlank4() == "O" && getBlank4() == getBlank5() && getBlank6() == " ") {
        return 6;
    } else if (getBlank5() == "O" && getBlank5() == getBlank6() && getBlank4() == " ") {
        return 4;
    } else if (getBlank7() == "O" && getBlank7() == getBlank8() && getBlank9() == " ") {
        return 9;
    } else if (getBlank8() == "O" && getBlank8() == getBlank9() && getBlank7() == " ") {
        return 7;
    } else if (getBlank3() == "O" && getBlank3() == getBlank5() && getBlank7() == " ") {
        return 7;
    } else if (getBlank5() == "O" && getBlank5() == getBlank7() && getBlank3() == " ") {
        return 3;
    } else if (getBlank1() == "O" && getBlank1() == getBlank2() && getBlank3() == " ") {
        return 3;
    } else if (getBlank2() == "O" && getBlank2() == getBlank3() && getBlank1() == " ") {
        return 1;
    } else if (getBlank1() == "O" && getBlank1() == getBlank4() && getBlank7() == " ") {
        return 7;
    } else if (getBlank4() == "O" && getBlank4() == getBlank7() && getBlank1() == " ") {
        return 1;
    } else if (getBlank1() == "O" && getBlank1() == getBlank5() && getBlank9() == " ") {
        return 9;
    } else if (getBlank5() == "O" && getBlank5() == getBlank9() && getBlank1() == " ") {
        return 1;
    } else if (getBlank1() == "O" && getBlank1() == getBlank3() && getBlank2() == " ") {
        return 2;
    } else if (getBlank4() == "O" && getBlank4() == getBlank6() && getBlank5() == " ") {
        return 5;
    } else if (getBlank7() == "O" && getBlank7() == getBlank9() && getBlank8() == " ") {
        return 8;
    } else if (getBlank1() == "O" && getBlank1() == getBlank7() && getBlank4() == " ") {
        return 4;
    } else if (getBlank2() == "O" && getBlank2() == getBlank8() && getBlank5() == " ") {
        return 5;
    } else if (getBlank3() == "O" && getBlank3() == getBlank9() && getBlank6() == " ") {
        return 6;
    } else if (getBlank1() == "O" && getBlank1() == getBlank9() && getBlank5() == " ") {
        return 5;
    } else if (getBlank3() == "O" && getBlank3() == getBlank7() && getBlank5() == " ") {
        return 5;
    }
    return 0;
    
    return 0;
}

// Detacts if CPU can win in their current move
bool Grid::compCanWinInNextMove() {
    if ((getBlank2() == "X" && getBlank2() == getBlank5() && getBlank8() == " ") ||
        (getBlank5() == "X" && getBlank5() == getBlank8() && getBlank2() == " ") ||
        (getBlank3() == "X" && getBlank3() == getBlank6() && getBlank9() == " ") ||
        (getBlank6() == "X" && getBlank6() == getBlank9() && getBlank3() == " ") ||
        (getBlank4() == "X" && getBlank4() == getBlank5() && getBlank6() == " ") ||
        (getBlank5() == "X" && getBlank5() == getBlank6() && getBlank4() == " ") ||
        (getBlank7() == "X" && getBlank7() == getBlank8() && getBlank9() == " ") ||
        (getBlank8() == "X" && getBlank8() == getBlank9() && getBlank7() == " ") ||
        (getBlank3() == "X" && getBlank3() == getBlank5() && getBlank7() == " ") ||
        (getBlank5() == "X" && getBlank5() == getBlank7() && getBlank3() == " ") ||
        (getBlank1() == "X" && getBlank1() == getBlank2() && getBlank3() == " ") ||
        (getBlank2() == "X" && getBlank2() == getBlank3() && getBlank1() == " ") ||
        (getBlank1() == "X" && getBlank1() == getBlank4() && getBlank7() == " ") ||
        (getBlank4() == "X" && getBlank4() == getBlank7() && getBlank1() == " ") ||
        (getBlank1() == "X" && getBlank1() == getBlank5() && getBlank9() == " ") ||
        (getBlank5() == "X" && getBlank5() == getBlank9() && getBlank1() == " ") ||
        (getBlank1() == "X" && getBlank1() == getBlank3() && getBlank2() == " ") ||
        (getBlank4() == "X" && getBlank4() == getBlank6() && getBlank5() == " ") ||
        (getBlank7() == "X" && getBlank7() == getBlank9() && getBlank8() == " ") ||
        (getBlank1() == "X" && getBlank1() == getBlank7() && getBlank4() == " ") ||
        (getBlank2() == "X" && getBlank2() == getBlank8() && getBlank5() == " ") ||
        (getBlank3() == "X" && getBlank3() == getBlank9() && getBlank6() == " ") ||
        (getBlank1() == "X" && getBlank1() == getBlank9() && getBlank5() == " ") ||
        (getBlank3() == "X" && getBlank3() == getBlank7() && getBlank5() == " ")) {
        return true;
    } else {
        return false;
    }
}

// Uses current move to win
int Grid::winningMove() {
    if (getBlank2() == "X" && getBlank2() == getBlank5() && getBlank8() == " ") {
        return 8;
    } else if (getBlank5() == "X" && getBlank5() == getBlank8() && getBlank2() == " ") {
        return 2;
    } else if (getBlank3() == "X" && getBlank3() == getBlank6() && getBlank9() == " ") {
        return 9;
    } else if (getBlank6() == "X" && getBlank6() == getBlank9() && getBlank3() == " ") {
        return 3;
    } else if (getBlank4() == "X" && getBlank4() == getBlank5() && getBlank6() == " ") {
        return 6;
    } else if (getBlank5() == "X" && getBlank5() == getBlank6() && getBlank4() == " ") {
        return 4;
    } else if (getBlank7() == "X" && getBlank7() == getBlank8() && getBlank9() == " ") {
        return 9;
    } else if (getBlank8() == "X" && getBlank8() == getBlank9() && getBlank7() == " ") {
        return 7;
    } else if (getBlank3() == "X" && getBlank3() == getBlank5() && getBlank7() == " ") {
        return 7;
    } else if (getBlank5() == "X" && getBlank5() == getBlank7() && getBlank3() == " ") {
        return 3;
    } else if (getBlank1() == "X" && getBlank1() == getBlank2() && getBlank3() == " ") {
        return 3;
    } else if (getBlank2() == "X" && getBlank2() == getBlank3() && getBlank1() == " ") {
        return 1;
    } else if (getBlank1() == "X" && getBlank1() == getBlank4() && getBlank7() == " ") {
        return 7;
    } else if (getBlank4() == "X" && getBlank4() == getBlank7() && getBlank1() == " ") {
        return 1;
    } else if (getBlank1() == "X" && getBlank1() == getBlank5() && getBlank9() == " ") {
        return 9;
    } else if (getBlank5() == "X" && getBlank5() == getBlank9() && getBlank1() == " ") {
        return 1;
    } else if (getBlank1() == "X" && getBlank1() == getBlank3() && getBlank2() == " ") {
        return 2;
    } else if (getBlank4() == "X" && getBlank4() == getBlank6() && getBlank5() == " ") {
        return 5;
    } else if (getBlank7() == "X" && getBlank7() == getBlank9() && getBlank8() == " ") {
        return 8;
    } else if (getBlank1() == "X" && getBlank1() == getBlank7() && getBlank4() == " ") {
        return 4;
    } else if (getBlank2() == "X" && getBlank2() == getBlank8() && getBlank5() == " ") {
        return 5;
    } else if (getBlank3() == "X" && getBlank3() == getBlank9() && getBlank6() == " ") {
        return 6;
    } else if (getBlank1() == "X" && getBlank1() == getBlank9() && getBlank5() == " ") {
        return 5;
    } else if (getBlank3() == "X" && getBlank3() == getBlank7() && getBlank5() == " ") {
        return 5;
    }
    return 0;
}

int Grid::chooseNextEmptyBlock()
{
    if (two != " ") {
        return 2;
    } else if (three != " ") {
        return 3;
    } else if (four != " ") {
        return 4;
    } else if (five != " ") {
        return 5;
    } else if (six != " ") {
        return 6;
    } else if (seven != " ") {
        return 7;
    } else if (eight != " ") {
        return 8;
    } else if (nine != " ") {
        return 9;
    }
    return 0;
}
