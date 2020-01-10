//
//  MenuItem.cpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#include <iostream>
#include "MenuItemH.h"

// display()
void MenuItem::display()
{
  std::cout << "(" << mPrompt << ") " << mTitle << std::endl;
}

char MenuItem::getPromptChar()
{
  return mPrompt;
}
