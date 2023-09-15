#ifndef CITY_H
#define CITY_H

#include <iostream>

using namespace std;

struct Measurement{
    int miles;
    long meters;
};

struct Destination{
    string city;
    Measurement distance;
};

void display(Destination);

#endif