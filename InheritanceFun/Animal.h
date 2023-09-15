#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal {
    // Access specifier (aka modifiers)
    // Private: accessible within this class only
    // Public: accessible anywhere (like in main)
    // Protected: accessible within this class and its subclasses
    protected:
        string species;
        int age;
    public:
        Animal(); // DVC
        Animal(string, int); //EVC
        virtual string toString(); 
        // virtual means to use dynamic binding to figure out which toString() to execute at run time (base class toString() or the derived class toString())
};

#endif