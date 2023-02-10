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
void printVector(vector<int> vec);
void swap(int& a, int& b);
bool sortedChecking(vector<int> vec);
void algorithmAnalysis(ofstream& outFileSelection, ofstream& outFileBubble, ofstream& outFileInsertion, string sortType);
vector<int> selectionSort(vector<int> vec);
vector<int> bubbleSort(vector<int> vec);
vector<int> insertionSort(vector<int> vec);

#endif