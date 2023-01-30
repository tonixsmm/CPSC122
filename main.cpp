#include "pa1.h"

int main(){
    ifstream inFile;
    ofstream outFile;
    string mode, fileNameRead, fileNameWrite;
    string morseStrings[91];
    char englishStrings[91];

    morseEnglishArrays(morseStrings, englishStrings);
    chooseMode(mode, fileNameRead, fileNameWrite);

    // mode = "-t";
    // fileNameRead = "morse.txt";
    // fileNameWrite = "english.txt";

    openFile(inFile, outFile, fileNameRead, fileNameWrite);
    processFile(inFile, outFile, morseStrings, englishStrings, mode);

    inFile.close();
    outFile.close();

    return 0;
}