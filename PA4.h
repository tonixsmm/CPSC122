/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 1, 2022
Programming Assignment: PA4
Description: This program implements several tasks required by PA4
Note: I attempted the bonus. Please run PA4BonusMain.cpp to see the bonus part
*/

#ifndef PA4_H
#define PA4_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct Package {
	int id;
	double weight;
	int width;
	int length;
	int height;
};

struct LetterOccurrence{
	int count;
	double frequency;
};

Package * loadPackages(ifstream&, string *, int *);
void computePackageStats(const Package[], const int, int * heaviestId, double *, double *);
void runReadFromFile(string filename);
void openFile(ifstream& inFile, string fileName);
void countPackage(ifstream& inFile, int * numPackage);
void printPackageArray(Package * packageArray, int size);
void checkInputFile(int argc);
void runBonus(void);
LetterOccurrence * analyzeString(string userInput);
void printLetterArray(LetterOccurrence * letterArray);
void plotHistogram(LetterOccurrence * letterArray);
int findMaxOccurrenceChar(LetterOccurrence * letterArray);
void charStats(LetterOccurrence * letterArray);

#endif
