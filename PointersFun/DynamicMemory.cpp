#include <iostream>

using namespace std;

void printArray(int * arr, int size);
int * createRandomArray(int size);
void * swapIt(int * a, int * b);

int main(){
    // local variables are located in a region of memory called the "stack"
    // when a function exits, the stack area that was used by the function is deallocated
    // NEVER return the memory addr of a local variable
    // GOAL: return the memory addr of memory in the "heap"
    // "heap" are is not deallocated when a function exits but deallocated when you deallocated it (freeing memory)

    // we want a function to allocate memory for an array of random numbers
    // we use the new and delete keyword to dynamically allocate memory
    // we will use these in the function to allocate memory on the heap
    int * randArr = NULL;
    randArr = createRandomArray(10);
    printArray(randArr, 10);
    // NOTE: we need to free aka deallocate randArr when we done with it
    // we have a memory leak unless we free randArr's memory on the heap
    delete [] randArr;
    // good practice to set the pointer to NULL or to nullptr
    randArr = NULL;

    return 0;
}

void printArray(int * arr, int size){
    for (int i = 0; i < size; i++){
        cout << *(arr + i) << " "; // pointer notation
    }
    cout << endl;
}

int * createRandomArray(int size){
    int * arr = new int[size]; // on the heap
    for (int i = 0; i < size; i++){
        *(arr + i) = rand() % size;
    }
    return arr; // NOTE: it is the calling code's respoinsibility to free this memory
}

void * swapIt(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}