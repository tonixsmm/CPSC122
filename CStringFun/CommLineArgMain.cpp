#include <iostream>
#include <cstring>

using namespace std;

void printArray(char * arr, int size);

// argc stores the count of how many args there are, +1 for the name of the program
// argv is an array of cstring, with each args stored in argv as a cstring
int main(int argc, char * argv[]){
    // String is a sequence of characters
    // In C++, we use the string type/class to work with them
    string name = "tony"; // C++ string
    // Cstring is an aeeay of chars that is null terminated
    // The last characyer in the array is \0
    // Note that we need an additional space for the \0 in cstring

    // Reading the command line arguments
    cout << "argc: " << argc << endl;
    cout << "argv[0]: " << argv[0] << endl;

    for (int i = 0; i < argc; i++){
        cout << endl;
        cout << "i: " << i << endl;
        cout << "argv[i]: " << argv[i] << endl;
        /*
        Print out:
        i: 0
        argv[i]: ./a.out

        i: 1
        argv[i]: source.txt

        i: 2
        argv[i]: destination.txt
        */

       printArray(argv[i], strlen(argv[i]));
       /*
       Print out example:
       d e s t i n a t i o n . t x t 
       */
    }

    return 0;
}

void printArray(char * arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}