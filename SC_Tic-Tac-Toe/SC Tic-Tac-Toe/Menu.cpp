//
//  Menu.cpp
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#include "MenuH.h"
#include "MenuItemH.h"
#include <iostream>

// Using statement that allows me to use the streams/keywords in the
// std:: namespace without needing the std:: prefix
using namespace std;

//
// Menu Constructor
//
Menu::Menu(MenuItem *items, int count)
{
  // Initialize from a C-style array
  for (int i=0; i < count; i++)
    {
      mItems.push_back(items[i]);
    }
}

//
// Show the Menu to the user
//
void Menu::showMenu()
{
    cout << " ---- MENU ---- " << endl;
    for (MenuItem item : mItems)
    {
      item.display();
    }
}

//
// Prompt the User for integer input.   Return the proper
// enumerated value that represents what the user entered
//
char Menu::promptUser()
{
  char input;

  cout << "Enter Choice> ";
  cin >> input;

  // validate input
  for (MenuItem  item : mItems)
    {
      // If it's a valid input, return it
      if (item.getPromptChar() == input)
    return input;
    }

  // Otherwise return -1
  return -1;
}

