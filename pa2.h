#ifndef PA2_H
#define PA2_H

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void createVector(vector<int>& vec, int size, bool sorting, bool desc);
void printVector(vector<int> vec);
void swap(int& a, int& b);
bool sortedChecking(vector<int> vec);
void sortAnalysis(vector<int> vec);
vector<int> selectionSort(vector<int> vec);
vector<int> bubbleSort(vector<int> vec);
vector<int> insertionSort(vector<int> vec);

#endif