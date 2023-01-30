#ifndef PA1_H
#define PA1_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

void chooseMode(string& mode, string& fileNameRead, string& fileNameWrite);
void openFile(ifstream& inFile, ofstream& outFile, string fileNameRead, string fileNameWrite);
void processFile(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91], string mode);
void morseEnglishArrays(string morseStrings[91], char englishStrings[91]);
void searchReplace(ofstream& outFile, string morseStrings, char englishStrings[91], string mode, string word, char character = '\0');
int englishToMorse(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91]);
int morsetoEnglish(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91]);

#endif