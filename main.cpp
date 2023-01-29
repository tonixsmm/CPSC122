#include "pa1.h"

int main(){
    ifstream inFile;
    ofstream outFile;
    string mode, fileNameRead, fileNameWrite;

    chooseMode(mode, fileNameRead, fileNameWrite);
    openFile(inFile, outFile, fileNameRead, fileNameWrite);
    return 0;
}