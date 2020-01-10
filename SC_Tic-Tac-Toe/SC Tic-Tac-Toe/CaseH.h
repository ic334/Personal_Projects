//
//  Cases.hpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#ifndef CaseH_h
#define CaseH_h

#include <stdio.h>
#include "GridH.h"

//
// Class definition
//
class Case
{
    public:
        bool userCanWinInNextMove(Grid grid);
        int proactiveSquareNum(Grid grid);
        bool compCanWinInNextMove(Grid grid);
        int winningMove(Grid grid);
};
#endif /* CaseH_h */
