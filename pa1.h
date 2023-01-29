#ifndef PA1_H
#define PA1_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void chooseMode(string& mode, string& fileNameRead, string& fileNameWrite);
void openFile(ifstream& inFile, ofstream& outFile, string fileNameRead, string fileNameWrite);
void processFile(ifstream& inFile, ofstream& outFile, string fileName, string mode);
void morseEnglishArrays(string morseStrings[91], char englishStrings[91]);

#endif