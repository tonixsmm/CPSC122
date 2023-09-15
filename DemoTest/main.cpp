#include <iostream>
#include <cstring>

using namespace std;

// void swap(int * a, int * b){
//     cout << a << " " << b << endl;
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     // cout << a << " " << b << endl;
// }

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool compareCString(char str1[], char str2[]){
    if (strcmp(str1, str2) == 0){
        return true;
    }
    return false;
}

void * strOps(void){
    string * myStr = new string;
    *myStr = "good";
    return myStr;
}

void swapMem(int * a, int * b){
    int * temp = a;
    a = b;
    b = temp;
}

void compute(int num1, int num2, int * sum, int * prod){
    *sum = num1 + num2;
    *prod = num1 * num2;
}

bool findNum(int * arr, int size, int numToFind){
    for (int i = 0; i < size; i++){
        if (*(arr + i) == numToFind){
            return true;
        }
    }
    return false;
}

void printArray(int * array, int size){
    for (int i = 0; i < size; i++){
        cout << *(array + i) << " ";
    }
    cout << endl;
}

void reverseArray(int * arr, int size){
    int temp = 0;
    for (int i = 0; i < static_cast<int>(size / 2); i++){
        swap(*(arr + i), *(arr + (size - 1 - i)));
    }
    printArray(arr, size);
}

void funZero(int a, int b) { 
	a = 1;
	b = 22; 
}

void funOne(int *a, int *b) { 
	*a = 11;
	*b = 2;
}

void funTwo(int a, int *b) {
	a = 3;
	*b = 42;
}

void dayProcessing(int * day, int * month, int * year){
    string userInput;

    cout << "Enter day mm/dd/yyyy" << endl;
    cin >> userInput;
}

int findSmallest(char values[], int low, int high)  {
    int smallestIndex, i;
    smallestIndex = low;
    for (i = low + 1; i <= high; i++)
        if (values[i] < values[smallestIndex])
            smallestIndex = i;
    return smallestIndex;
}

void selectionSort(char values[], int numValues) {
    int i, indexOfSmallest;
    char temp;
    for (i = 0; i < numValues - 2; ++i) {
        indexOfSmallest = findSmallest(values, i, numValues - 2);
        temp = values[i];
        values[i] = values[indexOfSmallest];
        values[indexOfSmallest] = temp;
    }
}


int main(){
    // int a = 1, b = 2;
    // int * aPtr = &a;
    // int * bPtr = &b;
    // cout << aPtr << " " << bPtr << endl;
    // swapMem(aPtr, bPtr);
    // cout << aPtr << " " << bPtr << endl;

    // int sum, prod;
    // compute(10, 12, &sum, &prod);
    // cout << sum << " " << prod;

    // int array[] = {1, 5, 3, 2, 7};
    // cout << findNum(array, 5, 3) << endl;

    // int arr[] = {0, 1, 2, 3, 4, 5};
    // printArray(arr, 6);
    // reverseArray(arr, 6);
    // printArray(arr, 6);

    // int i = 3, j = 5, k;
    // int * p = &i, * q = &j, *r;
    // r = &k;
    // *r = *p * *q;

    // cout << i << " " << j << " " << k << endl;
    // cout << *p << " " << *q << " " << *r << endl;
    // cout << &i << " " << &j << " " << &k << endl;
    // cout << p << " " << q << " " << r << endl;

    // int a = 9, b = 12;

	// cout << "a: " << a << "b: " << b << endl;
	// funZero(a, b);
	// cout << "a: " << a << "b: " << b << endl;

	// funOne(&a, &b);
	// cout << "a: " << a << "b: " << b << endl;

	// funTwo(a, &b);
	// cout << "a: " << a << "b: " << b << endl;

    // char elem;
    // cin >> elem;
    // char * charp = &elem;

    // double arr[100];
    // double * myNum = new double[100];
    // myNum = arr;
    // delete [] myNum;

    // char * str = "Hello";
    // char * myStr = new char[6];
    // // strcpy(myStr, str);
    // // str = myStr;
    // strcpy(myStr, str);
    // // printArray(str, 6);
    // cout << myStr;
    // delete [] myStr;
    // myStr = nullptr;

    char str[] = "Bill Gates";
    
    for (int i = 0; i < strlen(str); i++){
        cout << str[i] << endl;
    }

    selectionSort(str, 11);
    cout << "After";
    for (int i = 0; i < strlen(str); i++){
        cout << str[i] << endl;
    }

    return 0;
}