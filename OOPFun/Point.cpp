#include "Point.h"

// DVC
Point::Point(){
    x = 0.0;
    y = 0.0;
}

// EVC
Point::Point(double xParam, double yParam){
    x = xParam;
    y = yParam;
}

void Point::display(){
    cout << "(" << x << ", " << y << ")" << endl;
}