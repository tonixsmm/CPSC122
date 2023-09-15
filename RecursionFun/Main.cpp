#include "Recursion.h"
#include "LinkedList.h"

int main(){
    iterativeCountdown(3);
    recursiveCountdown(3);

    cout << iterativeMultiplication(2, 3) << endl;
    cout << recursiveMultiplication(2, 3) << endl;

    cout << iterativePower(2, 3) << endl;
    cout << recursivePower(2, 3) << endl;

    cout << iterativeFactorial(3) << endl;
    cout << recursiveFactorial(3) << endl;

    displayString("hello");
    displayString("recursive");
    displayString("hello", 0);
    displayString("recursion", 0);

    displayStringReverse("hello");
    cout << endl;
    displayStringReverse("recursion");
    cout << endl;

    cout << countCharacters("hello") << endl;
    cout << countCharacters("recursion") << endl;

    writeSequence(1);
    writeSequence(2);
    writeSequence(3);
    writeSequence(4);
    writeSequence(5);
    writeSequence(6);

    return 0;
}