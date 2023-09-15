#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>

using namespace std;

struct Fruit{
    string type; // apple, banana, etc.
    string color; // red, yellow, etc.
    double weight; // in ounces
};

void printFruit(const Fruit);
int compareFruits(Fruit *, Fruit *);

#endif