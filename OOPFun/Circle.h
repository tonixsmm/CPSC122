#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Point.h"

using namespace std;

class Circle {
    private:
        double radius;
        Point center; // Composition - Circle "has-a" Point
    public:
        Circle(); // DVC
        Circle(double, Point); // EVC
        Circle(double, double, double); // EVC
        // Circle(const Circle&); // TODO: Add copy constructor
        void display();
        // TODO: Add getters and setters
};

#endif