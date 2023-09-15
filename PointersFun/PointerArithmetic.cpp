#include <iostream>

using namespace std;

void printArray(int arr[], int size);
void printArrayNew(int * arr, int size); // using pointers


int main(){
    // an array stores the memory addr of the first elem of the array
    int nums[] = {5, 2, 8, 6}; // 16 contiguously (next to each other) allocated bytes
    int size = 4;

    cout << nums << endl;
    cout << &(nums[0]) << endl;
    cout << &(nums[1]) << endl;
    cout << &(nums[2]) << endl;
    cout << &(nums[3]) << endl;

    // printArray(nums, size);
    printArrayNew(nums, size);

    return 0;
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArrayNew(int * arr, int size){
    for (int i = 0; i < size; i++){
        cout << *(arr + i) << " "; // pointer notation
        // values of i...
        // i = 0, 1, 2, 3
        // ints are 4 bytes
        // the offset added to arr is the size of the memory cell times the offset to get the total byte
        /* TERMINAL OUTPUT:
        0x7ff7bd3a6340
        0x7ff7bd3a6344
        0x7ff7bd3a6348
        0x7ff7bd3a634c
        5 2 8 6 
        */
    }
    cout << endl;
}