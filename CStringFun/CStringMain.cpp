#include <iostream>
#include <cstring> //string.h in C

using namespace std;

int main(){
    // Generally, what's a string?
    // A string is a sequence of characters.
    // Ex: "winter"
    // In C++, we use the string type to work with them
    string season = "winter";
    cout << season << endl;

    // In C, we use c-string
    // Cstring is a null terminated char array
    // Null termninator character is \0 - a special way to denote the end of a cstring
    int arr[] = {2, 4};
    int size = 2;
    // 0 1 2 3 4 5 6
    // w i n t e r \0 // cstring
    // This means the array must have size + 1, so that there is a space for \0
    char season2[] = {'w', 'i', 'n', 't', 'e', 'r', '\0'}; // cstring is mutable, which means can be changed
    cout << season2 << endl;

    season2[0] = 'W';
    cout << season2 << endl; // Print out "Winter"
    int num[] = {3, 6, 9};
    cout << num << endl; // Print out "0x7ff7b98ce3a0"

    const char * season3 = "winter"; // immutable, which means cannot be changed
    // Have to make it a const cuz we cant change its memory address - read-only mode
    // Note that \0 can be omit in this case
    // The pointer notation replaces the array notation ([])
    cout << season3 << endl;

    char season4[20];
    // season4 = season2; // This is not allowed cuz season4 is string, and season2 is cstring
    // Use function for cstring in cstring!!
    strcpy(season4, season2); // Copy season2 to season4 
    cout << season4 << endl;
    
    // Compare two cstring
    // "winter" < "fall" // This will not work, cuz cstring are literally just pointers
    // Instead, we can use strcmp()
    cout << strcmp(season3, "fall") << endl; // 0 if equal, < 0 if arg1 < arg2, > 0 if arg2 < arg1

    cout << strlen(season2) << endl; // Print out the length of the string, not the array
    // Print out "6"
    cout << sizeof(season2) << endl; // Print out the size of the function
    // Print out "7" (+1 for \0)

    return 0;
}