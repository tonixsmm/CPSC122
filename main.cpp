#include "pa2.h"

int main(){
    vector<int> vec;
    vector<int> sortedSelection;
    vector<int> sortedBubble;
    vector<int> sortedInsertion;

    createVector(vec, 10, 0, 0);
    printVector(vec);
    cout << "****" << endl;

    // sortedSelection = selectionSort(vec);
    // sortedBubble = bubbleSort(vec);
    sortedInsertion = insertionSort(vec);
    printVector(sortedInsertion);

    return 0;
}