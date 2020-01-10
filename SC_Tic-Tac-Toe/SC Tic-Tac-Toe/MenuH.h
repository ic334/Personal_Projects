//
//  Menu.hpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#ifndef MenuH_h
#define MenuH_h

#include <stdio.h>
#include <vector>
#include "MenuItemH.h"

//
// Class definition
//
class Menu
{
    public:
        Menu(MenuItem *items,int count);
        
        void showMenu();
        void showGrid();
        char promptUser();
    private:
        std::vector<MenuItem> mItems;
};

#endif /* MenuH_h */
