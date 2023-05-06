/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 30, 2023
Programming Assignment: PA9
Description: This program implements several tasks required by PA9
I attempted the ART Review Bonus
*/

#ifndef PA9_H
#define PA9_H

#include <iostream>
#include <vector>

// for task 4
#include "LinkedList.h"

using namespace std;

// TODO: add your additional PA9.cpp function prototypes in the appropriate spot below

// task 1 prototypes
int countDigits(string);
int countDigits(string, int);
void runTask1();

// task 2 prototypes
int sumDigits(int);
void runTask2();

// task 3 prototypes
bool isPalindrome(string);
void runTask3();
string stringCleaning(string);

// task 4 prototypes
void runTask4();

// task 5 prototypes
void generateSubstrings(string, vector<string>&);
void runTask5();
void removeFront(string, vector<string>&);
void removeBack(string, vector<string>&);

// BONUS ONLY struct definition and prototypes
struct Coordinates {
	int row;
	int col;
};
bool traverseMaze(char[8][8], Coordinates[], int *, int, int);
void displayMaze(char[8][8]);
void runBONUSTask();

#endif
