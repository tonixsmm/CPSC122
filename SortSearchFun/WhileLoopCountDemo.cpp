# include <iostream>

using namespace std;

int main(){
    int count1 = 0, count2 = 0;
    int i = 0;
    count1++;
    while (i < 10) {
        count2++;
        i++;
    }

    cout << "count1: " << count1 << endl;
    cout << "count2: " << count2 << endl;
    return 0;
}