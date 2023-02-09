#include "pa2.h"

int main(){
    ofstream outFile;

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

    // Driver function
    // Selection sort
    openFile(outFile, "selection_sort_results.csv");
    outFile << "Vector configuration,Seconds,# Data Comparisons,# Loop Comparisons,# Data Assignments,# Loop Assignments,# Other,# Total" << endl;

    driverFunction(sorted500, outFile, "selection", "Sorted N = 500");
    driverFunction(sorted1000, outFile, "selection", "Sorted N = 1000");
    driverFunction(sorted5000, outFile, "selection", "Sorted N = 5000");
    driverFunction(sorted10000, outFile, "selection", "Sorted N = 10000");

    driverFunction(sortedDescending500, outFile, "selection", "Descending sorted N = 500");
    driverFunction(sortedDescending1000, outFile, "selection", "Descending sorted N = 1000");
    driverFunction(sortedDescending5000, outFile, "selection", "Descending sorted N = 5000");
    driverFunction(sortedDescending10000, outFile, "selection", "Descending sorted N = 10000");

    driverFunction(random500, outFile, "selection", "Random N = 500");
    driverFunction(random1000, outFile, "selection", "Random N = 1000");
    driverFunction(random5000, outFile, "selection", "Random N = 5000");
    driverFunction(random10000, outFile, "selection", "Random N = 10000");

    closeFile(outFile);

    // Bubble sort
    openFile(outFile, "bubble_sort_results.csv");
    outFile << "Vector configuration,Seconds,# Data Comparisons,# Loop Comparisons,# Data Assignments,# Loop Assignments,# Other,# Total" << endl;

    driverFunction(sorted500, outFile, "bubble", "Sorted N = 500");
    driverFunction(sorted1000, outFile, "bubble", "Sorted N = 1000");
    driverFunction(sorted5000, outFile, "bubble", "Sorted N = 5000");
    driverFunction(sorted10000, outFile, "bubble", "Sorted N = 10000");

    driverFunction(sortedDescending500, outFile, "bubble", "Descending sorted N = 500");
    driverFunction(sortedDescending1000, outFile, "bubble", "Descending sorted N = 1000");
    driverFunction(sortedDescending5000, outFile, "bubble", "Descending sorted N = 5000");
    driverFunction(sortedDescending10000, outFile, "bubble", "Descending sorted N = 10000");

    driverFunction(random500, outFile, "bubble", "Random N = 500");
    driverFunction(random1000, outFile, "bubble", "Random N = 1000");
    driverFunction(random5000, outFile, "bubble", "Random N = 5000");
    driverFunction(random10000, outFile, "bubble", "Random N = 10000");

    closeFile(outFile);

    // Insertion sort
    openFile(outFile, "insertion_sort_results.csv");
    outFile << "Vector configuration,Seconds,# Data Comparisons,# Loop Comparisons,# Data Assignments,# Loop Assignments,# Other,# Total" << endl;

    driverFunction(sorted500, outFile, "insertion", "Sorted N = 500");
    driverFunction(sorted1000, outFile, "insertion", "Sorted N = 1000");
    driverFunction(sorted5000, outFile, "insertion", "Sorted N = 5000");
    driverFunction(sorted10000, outFile, "insertion", "Sorted N = 10000");

    driverFunction(sortedDescending500, outFile, "insertion", "Descending sorted N = 500");
    driverFunction(sortedDescending1000, outFile, "insertion", "Descending sorted N = 1000");
    driverFunction(sortedDescending5000, outFile, "insertion", "Descending sorted N = 5000");
    driverFunction(sortedDescending10000, outFile, "insertion", "Descending sorted N = 10000");

    driverFunction(random500, outFile, "insertion", "Random N = 500");
    driverFunction(random1000, outFile, "insertion", "Random N = 1000");
    driverFunction(random5000, outFile, "insertion", "Random N = 5000");
    driverFunction(random10000, outFile, "insertion", "Random N = 10000");

    closeFile(outFile);

    return 0;
}