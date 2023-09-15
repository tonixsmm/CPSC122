#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

void iterativeCountdown(int);
void recursiveCountdown(int);

// A recursive function is a function that directly or indirectly calls itself
// Pros: Simple/Short/Elegant solutions for some problems (compared to iterative solution). Commonly used by other programmers
// Cons: High memory overhead compared to iterative solutions

int iterativeMultiplication(int, int);
int recursiveMultiplication(int, int);

int iterativePower(int, int);
int recursivePower(int, int);

int iterativeFactorial(int n);
int recursiveFactorial(int n);

void displayString(string, int);
void displayString(string);
void displayStringReverse(string);
int countCharacters(string);

void writeSequence(int);
void writeSequenceHelper(int, bool);

#endif