//
//  MenuItemH.h
//  Soul-Crushing Tic-Tac-Toe
//
//  Created by Isaac Cervantes on 12/11/19.
//  Copyright © 2019 ic334. All rights reserved.
//

#ifndef MenuItemH_h
#define MenuItemH_h

#include <stdio.h>
#include <iostream>

class MenuItem
{
 public:
 MenuItem(std::string title,char prompt): mTitle(title),mPrompt(prompt)
  {}

  void display();
  char getPromptChar();
 private:
  std::string mTitle;
  char mPrompt;

};

#endif /* MenuItemH_h */
