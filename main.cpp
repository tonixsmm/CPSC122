/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: February 20, 2022
Programming Assignment: PA2
Description: This program implements several sorting algorithm to compare for efficiency
*/

#include "pa2.h"

int main(){
    // Declare variables
    ofstream outFileSelection;
    ofstream outFileBubble;
    ofstream outFileInsertion;

    // Open files
    openFile(outFileSelection, "selection_sort_results.csv");
    openFile(outFileBubble, "bubble_sort_results.csv");
    openFile(outFileInsertion, "insertion_sort_results.csv");

    // Sorted vectors
    algorithmAnalysis(outFileSelection, outFileBubble, outFileInsertion, "Sorted");
    // Descending sorted vectors
    algorithmAnalysis(outFileSelection, outFileBubble, outFileInsertion, "DescSorted");
    // Random vectors
    algorithmAnalysis(outFileSelection, outFileBubble, outFileInsertion, "Random");

    // Close files
    closeFile(outFileSelection);
    closeFile(outFileBubble);
    closeFile(outFileInsertion);

    return 0;
}