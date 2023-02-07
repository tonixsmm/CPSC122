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

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

bool sortedChecking(vector<int> vec){
    long count = 0;
    for (int i = 1; i < vec.size(); i++){
        if (vec[i - 1] <= vec[i]){
            count++;
        }
    }
    if (count == (vec.size() - 1)){
        return true;
    }
    else {
        return false;
    }
}

vector<int> selectionSort(vector<int> vec){
    long count = 0;
    vector<int>& sortedVec = vec; // also this?
    int minValue, minIndex; // is this 1 or 2 ops?
    count += 2; // assuming 1
    count++; // int i = 0
    for (int i = 0; i < (sortedVec.size() - 1); i++){
        count++; // i < sortedVec.size() - 1 true
        minIndex = i;
        minValue = sortedVec[i];
        count += 2; // two above
        count++; // for initial j
        for (int j = i + 1; j < sortedVec.size(); j++){
            count++; // for j < () true
            count++; // for if statement
            if (sortedVec[j] <= minValue){
                minValue = sortedVec[j];
                minIndex = j;
                count += 2; // for two of these
            }
            count++; // for j++
        }
        swap(sortedVec[minIndex], sortedVec[i]);
        count++; // for swap
        count++; // for i++ 

        if (sortedChecking(sortedVec) == true){
            break;
        }
    }
    count++; // for j < () false
    count++; // for i < () false
    count++; // for return vec
    cout << "Counter: " << count << endl;
    return vec;
}

vector<int> bubbleSort(vector<int> vec){
    vector<int> sortedVec = vec;
    int maxValue, maxIndex;
    int count = 0;
    count += 2; // for variable initialization
    count++; // initialize maxValue

    for (maxValue = sortedVec.size() - 1; maxValue > 0; maxValue--){
        count++; // maxValue > 0 true
        count++; // initialize maxIndex
        for (maxIndex = 0; maxIndex < maxValue; maxIndex++){
            count++; // if loop condition is true
            count++; // if statement
            if (sortedVec[maxIndex] > sortedVec[maxIndex + 1]){
                count++; // swap
                swap(sortedVec[maxIndex], sortedVec[maxIndex + 1]);
            }
            count++; // maxIndex++
        }
        count++; // maxValue--

        if (sortedChecking(sortedVec) == true){
            break;
        }
    }
    count++; // maxIndex < maxValue false
    count++; // maxValue > 0
    count++; // return sortedVec
    cout << "Count: " << count << endl;
    return sortedVec;
}

vector<int> insertionSort(vector<int> vec){
    vector<int> sortedVec = vec;
    int j, value;

    for (int i = 1; i < sortedVec.size(); i++){
        value = sortedVec[i];
        j = i - 1;
        
        while (j >= 0 && value < sortedVec[j]){
            sortedVec[j + 1] = sortedVec[j];
            j--;
        }
        sortedVec[j + 1] = value;

        if (sortedChecking(sortedVec) == true){
            break;
        }
    }
    return sortedVec;
}

int sortAnalysis(vector<int> vec){
    auto start = high_resolution_clock::now();

    // sort function goes here
    sort(vec.begin(), vec.end());

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    
    return duration.count();
}