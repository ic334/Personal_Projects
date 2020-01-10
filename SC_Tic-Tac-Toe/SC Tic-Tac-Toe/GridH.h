//
//  Grid.hpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#ifndef GridH_h
#define GridH_h

#include <stdio.h>
#include <string>


// Using statement that allows me to use the streams/keywords in the
// std:: namespace without needing the std:: prefix
using namespace std;

//
// Initializing enums PlayerMove. Used for ___________.
//
enum PlayerMove
  {
    cUnknownSquare = 0,
    cSquareOne,
    cSquareTwo,
    cSquareThree,
    cSquareFour,
    cSquareFive,
    cSquareSix,
    cSquareSeven,
    cSquareEight,
    cSquareNine
  };

//
// Class definition
//
class Grid
{
    public:
        void showGrid();
        void showTurn();
        PlayerMove promptMove();
        void updateGrid(int squareNum);
        bool getIsX();
        bool changeIsX();
    
        bool userCanWinInNextMove();
        int proactiveSquareNum();
        bool compCanWinInNextMove();
        int winningMove();
        int chooseNextEmptyBlock();
    
        string getBlank1() {return blank1;}
        string getBlank2() {return blank2;}
        string getBlank3() {return blank3;}
        string getBlank4() {return blank4;}
        string getBlank5() {return blank5;}
        string getBlank6() {return blank6;}
        string getBlank7() {return blank7;}
        string getBlank8() {return blank8;}
        string getBlank9() {return blank9;}
    
        string setBlank1(string b1) {return blank1 = b1;}
        string setBlank2(string b2) {return blank2 = b2;}
        string setBlank3(string b3) {return blank3 = b3;}
        string setBlank4(string b4) {return blank4 = b4;}
        string setBlank5(string b5) {return blank5 = b5;}
        string setBlank6(string b6) {return blank6 = b6;}
        string setBlank7(string b7) {return blank7 = b7;}
        string setBlank8(string b8) {return blank8 = b8;}
        string setBlank9(string b9) {return blank9 = b9;}
    
        string getOne() {return one;}
        string getTwo() {return two;}
        string getThree() {return three;}
        string getFour() {return four;}
        string getFive() {return five;}
        string getSix() {return six;}
        string getSeven() {return seven;}
        string getEight() {return eight;}
        string getNine() {return nine;}
    
        string setOne(string uno) {return one = uno;}
        string setTwo(string dos) {return two = dos;}
        string setThree(string tres) {return three = tres;}
        string setFour(string cuatro) {return four = cuatro;}
        string setFive(string cinco) {return five = cinco;}
        string setSix(string seis) {return six = seis;}
        string setSeven(string siete) {return seven = siete;}
        string setEight(string ocho) {return eight = ocho;}
        string setNine(string nueve) {return nine = nueve;}
    
    private:
        bool isX = true;
        string blank1 = " ";
        string blank2 = " ";
        string blank3 = " ";
        string blank4 = " ";
        string blank5 = " ";
        string blank6 = " ";
        string blank7 = " ";
        string blank8 = " ";
        string blank9 = " ";
        string one = "1";
        string two = "2";
        string three = "3";
        string four = "4";
        string five = "5";
        string six = "6";
        string seven = "7";
        string eight = "8";
        string nine = "9";
};

#endif /* GridH_h */
