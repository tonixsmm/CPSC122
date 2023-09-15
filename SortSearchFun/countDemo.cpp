#include <iostream>

using namespace std;

void selectionSortArrayGaddis(int array[], int size, long &dataComparisons, long &loopControlComparisions, long &dataAssignments, long &loopControlAssignments, long &other) {
    int minIndex, minValue;
    other += 2; //for initialization of minIndex, maxIndex

    loopControlAssignments++; // for int start = 0
    for (int start = 0; start < (size - 1); start++) {
        loopControlComparisions++; // for boolean condition eval to true
        loopControlAssignments++; // for start++;

        minIndex = start;
        other++; // for minIndex assignment. start does not store a value in an array
        
        minValue = array[start];
        dataAssignments++; // for minValue assignment

        loopControlAssignments++; // for int index = start + 1
        for (int index = start + 1; index < size; index++) {
            loopControlComparisions++; // for inner for loop boolean condition eval to true
            loopControlAssignments++; // for index++

            dataComparisons++; // for if boolean condition
            if (array[index] < minValue) {

                minValue = array[index];
                dataAssignments++; // for minValue assignment

                minIndex = index;
                other++; // for minIndex assignment

            }
        }
        // swap(array[minIndex], array[start]);
    }
    loopControlComparisions++; // for boolean condition eval to false
    dataAssignments += 3; // for swap, which has 3 ops
}

int main(){
    long dataComparisons = 0, loopControlComparisions = 0, dataAssignments = 0, loopControlAssignments = 0, other = 0;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    selectionSortArrayGaddis(array, 10, dataComparisons, loopControlComparisions, dataAssignments, loopControlAssignments, other);
    
    cout << "dataComparisons: " << dataComparisons << endl;
    cout << "loopControlComparisions: " << loopControlComparisions << endl;
    cout << "dataAssignments: " << dataAssignments << endl;
    cout << "loopControlAssignments: " << loopControlAssignments << endl;
    cout << "other: " << other << endl;
    cout << "total: " << dataComparisons + loopControlComparisions + dataAssignments + loopControlAssignments + other << endl;
    return 0;
}