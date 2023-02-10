#include "pa2.h"

int main(){
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

    closeFile(outFileSelection);
    closeFile(outFileBubble);
    closeFile(outFileInsertion);

    return 0;
}