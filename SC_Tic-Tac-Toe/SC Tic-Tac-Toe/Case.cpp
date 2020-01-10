//
//  Cases.cpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#include "CaseH.h"
#include "GridH.h"


// Detacts if user can win in their next move
bool Case::userCanWinInNextMove(Grid grid) {
    if ((grid.getBlank2() == "O" && grid.getBlank2() == grid.getBlank5()) ||
        (grid.getBlank5() == "O" && grid.getBlank5() == grid.getBlank8()) ||
        (grid.getBlank3() == "O" && grid.getBlank3() == grid.getBlank6()) ||
        (grid.getBlank6() == "O" && grid.getBlank6() == grid.getBlank9()) ||
        (grid.getBlank4() == "O" && grid.getBlank4() == grid.getBlank5()) ||
        (grid.getBlank5() == "O" && grid.getBlank5() == grid.getBlank6()) ||
        (grid.getBlank7() == "O" && grid.getBlank7() == grid.getBlank8()) ||
        (grid.getBlank8() == "O" && grid.getBlank8() == grid.getBlank9()) ||
        (grid.getBlank3() == "O" && grid.getBlank3() == grid.getBlank5()) ||
        (grid.getBlank5() == "O" && grid.getBlank5() == grid.getBlank7())) {
        return true;
    } else {
        return false;
    }
}

// Uses current move to prevent user from winning
int Case::proactiveSquareNum(Grid grid) {
    if (grid.getBlank2() == "O" && grid.getBlank2() == grid.getBlank5()) {
        return 8;
    } else if (grid.getBlank5() == "O" && grid.getBlank5() == grid.getBlank8()) {
        return 2;
    } else if (grid.getBlank3() == "O" && grid.getBlank3() == grid.getBlank6()) {
        return 9;
    } else if (grid.getBlank6() == "O" && grid.getBlank6() == grid.getBlank9()) {
        return 3;
    } else if (grid.getBlank4() == "O" && grid.getBlank4() == grid.getBlank5()) {
        return 6;
    } else if (grid.getBlank5() == "O" && grid.getBlank5() == grid.getBlank6()) {
        return 4;
    } else if (grid.getBlank7() == "O" && grid.getBlank7() == grid.getBlank8()) {
        return 9;
    } else if (grid.getBlank8() == "O" && grid.getBlank8() == grid.getBlank9()) {
        return 7;
    } else if (grid.getBlank3() == "O" && grid.getBlank3() == grid.getBlank5()) {
        return 7;
    } else if (grid.getBlank5() == "O" && grid.getBlank5() == grid.getBlank7()) {
        return 3;
    }
    return 0;
}

// Detacts if CPU can win in their current move
bool Case::compCanWinInNextMove(Grid grid) {
    if ((grid.getBlank2() == "X" && grid.getBlank2() == grid.getBlank5()) ||
        (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank8()) ||
        (grid.getBlank3() == "X" && grid.getBlank3() == grid.getBlank6()) ||
        (grid.getBlank6() == "X" && grid.getBlank6() == grid.getBlank9()) ||
        (grid.getBlank4() == "X" && grid.getBlank4() == grid.getBlank5()) ||
        (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank6()) ||
        (grid.getBlank7() == "X" && grid.getBlank7() == grid.getBlank8()) ||
        (grid.getBlank8() == "X" && grid.getBlank8() == grid.getBlank9()) ||
        (grid.getBlank3() == "X" && grid.getBlank3() == grid.getBlank5()) ||
        (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank7()) ||
        (grid.getBlank1() == "X" && grid.getBlank1() == grid.getBlank2()) ||
        (grid.getBlank2() == "X" && grid.getBlank2() == grid.getBlank3()) ||
        (grid.getBlank1() == "X" && grid.getBlank1() == grid.getBlank4()) ||
        (grid.getBlank4() == "X" && grid.getBlank4() == grid.getBlank7()) ||
        (grid.getBlank1() == "X" && grid.getBlank1() == grid.getBlank5()) ||
        (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank9())) {
        return true;
    } else {
        return false;
    }
}

// Uses current move to win
int Case::winningMove(Grid grid) {
    if (grid.getBlank2() == "X" && grid.getBlank2() == grid.getBlank5()) {
        return 8;
    } else if (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank8()) {
        return 2;
    } else if (grid.getBlank3() == "X" && grid.getBlank3() == grid.getBlank6()) {
        return 9;
    } else if (grid.getBlank6() == "X" && grid.getBlank6() == grid.getBlank9()) {
        return 3;
    } else if (grid.getBlank4() == "X" && grid.getBlank4() == grid.getBlank5()) {
        return 6;
    } else if (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank6()) {
        return 4;
    } else if (grid.getBlank7() == "X" && grid.getBlank7() == grid.getBlank8()) {
        return 9;
    } else if (grid.getBlank8() == "X" && grid.getBlank8() == grid.getBlank9()) {
        return 7;
    } else if (grid.getBlank3() == "X" && grid.getBlank3() == grid.getBlank5()) {
        return 7;
    } else if (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank7()) {
        return 3;
    } else if (grid.getBlank1() == "X" && grid.getBlank1() == grid.getBlank2()) {
        return 3;
    } else if (grid.getBlank2() == "X" && grid.getBlank2() == grid.getBlank3()) {
        return 1;
    } else if (grid.getBlank1() == "X" && grid.getBlank1() == grid.getBlank4()) {
        return 7;
    } else if (grid.getBlank4() == "X" && grid.getBlank4() == grid.getBlank7()) {
        return 1;
    } else if (grid.getBlank1() == "X" && grid.getBlank1() == grid.getBlank5()) {
        return 9;
    } else if (grid.getBlank5() == "X" && grid.getBlank5() == grid.getBlank9()) {
        return 1;
    }
    return 0;
}
