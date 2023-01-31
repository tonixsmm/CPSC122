/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: January 30, 2022
Programming Assignment: PA1
Description: This program will convert a file from english to morse code and vice versa
Notes: The English text file and Morse strings file must have line feeds (e.g. press enter) at the end of each line
*/

#include "pa1.h"

int main(){
    
    // Declare variables
    ifstream inFile;
    ofstream outFile;
    string mode, fileNameRead, fileNameWrite;
    string morseStrings[91];
    char englishStrings[91];

    // Create arrays for morse and english
    morseEnglishArrays(morseStrings, englishStrings);

    // Choose mode
    chooseMode(mode, fileNameRead, fileNameWrite);

    // File processing
    openFile(inFile, outFile, fileNameRead, fileNameWrite);
    processFile(inFile, outFile, morseStrings, englishStrings, mode);
    closeFile(inFile, outFile);

    return 0;
}