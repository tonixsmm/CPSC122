/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: February 20, 2022
Programming Assignment: PA2
Description: This program implements several sorting algorithm to compare for efficiency
*/

#include "pa2.h"

/*
Function: openFile()
 * Date Created: 02/04/2022
 * Date Last Modified: 02/04/2022
 * Description: This function opens a file and checks if it is opened successfully
 * Input parameters: File stream and file name
 * Returns: None
 * Pre: User follows the command line instructions
 * Post: None
*/
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

/*
Function: createVector()
 * Date Created: 02/04/2022
 * Date Last Modified: 02/05/2022
 * Description: This function fills vector with randomly generated numbers
 * Input parameters: a vector, vector size, conditional arguments for sorting or descending sorting
 * Returns: None
 * Pre: a vector must be previously declared and passed by reference
 * Post: None
*/
void createVector(vector<int>& vec, int size, bool sorting, bool desc){
    // Not sorted
    for (int i = 0; i < size; i++){
        vec.push_back(rand() % size);
    }

    // Descending sorted
    if (sorting == 1 && desc == 1){
        sort(vec.begin(), vec.end(), greater<int>());
    }

    // Sorted
    else if (sorting == 1){
        sort(vec.begin(), vec.end());
    }
}

/*
Function: openFile()
 * Date Created: 02/06/2022
 * Date Last Modified: 02/06/2022
 * Description: This function swaps two integers
 * Input parameters: two integers
 * Returns: None
 * Pre: two intergers must be previously intialized and passed by reference
 * Post: None
 * Note: Adapted from Gaddis
*/
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

/*
Function: sortedChecking()
 * Date Created: 02/06/2022
 * Date Last Modified: 02/07/2022
 * Description: This function checks if a vector is sorted
 * Input parameters: a vector
 * Returns: boolean value of true or false
 * Pre: None
 * Post: None
*/
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

/*
Function: selectionSort()
 * Date Created: 02/09/2022
 * Date Last Modified: 02/10/2022
 * Description: This function performs selection sort
 * Input parameters: a vector and six variables for operation counting
 * Returns: None
 * Pre: all input parameters must be previously intialized and passed by reference
 * Post: None
*/
void selectionSort(vector<int> vec, long& dataComparisons, long& loopControlComparisons, long& dataAssignments, long& loopControlAssignments, long& other, long& total){
    int minValue, minIndex;
    other += 2; // for initialization of minIndex and minValue
    
    loopControlAssignments++; // for int i = 0
    for (int i = 0; i < (vec.size() - 1); i++){
        loopControlComparisons++; // for boolean condition evaluates to true
        loopControlAssignments++; // for i++

        minIndex = i;
        other++; // for minIndex assignment

        minValue = vec[i];
        dataAssignments++; // for minValue assignment

        loopControlAssignments++; // for int j = i + 1
        for (int j = i + 1; j < vec.size(); j++){
            loopControlComparisons++; // for boolean condition evaluates to true
            loopControlAssignments++; // for j++

            dataComparisons++; // for comparison of vec[j] and minValue
            if (vec[j] <= minValue){

                minValue = vec[j];
                dataAssignments++; // for minValue assignment

                minIndex = j;
                other++; // for minIndex assignment
            }
        }
        loopControlComparisons++; // for boolean condition evaluates to false
        
        swap(vec[minIndex], vec[i]);
        dataAssignments += 3; // for swap function, which has three operations
    }
    loopControlComparisons++; // for boolean condition evaluates to false

    // Calculate the total operations
    total = dataComparisons + loopControlComparisons + dataAssignments + loopControlAssignments + other;
}

/*
Function: bubbleSort()
 * Date Created: 02/09/2022
 * Date Last Modified: 02/10/2022
 * Description: This function performs bubble sort
 * Input parameters: a vector and six variables for operation counting
 * Returns: None
 * Pre: all input parameters must be previously intialized and passed by reference
 * Post: None
*/
void bubbleSort(vector<int> vec, long& dataComparisons, long& loopControlComparisons, long& dataAssignments, long& loopControlAssignments, long& other, long& total){
    int maxValue, maxIndex;
    other += 2; // for initialization of maxIndex and maxValue

    loopControlAssignments++; // for int maxValue = vec.size() - 1
    for (maxValue = vec.size() - 1; maxValue > 0; maxValue--){
        loopControlComparisons++; // for boolean condition evaluates to true
        loopControlAssignments++; // for maxValue--

        loopControlAssignments++; // for int maxIndex = 0
        for (maxIndex = 0; maxIndex < maxValue; maxIndex++){
            loopControlComparisons++; // for boolean condition evaluates to true
            loopControlAssignments++; // for maxIndex++

            dataComparisons++; // for comparison of vec[maxIndex] and vec[maxIndex + 1]
            if (vec[maxIndex] > vec[maxIndex + 1]){

                swap(vec[maxIndex], vec[maxIndex + 1]);
                dataAssignments += 3; // for swap function, which has three operations
            }
        }
        loopControlComparisons++; // for boolean condition evaluates to false

        dataComparisons++; // for comparison of sortedChecking(vec) and true
        if (sortedChecking(vec) == true){
            
            break;
            other++; // for break statement
        }
    }
    loopControlComparisons++; // for boolean condition evaluates to false

    // Calculate the total operations
    total = dataComparisons + loopControlComparisons + dataAssignments + loopControlAssignments + other;
}

/*
Function: insertionSort()
 * Date Created: 02/09/2022
 * Date Last Modified: 02/10/2022
 * Description: This function performs insertion sort
 * Input parameters: a vector and six variables for operation counting
 * Returns: None
 * Pre: all input parameters must be previously intialized and passed by reference
 * Post: None
*/
void insertionSort(vector<int> vec, long& dataComparisons, long& loopControlComparisons, long& dataAssignments, long& loopControlAssignments, long& other, long& total){
    int j, value;
    other += 2; // for initialization of j and value

    loopControlAssignments++; // for int i = 1
    for (int i = 1; i < vec.size(); i++){
        loopControlComparisons++; // for boolean condition evaluates to true
        loopControlAssignments++; // for i++

        value = vec[i];
        dataAssignments++; // for value assignment

        j = i - 1;
        other++; // for j assignment
        
        while (j >= 0 && value < vec[j]){
            loopControlComparisons += 2; // for boolean conditions evaluate to true

            vec[j + 1] = vec[j];
            dataAssignments++; // for vec[j + 1] assignment

            j--;
            loopControlAssignments++; // for j--
        }
        loopControlComparisons += 2; // for boolean conditions evaluate to false

        vec[j + 1] = value;
        dataAssignments++; // for vec[j + 1] assignment
    }
    loopControlComparisons++; // for boolean condition evaluates to false

    // Calculate the total operations
    total = dataComparisons + loopControlComparisons + dataAssignments + loopControlAssignments + other;
}

/*
Function: algorithmAnalysis()
 * Date Created: 02/09/2022
 * Date Last Modified: 02/10/2022
 * Description: This function acts as the driver function to perform operation counting and execution time measurement
 * Input parameters: File streams and a string for sort type
 * Returns: None
 * Pre: Three file streams must be previously intialized and passed by reference
 * Post: None
*/
void algorithmAnalysis(ofstream& outFileSelection, ofstream& outFileBubble, ofstream& outFileInsertion, string sortType){
    // Declare and initialize variables
    long dataComparisons = 0, loopControlComparisons = 0, dataAssignments = 0, loopControlAssignments = 0, other = 0, total = 0;
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
                selectionSort(vec, dataComparisons, loopControlComparisons, dataAssignments, loopControlAssignments, other, total);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop - start);
                numSeconds = duration.count();
            }
            if (sortAlgo[j] == "Bubble"){
                auto start = high_resolution_clock::now();
                bubbleSort(vec, dataComparisons, loopControlComparisons, dataAssignments, loopControlAssignments, other, total);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop - start);
                numSeconds = duration.count();
            }
            if (sortAlgo[j] == "Insertion"){
                auto start = high_resolution_clock::now();
                insertionSort(vec, dataComparisons, loopControlComparisons, dataAssignments, loopControlAssignments, other, total);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                numSeconds = duration.count();
            }
            
            // Write to file
            if (sortAlgo[j] == "Selection"){
                outFileSelection << sortMethod << vecSize[i] << "," << fixed << setprecision(2) << numSeconds << "," << dataComparisons << "," << loopControlComparisons;
                outFileSelection << "," << dataAssignments << "," << loopControlAssignments << "," << other << "," << total << endl;
            }
            if (sortAlgo[j] == "Bubble"){
                outFileBubble << sortMethod << vecSize[i] << "," << fixed << setprecision(2) << numSeconds << "," << dataComparisons << "," << loopControlComparisons;
                outFileBubble << "," << dataAssignments << "," << loopControlAssignments << "," << other << "," << total << endl;
            }
            if (sortAlgo[j] == "Insertion"){
                outFileInsertion << sortMethod << vecSize[i] << "," << fixed << setprecision(2) << numSeconds << "," << dataComparisons << "," << loopControlComparisons;
                outFileInsertion << "," << dataAssignments << "," << loopControlAssignments << "," << other << "," << total << endl;
            }
        }
    }
}

/*
Function: selectionSort()
 * Date Created: 02/04/2022
 * Date Last Modified: 02/14/2022
 * Description: This function closes the file
 * Input parameters: File stream
 * Returns: None
 * Pre: File stream must be previously intialized and passed by reference
 * Post: None
*/
void closeFile(ofstream& outFile){
    outFile.close();
}