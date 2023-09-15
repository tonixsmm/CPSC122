#include <iostream>
#include "Animal.h"

using namespace std;

class WildAnimal : public Animal {
    private:
        string ferociousNoise; // e.g., "roar", "grr", "hiss"
    public:
        WildAnimal();
        WildAnimal(string);
        WildAnimal(string, int, string);
        string toString();
};