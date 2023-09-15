#include "Pet.h"

Pet::Pet() : Animal(){
    // Pet() is going to first invoke Animal() (aka DVC)
    cout << "Hello from Pet()" << endl;
    // Initialize the Pet specific attribute name
    name = "default name";
} // DVC
        
Pet::Pet(string nameParam) : Animal(){
    cout << "Hello from Pet(string)" << endl;
    name = nameParam;
} // EVC

Pet::Pet(string speciesParam, int ageParam, string nameParam) : Animal(speciesParam, ageParam){
    cout << "Hello from Pet(string, int, string)" << endl;
    name = nameParam;
}

// Redefine more specific behaivor for toString()
string Pet::toString(){
    return Animal::toString() + " named " + name;
}