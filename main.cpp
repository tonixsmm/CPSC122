#include "pa2.h"

int main(){
    // Declare and create original sorted vectors
    vector<int> sorted500;
    vector<int> sorted1000;
    vector<int> sorted5000;
    vector<int> sorted10000;

    // Declare original sorted descending vectors
    vector<int> sortedDescending500;
    vector<int> sortedDescending1000;
    vector<int> sortedDescending5000;
    vector<int> sortedDescending10000;

    // Declare original random vectors
    vector<int> random500;
    vector<int> random1000;
    vector<int> random5000;
    vector<int> random10000;

    // Create original sorted vectors
    createVector(sorted500, 500, 1, 0);
    createVector(sorted1000, 1000, 1, 0);
    createVector(sorted5000, 5000, 1, 0);
    createVector(sorted10000, 10000, 1, 0);

    // Create original sorted descending vectors
    createVector(sortedDescending500, 500, 1, 1);
    createVector(sortedDescending1000, 1000, 1, 1);
    createVector(sortedDescending5000, 5000, 1, 1);
    createVector(sortedDescending10000, 10000, 1, 1);

    // Declare original random vectors
    createVector(random500, 500, 0, 0);
    createVector(random1000, 1000, 0, 0);
    createVector(random5000, 5000, 0, 0);
    createVector(random10000, 10000, 0, 0);

    

    return 0;
}