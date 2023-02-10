#include "pa2.h"

void openFile(ofstream& outFile, string fileName){
    outFile.open(fileName, ios::out);

    if (outFile.is_open()){
        cout << "Successfully opened " << fileName << endl;
        outFile << "Vector configuration,Seconds,# Data Comparisons,# Loop Comparisons,# Data Assignments,# Loop Assignments,# Other,# Total" << endl;
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

void algorithmAnalysis(ofstream& outFileSelection, ofstream& outFileBubble, ofstream& outFileInsertion, string sortType){
    int numDataComparisons = 0, numLoopComparisons = 0, numDataAssignments = 0, numLoopAssignments = 0, numOther = 0, total = 0;
    double numSeconds = 0.0;
    int vecSize[4] = {500, 1000, 5000, 10000};
    string sortAlgo[3] = {"Selection", "Bubble", "Insertion"};
    string sortMethod;
    vector<int> vec;

    for (int i = 0; i < 4; i++){
        // Create vector
        if (sortType == "Sorted"){
            createVector(vec, vecSize[i], 1, 0);
            sortMethod = "Sorted N=";
        }
        if (sortType == "DescSorted"){
            createVector(vec, vecSize[i], 1, 1);
            sortMethod = "Descending sorted N=";
        }
        if (sortType == "Random"){
            createVector(vec, vecSize[i], 0, 0);
            sortMethod = "Random N=";
        }
        for (int j = 0; j < 3; j++){
            // Calculate execution time
            if (sortAlgo[j] == "Selection"){
                auto start = high_resolution_clock::now();
                selectionSort(vec);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop - start);
                numSeconds = duration.count();
            }
            if (sortAlgo[j] == "Bubble"){
                auto start = high_resolution_clock::now();
                bubbleSort(vec);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop - start);
                numSeconds = duration.count();
            }
            if (sortAlgo[j] == "Insertion"){
                auto start = high_resolution_clock::now();
                insertionSort(vec);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                numSeconds = duration.count();
            }
            
            // Write to file
            if (sortAlgo[j] == "Selection"){
                outFileSelection << sortMethod << vecSize[i] << "," << fixed << setprecision(2) << numSeconds << "," << numDataComparisons << "," << numLoopComparisons;
                outFileSelection << "," << numDataAssignments << "," << numLoopAssignments << "," << numOther << "," << total << endl;
            }
            if (sortAlgo[j] == "Bubble"){
                outFileBubble << sortMethod << vecSize[i] << "," << fixed << setprecision(2) << numSeconds << "," << numDataComparisons << "," << numLoopComparisons;
                outFileBubble << "," << numDataAssignments << "," << numLoopAssignments << "," << numOther << "," << total << endl;
            }
            if (sortAlgo[j] == "Insertion"){
                outFileInsertion << sortMethod << vecSize[i] << "," << fixed << setprecision(2) << numSeconds << "," << numDataComparisons << "," << numLoopComparisons;
                outFileInsertion << "," << numDataAssignments << "," << numLoopAssignments << "," << numOther << "," << total << endl;
            }
        }
    }
}

void closeFile(ofstream& outFile){
    outFile.close();
}