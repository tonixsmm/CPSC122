/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: February 10, 2022
Programming Assignment: PA2
Description: This program implements several sorting algorithm to compare for efficiency
Note: I decided to use milliseconds instead of seconds for execution time measurement becuase it is more accurate
*/

#include "pa2.h"

int main(){
    // Declare variables
    ofstream outFileSelection, outFileBubble, outFileInsertion, outFileShell;

    // Open files
    openFile(outFileSelection, "selection_sort_results.csv");
    openFile(outFileBubble, "bubble_sort_results.csv");
    openFile(outFileInsertion, "insertion_sort_results.csv");
    openFile(outFileShell, "shell_sort_results.csv");

    // Sorted vectors
    algorithmAnalysis(outFileSelection, outFileBubble, outFileInsertion, outFileShell, "Sorted");
    // Descending sorted vectors
    algorithmAnalysis(outFileSelection, outFileBubble, outFileInsertion, outFileShell, "DescSorted");
    // Random vectors
    algorithmAnalysis(outFileSelection, outFileBubble, outFileInsertion, outFileShell, "Random");

    // Close files
    closeFile(outFileSelection);
    closeFile(outFileBubble);
    closeFile(outFileInsertion);
    closeFile(outFileShell);
    
    return 0;
}