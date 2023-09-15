#include "Animal.h"
#include "Pet.h"
#include "WildAnimal.h"

int main() {
    Animal a;
    cout << a.toString() << endl;
    Animal d("dog", 4); //EVC
    cout << d.toString() << endl;

    // Recall the relationship of two classes
        // Composition is a "has-a" relationship
            // Circle has a Point
        // Inheritance is a "is-a" relationship between two classes where one class includes ("inherits") the state AND the behavior of the other class
        // State: attributes (aka member variables)
        // Behavior: member functions (constructor and destructor are not inherited)
    
    // Example
    // Animal is going to be a base class
    // Base class aka parent class aka super class
    // Pet is going to be a derived class aka child class aka sub class
    // The we eill come back to main and make a few Pet objects and exercise the inheritance hierarchy

    Pet p1; // DVC
    cout << p1.toString() << endl;
    Pet myPet("Dog", 7, "Odin"); // EVC
    cout << myPet.toString() << endl;

    // Let say we have a pointer to an Animal
    Animal * aPtr = &a;
    cout << aPtr->toString() << endl;
    /* TERMINAL
    a 0-year old default species
    */

    aPtr = &myPet;
    cout << aPtr->toString() << endl;
    /* TERMINAL
    a 7-year old Dog
    */
   // This is an example of static binding. At compile time, the compiler figures out which toString() to execute (Animal toString or the Pet toString())
   Pet * pPtr = &myPet;
   cout << "This is static binding" << endl;
   cout << pPtr->toString() << endl;
   // DYNAMIC BINDING
   // Figure out at runtime which toString() to execute
   // Need to use the "virtual" keyword to do this

    WildAnimal wa; // DVC
    cout << wa.toString() << endl;
    WildAnimal tiger("Tiger", 2, "Roar");
    cout << tiger.toString() << endl;

    // POLYMORPHISM: same code, different behavior
    // With a pointer or a reference to an object, we can call a virtual member function to get object 
    // specific behavior at runtome even the pointer or reference is of a more general type 
    // (e.g., super class such as Animal)
    // Example: array of Animal *
    // Some will point to Animal objects, some will point to Pet object, some point to WildAnimal objects
    // We will call toString() in a loop for each pointer
    // With dynamic binding we are going to get different behavior (e.g., Animal, Pet, or WildAnimal specific to toString()) with the same code (animalPtr->toString())
    Animal * animalPtrArr[4];
    animalPtrArr[0] = &a;
    animalPtrArr[1] = &myPet;
    animalPtrArr[2] = &tiger;
    animalPtrArr[3] = &d;

    for (Animal * animalPtr : animalPtrArr){
        // Same code for all objects pointed to
        cout << animalPtr->toString() << endl;
    }

    return 0;
}