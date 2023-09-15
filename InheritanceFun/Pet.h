#ifndef PET_H
#define PET_H

#include <iostream>
#include "Animal.h"

using namespace std;

// Access specifier before the name of the base class to specify how public attributes of the base class are inherited
// Public attributes/member functions of Animal will be public in Pet
class Pet : public Animal {
    // We put Pet specific state and behavior
    private:
        string name;
    public:
        Pet(); // DVC
        Pet(string); // EVC
        Pet(string, int, string);
        // Redefine more specific behaivor for toString()
        string toString();
};

#endif