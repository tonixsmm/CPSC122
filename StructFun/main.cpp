#include "struct.h"

int main(){
    // A struct is a programmer defined collection of data member
    // Structs are defined in header files
    // Note that no memory is allocated for a definition
    // Create Fruit variables. Now memory will be allocated
    Fruit myFruit = {"kiwi", "brown", 2.5};

    // cout << myFruit << endl; // This won't work
    // Can't use < and Fruit until we overload the << to work with Fruit
    // We can access individual members using the dot(.) operator
    cout << myFruit.type << endl;
    
    // Define a function that accepts a Fruit and prints out which labels the values of all the Fruit members
    printFruit(myFruit);

    // Pointers to struct
    Fruit * myFruitPtr = &myFruit;
    // cout << *myFruitPtr.type << endl; // This won't work
    // This does not compile because the [.] has higher priority than the *
    cout << (*myFruitPtr).type << endl; // This works

    // The -> operator, or indirect member selection operator
    // Dereference the pointer and select from the struct it points to
    cout << myFruitPtr->type << endl; // This works

    // Structs are pass by value
    // Struct assignment is okay. It makes a copy
    Fruit myOtherFruit = myFruit;
    myOtherFruit.type = "apple";
    printFruit(myFruit);
    printFruit(myOtherFruit);

    // How do we compare fruits?
    Fruit myFruitArr[10];
    // If this is a normal array, we can use relational opperator < > == != <= >=
    // Define a function that takes two fruits and returns a negative number if the first fruit is less than the second fruit
    // and 1 if the second fruit is less than the first fruit, or 0 if they are equal
    cout << compareFruits(&myFruit, &myOtherFruit) << endl;

    Fruit * myDynFruitArr = new Fruit[20];
    // Be sure to zero out memory
    // Be sure to free this memory

    return 0;
}