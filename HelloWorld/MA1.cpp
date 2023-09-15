// Tony Nguyen
// Dr. Gina Sprint
// CPSC 122 01
// 1/26/2022
// Mini Assignment 1

# include <iostream>
# include <fstream>

using namespace std;

// Function headers
void openFile(ifstream&, string);
int readNum(ifstream&, int array[10]);
void printNum(int array[10], int);
void reverseArray(int array[10], int);

int main(){
    // Declare array
    int numArray[10];

    // Open file
    ifstream inFile;
    openFile(inFile, "numbers.txt");

    // Read numbers
    int count = readNum(inFile, numArray);

    // Print numbers
    printNum(numArray, count);

    // Reverse numbers
    reverseArray(numArray, count);

    // Open file
    inFile.close();
}

// This function open a file and check if it opens successfully
void openFile(ifstream& inFile, string fileName){
    inFile.open(fileName);
    if (inFile.is_open()){
        cout << "Open successfully" << endl;
    }
    else {
        cout << "Failed to open file" << endl;
        exit(-1);
    }
}

// This function reads numbers from a file and save it to an array
int readNum(ifstream& inFile, int array[10]){
    int numFromFile;
    int count = 0;

    while (!inFile.eof()){
        inFile >> numFromFile;
        array[count] = numFromFile;
        count++;
    }

    return count;
}

// This function prints numbers from an array
void printNum(int array[10], int size){
    for (int i = 0; i < size; i++){
        if (i != size - 1){
            cout << array[i] << ", ";
        }
        else {
            cout << array[i] << endl;
        }
    }
}

// This function reverses an array and print the reversed array
void reverseArray(int array[10], int size){
    int arrayTemp[10];
    int k = 0;

    // Create a copy of the array
    for (int i = 0; i < size; i++){
        arrayTemp[k] = array[i];
        k++;
    }

    // Reverse the array
    for (int i = 0; i < size; i++){
        array[i] = arrayTemp[size - 1 - i];
    }

    // Print the reversed array
    printNum(array, size);
}