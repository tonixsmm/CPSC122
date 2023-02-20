/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: February 21, 2022
Programming Assignment: PA3
Description: This program implements several tasks required by PA3
Note: I attempted the bonus
*/

#ifndef PA3_H
#define PA3_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

// Task 1
void answerIntegerQuestions(const int num, bool *, bool *, bool *);
bool checkMultiplication(int num);
bool checkSumEven(int num);
bool checkPrime(int num);
void runTask1();
void openFile(ifstream&, string);

// Task 2
bool findWinningLotteryTicket(int, const int *, const int);
void runTask2();

// Task 3
string * createWordsArray(ifstream&, const int);
void generateSentence(string *, const string *, const int, const string *, const int, const string *, const int, const string *, const int);
void runTask3();
void printArray(string *, const int);
void swap(int&, int&);
void bubbleSort(string *, const int);

#endif
