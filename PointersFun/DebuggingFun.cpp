#include <iostream>

using namespace std;

int * doBadThings(){
    int localVar = 5; // resides in the stack area of the memory
    // NEVER want to return the mem addr of a local variable cuz when function exits, local variables in stack are deallocated
    return &localVar;
}

int main(){
    int * intPtr = new int[10];
    *intPtr = 7;

    cout << *intPtr << endl;
    //done with what intPtr points to ... but forget to free it
    // compile with -g for compiling with debug symbol
    // valgrind --leak-check=yes ./a.out

    // delete [] intPtr;
    intPtr = NULL;

    int * badPtr = NULL;
    badPtr = doBadThings();
    cout << *badPtr << endl;

    return 0;
}