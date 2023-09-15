#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
    private:
        double x;
        double y;
    public:
        Point(); // DVC
        Point(double x, double y); // EVC
        // TODO: Add a copy constructor
        // TODO: Dynamically allocate x and y and add a destructor
        void display();
        // TODO: add getters and setters
};

#endif