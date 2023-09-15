#include "Circle.h"

Circle::Circle(){
    center = Point(); // Origin
    radius = 1.0; // Unit circle
}

Circle::Circle(double radiusParam, Point centerParam){
    center = centerParam;
    radius = radiusParam;
}

Circle::Circle(double radiusParam, double xParam, double yParam){
    center = Point(xParam, yParam);
    radius = radiusParam;
}

void Circle::display() {
    cout << "Circle with radius = " << radius << " and center = "; 
    center.display();
    cout << endl;
}