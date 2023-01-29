#ifndef PA1_H
#define PA1_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void chooseMode(string& mode, string& fileNameRead, string& fileNameWrite);
void openFile(ifstream& inFile, ofstream& outFile, string fileNameRead, string fileNameWrite);
void processFile(ifstream& inFile, ofstream& outFile, string fileName);

#endif