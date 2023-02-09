#include "pa2.h"

void openFile(ofstream& outFile, string fileName){
    outFile.open(fileName, ios::out);

    if (outFile.is_open()){
        cout << "Successfully opened " << fileName << endl;
    }
    else{
        cout << "Failed to open " << fileName << endl;
        exit(-1);
    }
}

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
    
    for (int i = 0; i < (sortedVec.size() - 1); i++){
        minIndex = i;
        minValue = sortedVec[i];

        for (int j = i + 1; j < sortedVec.size(); j++){
            if (sortedVec[j] <= minValue){
                minValue = sortedVec[j];
                minIndex = j;
            }
        }
        swap(sortedVec[minIndex], sortedVec[i]);
    }
    return vec;
}

vector<int> bubbleSort(vector<int> vec){
    vector<int> sortedVec = vec;
    int maxValue, maxIndex;
    int count = 0;

    for (maxValue = sortedVec.size() - 1; maxValue > 0; maxValue--){
        for (maxIndex = 0; maxIndex < maxValue; maxIndex++){
            if (sortedVec[maxIndex] > sortedVec[maxIndex + 1]){
                swap(sortedVec[maxIndex], sortedVec[maxIndex + 1]);
            }
        }
        if (sortedChecking(sortedVec) == true){
            break;
        }
    }
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

void driverFunction(vector<int>& vec, ofstream& outFile, string sortType, string vecType){
    int numDataComparisons = 0, numloopComparisons = 0, numdataAssignments = 0, numloopAssignments = 0, numOther = 0, total = 0;

    if (sortType == "selection"){
        // Execution time
        auto start = high_resolution_clock::now();
        selectionSort(vec);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);

        // Print out
        outFile << vecType;
        outFile << "," << duration.count();
        outFile << "," << numDataComparisons;
        outFile << "," << numloopComparisons;
        outFile << "," << numdataAssignments;
        outFile << "," << numloopAssignments;
        outFile << "," << numOther;
        outFile << "," << total << endl;
    }
    else if (sortType == "bubble"){
        auto start = high_resolution_clock::now();
        bubbleSort(vec);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);

        // Print out
        outFile << vecType;
        outFile << "," << duration.count();
        outFile << "," << numDataComparisons;
        outFile << "," << numloopComparisons;
        outFile << "," << numdataAssignments;
        outFile << "," << numloopAssignments;
        outFile << "," << numOther;
        outFile << "," << total << endl;
    }
    else if (sortType == "insertion"){
        auto start = high_resolution_clock::now();
        insertionSort(vec);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);

        // Print out
        outFile << vecType;
        outFile << "," << duration.count();
        outFile << "," << numDataComparisons;
        outFile << "," << numloopComparisons;
        outFile << "," << numdataAssignments;
        outFile << "," << numloopAssignments;
        outFile << "," << numOther;
        outFile << "," << total << endl;
    }
}

void closeFile(ofstream& outFile){
    outFile.close();
}