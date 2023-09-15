#include <iostream>

using namespace std;

void divide(int num, int den, int * res, int * rem);

int main(){
    // pointer: a variable that stores as its contents the memory address of another variable
    // Examples
    /*
    NAME    TYPE    MEM ADDR    CONTENTS
    x       int     0x2000      5 -> 7 -> 10
    xPtr    int *   0x2004      NULL -> 0x2000
    */
    
    int x = 5; // "x is assigned 5"

    // declare a pointer to an int
    // pointers must have a type to point to. eg. int, float, etc
    int * xPtr = NULL; // NULL means invalid (0)
    // "this reads as the pointer to int xPtr is assigned null"

    // 2 ways to modify the contents of x
    // 1. directly via x
    x = 7;
    // 2. indirectly via xPtr
    // we want xPtr to point to x, so we have xPtr store the mem addr of x
    xPtr = &x; // & address of operator
    // read as "xPtr is assigned the address of x"

    // follow the xPtr to x
    *xPtr = 10;
    // read as "the content of what xPtr points to is assigned 10"
    // * is the unary indirection operator and it "dereferences" a pointer

    cout << "x: " << x << endl;
    cout << "*xPtr: " << *xPtr << endl;
    cout << "&x: " << &x << endl;
    cout << "xPtr: " << xPtr << endl;

    // 3 different uses of the * in C/C++
    // 1. Multiplication operator
    // e.g. x * 2
    // 2. pointer type
    // e.g. int * xPtr
    // 3. unary indirection operator
    // e.g. *xPtr = 5;

    // 2 differences uses of the & in C/C++
    // 1. declaration of a reference variable
    // e.g. int & xREF = x; // make an alias
    // 2. adress of operator
    // e.g. char * charPtr = &myChar;

    // OUTPUT PARAMETERS
    // With the return statement, a function can return a value
    // Output parameter is a parameter that "returns a value" from the function

    // 2 ways to do this
    // 1. pass by reference variable function
    // e.g. int &result
    // 2. via a pointer
    
    // example
    // a function called divide() that accepts two ints, and returns their result of division and remainder
    int result, remainder;
    // what is in scope of main()?
    // int results CONTENTS ?->1 ADDR 0x2000
    // int remainder CONTENTS ?->2 ADDR 0x3000
    divide(13, 11, &result, & remainder);
    cout << "result: " << result << endl;
    cout << "remainder: " << remainder << endl;

    return 0;
}

void divide(int num, int den, int * res, int * rem){
    *res = num / den; // int div
    // the content of whatvres points to is assigned num divided by den
    *rem = num % den; // mod
    // the content of what rem points to is assigned num mod den

    // what is the scope of divide()?
    // int num CONTENTS 13
    // int den CONTENTS 11
    // int * res CONTENTS 0x2000
    // int * rem CONTENTS 0x3000
}