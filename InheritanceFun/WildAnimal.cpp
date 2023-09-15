#include "WildAnimal.h"

WildAnimal::WildAnimal() : Animal(){
    // Pet() is going to first invoke Animal() (aka DVC)
    cout << "Hello from WildAnimal()" << endl;
    // Initialize the Pet specific attribute name
    ferociousNoise = "default noise";
} // DVC
        
WildAnimal::WildAnimal(string noiseParam) : Animal(){
    cout << "Hello from WildAnimal(string)" << endl;
    ferociousNoise = noiseParam;
} // EVC

WildAnimal::WildAnimal(string speciesParam, int ageParam, string noiseParam) : Animal(speciesParam, ageParam){
    cout << "Hello from Pet(string, int, string)" << endl;
    ferociousNoise = noiseParam;
}

// Redefine more specific behaivor for toString()
string WildAnimal::toString(){
    return Animal::toString() + " that goes " + ferociousNoise;
}