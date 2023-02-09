#include "pa2.h"

int main(){
    // Declare and create original sorted vectors
    vector<int> sorted500 = createVector(sorted500, 500, 1, 0);
    vector<int> sorted1000 = createVector(sorted1000, 1000, 1, 0);
    vector<int> sorted5000 = createVector(sorted5000, 5000, 1, 0);
    vector<int> sorted10000 = createVector(sorted10000, 10000, 1, 0);

    // Declare and create original sorted descending vectors
    vector<int> sortedDescending500 = createVector(sortedDescending500, 500, 1, 1);
    vector<int> sortedDescending1000 = createVector(sortedDescending1000, 1000, 1, 1);
    vector<int> sortedDescending5000 = createVector(sortedDescending5000, 5000, 1, 1);
    vector<int> sortedDescending10000 = createVector(sortedDescending10000, 10000, 1, 1);

    // Declare and create original random vectors
    vector<int> random500 = createVector(random500, 500, 0, 0);
    vector<int> random1000 = createVector(random1000, 1000, 0, 0);
    vector<int> random5000 = createVector(random5000, 5000, 0, 0);
    vector<int> random10000 = createVector(random10000, 10000, 0, 0);

    return 0;
}