#include "pa1.h"

int main(){
    ifstream inFile;
    ofstream outFile;
    string mode, fileNameRead, fileNameWrite;
    string morseStrings[91];
    char englishStrings[91];

    morseEnglishArrays(morseStrings, englishStrings);
    chooseMode(mode, fileNameRead, fileNameWrite);
    openFile(inFile, outFile, fileNameRead, fileNameWrite);

    

    return 0;
}