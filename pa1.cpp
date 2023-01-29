#include "pa1.h"

void chooseMode(char& mode, string& fileNameRead, string& fileNameWrite){
    cout << "Please enter the mode you'd like to use using the following command:" << endl;;
    cout << "English to Morse mode: -m [ENGLISH FILENAME] [MORSE FILENAME]" << endl;
    cout << "Morse to English mode: -t [MORSE FILENAME] [ENGLISH FILENAME]" << endl;

    cin >> mode >> fileNameRead >> fileNameWrite;
}

void openFile(ifstream& inFile, ofstream& outFile, string fileNameRead, string fileNameWrite){
    inFile.open(fileNameRead);
    outFile.open(fileNameWrite, ios::app);

    if (inFile.good()){
        cout << "Successfully opened " << fileNameRead << endl;
    }
    else{
        cout << "Failed to open " << fileNameRead << endl;
        exit(-1);
    }

    if (outFile.good()){
        cout << "Successfully opened " << fileNameWrite << endl;
    }
    else{
        cout << "Failed to open " << fileNameWrite << endl;
        exit(-1);
    }
}

void processFile(ifstream& inFile, ofstream& outFile, string fileName){

}