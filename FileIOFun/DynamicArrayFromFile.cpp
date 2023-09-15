#include <iostream>
#include <fstream>

using namespace std;

int countNumberOfIntFromFile(ifstream&);
void fillArray(ifstream& inFile, int * arr, int count);

int main(){
    ifstream inFile;
    inFile.open("nums.txt");
    // TODO: First, get a count for the number of ints in the file
    // then, perfectly allocate a dynamic array fit for the ints in the file
    // then fill the array from the file

    int count = 0, * arr = NULL;
    count = countNumberOfIntFromFile(inFile);
    cout << "Count: " << count << endl;
    
    arr = new int[count];

    inFile.clear();
    inFile.seekg(0, ios::beg);
    fillArray(inFile, arr, count);

    inFile.close();
    return 0;
}

int countNumberOfIntFromFile(ifstream& inFile){
    int count = 0, num = 0;
    inFile >> num;
    if (!inFile.bad()) {
        count++;
    }
    return count;
}

void fillArray(ifstream& inFile, int * arr, int count){
    for (int i = 0; i < count; i++){
        inFile >> arr[i];
        cout << arr[i] << endl;
    }
}