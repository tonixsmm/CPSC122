#include "pa2.h"

void createVector(vector<int>& vec, int size, bool sorting, bool desc){
    for (int i = 0; i < size; i++){
        vec.push_back(rand() % size);
    }
    if (sorting == 1 && desc == 1){
        sort(vec.begin(), vec.end(), greater<int>());
    }
    else if (sorting == 1){
        sort(vec.begin(), vec.end());
    }
}

void printVector(vector<int> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> selectionSort(vector<int> vec){
    // assume the first element is the smallest
    vector<int> sortedVec;
    int minValue = vec[0];

    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size(); j++){
            if (vec[j] <= minValue){
                sortedVec.push_back(vec[i]);
                minValue = vec[j];
            }
        }
    }
}