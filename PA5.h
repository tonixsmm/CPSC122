/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 21, 2022
Programming Assignment: PA5
Description: This program implements several tasks required by PA5
Note: I attempted the bonus
*/

#ifndef PA5_H
#define PA5_H

#include <iostream>
#include <fstream>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = QUIT_OPTION;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runMusicManager();

#endif
