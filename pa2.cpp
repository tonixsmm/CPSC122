#include "pa2.h"

void createVector(vector<int>& vec, int size){
    for (int i = 0; i < size; i++){
        vec.push_back(rand() % size);
    }
}

void printVector(vector<int> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}