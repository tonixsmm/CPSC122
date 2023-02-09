#ifndef PA2_H
#define PA2_H

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

vector<int> createVector(vector<int> vec, int size, bool sorting, bool desc);
void printVector(vector<int> vec);
void swap(int& a, int& b);
bool sortedChecking(vector<int> vec);
int algorithmAnalysis(vector<int> vec500, vector<int> vec1000, vector<int> vec5000, vector<int> vec10000, string sortType);
void driverFunction(vector<int> vec, string sortType);
vector<int> selectionSort(vector<int> vec);
vector<int> bubbleSort(vector<int> vec);
vector<int> insertionSort(vector<int> vec);

#endif