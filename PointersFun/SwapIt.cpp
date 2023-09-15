#include <iostream>

using namespace std;

// void * swapIt(int * a, int * b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void * swapIt(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int first = 10;
    int second = 12;

    swapIt(&first, &second);
    cout << first << " " << second << endl;

    return 0;
}