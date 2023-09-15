#include "Recursion.h"

void iterativeRecursion(int n){
    for (int i = n; i > 0; i--){
        cout << i << " ";
    }
    cout << "blastoff!!!" << endl;
}

void recursiveCountdown(int n){
    // Element of recursion
        // 1. Base case - no more recursion is appropriate
        // e.g., when n == 0
        if (n == 0){
            cout << "blassoff!!!" << endl;
            return;
        }
        // 2. Code to approach the base case - reformation of a similar yet smaller version of the problem (like "progress towards BC being false")
        // e.g., Print out n and call this function again with n - 1 (smaller version of problem, approaching 0)
        cout << n << " ";
        // Recursive call (aka step)
        recursiveCountdown(n - 1);
}

int iterativeMultiplication(int m, int n){
    // Multiply by adding m n times
    int sum = 0, i = 0;

    for (i = 0; i < n; i++){
        sum +=m;
    }
    return sum;
}

int recursiveMultiplication(int m, int n){
    // Multiplying by adding m n times
    if (n == 1){
        return m;
    }
    // Recursive step
    return m + recursiveMultiplication(m, n-1);
}

int iterativePower(int base, int exp){
    int prod = 1, i =0;

    for (i = 0; i < exp;i++){
        prod *= base;
    }
    return prod;
}

int recursivePower(int base, int exponent){
    if (exponent == 1){
        return base;
    }
    return base * recursivePower(base, exponent - 1);
}

int iterativeFactorial(int n){
    int result = 1, i = 1;

    for (i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int recursiveFactorial(int n){
    if (n == 1){
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}

void displayString(string s, int index){
    // Print string char by char
    // Base case
    if (index == s.length()){
        cout << endl;
        return;
    }
    // Print out the char at index
    cout << s.at(index) << " ";
    // Recursive step
    displayString(s, index + 1);
}

void displayString(string s){
    // Print string char by char
    if (s.length() == 0){
        cout << endl;
        return;
    }
    // "hello", "ello", "llo", "lo", "o", ""
    cout << s.at(0) << " "; // Print out the first char
    displayString(s.substr(1, s.length() - 1));
}

void displayStringReverse(string s){
    // Print string char by char
    if (s.length() == 0){
        return;
    }
    // o l l e h
    displayStringReverse(s.substr(1, s.length() - 1));
    cout << s.at(0) << " ";
}

int countCharacter(string s){
    // Print string char by char
    if (s.length() == 0){
        return 0;
    }
    // "hello", "ello", "llo", "lo", "o", ""
    return 1 + countCharacter(s.substr(1, s.length() - 1));
}

void fun(int n){
    if (n > 2){
        fun(n - 1);
        fun(n - 2);
        fun(n - 3);
    }
    cout << n << endl;
}

void moreFun(int n){
    cout << n << endl;
    if (n > 2){
        moreFun(n - 1);
        moreFun(n - 2);
        moreFun(n - 3);
    }
}

void writeSequence(int n){
    if (n % 2 == 0){
        writeSequenceHelper(n / 2, true);
    }
    else {
        writeSequenceHelper(n / 2 + 1, false);
    }
    cout << endl;
} 

void writeSequenceHelper(int n, bool even){
    // Base case
    if (n == 1 & even == true){
        cout << "1 1";
        return;
    }
    else if (n == 1 && even == false){
        cout << "1";
        return;
    }
    cout << n << " ";

    // Recursive step
    writeSequenceHelper(n - 1, even);
    
    // Make is symmetrical
    cout << n << " ";
}