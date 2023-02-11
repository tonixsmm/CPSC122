/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: February 10, 2022
Programming Assignment: PA2
Description: This program implements several sorting algorithm to compare for efficiency
Note: I decided to use milliseconds instead of seconds for execution time measurement becuase it is more accurate
*/

#ifndef PA2_H
#define PA2_H

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <fstream>
#include<iomanip>

using namespace std;
using namespace std::chrono;

void openFile(ofstream& outFile, string fileName);
void closeFile(ofstream& outFile);
void createVector(vector<int>& vec, int size, bool sorting, bool desc);
void swap(int& a, int& b);
bool sortedChecking(vector<int> vec);
void algorithmAnalysis(ofstream& outFileSelection, ofstream& outFileBubble, ofstream& outFileInsertion, ofstream& outFileShell, string sortType);
void selectionSort(vector<int> vec, long& dataComparisons, long& loopControlComparisons, long& dataAssignments, long& loopControlAssignments, long& other, long& total);
void bubbleSort(vector<int> vec, long& dataComparisons, long& loopControlComparisons, long& dataAssignments, long& loopControlAssignments, long& other, long& total);
void insertionSort(vector<int> vec, long& dataComparisons, long& loopControlComparisons, long& dataAssignments, long& loopControlAssignments, long& other, long& total);
void shellSort(vector<int> vec, long& dataComparisons, long& loopControlComparisons, long& dataAssignments, long& loopControlAssignments, long& other, long& total);

#endif