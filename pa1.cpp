#include "pa1.h"

void chooseMode(string& mode, string& fileNameRead, string& fileNameWrite){
    cout << "Please enter the mode you'd like to use using the following command:" << endl;;
    cout << "English to Morse mode: -m [ENGLISH FILENAME] [MORSE FILENAME]" << endl;
    cout << "Morse to English mode: -t [MORSE FILENAME] [ENGLISH FILENAME]" << endl;

    cin >> mode >> fileNameRead >> fileNameWrite;
}

void openFile(ifstream& inFile, ofstream& outFile, string fileNameRead, string fileNameWrite){
    inFile.open(fileNameRead);
    outFile.open(fileNameWrite, ios::out);

    if (inFile.is_open()){
        cout << "Successfully opened " << fileNameRead << endl;
    }
    else{
        cout << "Failed to open " << fileNameRead << endl;
        exit(-1);
    }

    if (outFile.is_open()){
        cout << "Successfully opened " << fileNameWrite << endl;
    }
    else{
        cout << "Failed to open " << fileNameWrite << endl;
        exit(-1);
    }
}

void morseEnglishArrays(string morseStrings[91], char englishStrings[91]){

    // english characters using ascii
    char orgChar = ' ';
    for (int i = 32; i < 91; i++){
        englishStrings[i] = orgChar;
        orgChar++;
    }
    
    // numbers to morse
    morseStrings[48] = "----";
    morseStrings[49] = ".----";
    morseStrings[50] = "..---";
    morseStrings[51] = "...--";
    morseStrings[52] = "....-";
    morseStrings[53] = ".....";
    morseStrings[54] = "-....";
    morseStrings[55] = "--...";
    morseStrings[56] = "---..";
    morseStrings[57] = "----.";

    // letters to morse
    morseStrings[65] = ".-";
    morseStrings[66] = "-...";
    morseStrings[67] = "-.-.";
    morseStrings[68] = "-..";
    morseStrings[69] = ".";
    morseStrings[70] = "..-.";
    morseStrings[71] = "--.";
    morseStrings[72] = "....";
    morseStrings[73] = "..";
    morseStrings[74] = ".---";
    morseStrings[75] = "-.-";
    morseStrings[76] = ".-..";
    morseStrings[77] = "--";
    morseStrings[78] = "-.";
    morseStrings[79] = "---";
    morseStrings[80] = ".--.";
    morseStrings[81] = "--.-";
    morseStrings[82] = ".-.";
    morseStrings[83] = "...";
    morseStrings[84] = "-";
    morseStrings[85] = "..-";
    morseStrings[86] = "...-";
    morseStrings[87] = ".--";
    morseStrings[88] = "-..-";
    morseStrings[89] = "-.--";
    morseStrings[90] = "--..";

    // punctuation to morse
    morseStrings[33] = "..--.";
    morseStrings[34] = ".-..-.";
    morseStrings[39] = ".----.";
    morseStrings[40] = "-.--.";
    morseStrings[41] = "-.--.-";
    morseStrings[42] = "-..-";
    morseStrings[43] = ".-.-.";
    morseStrings[44] = "--..--";
    morseStrings[45] = "-....-";
    morseStrings[46] = ".-.-.-";
    morseStrings[47] = "-..-.";
    morseStrings[58] = "---...";
    morseStrings[59] = "-.-.-.";
    morseStrings[61] = "-...-";
    morseStrings[63] = "..--..";

    // line feed
    morseStrings[10] = '\n';
    
}

void searchReplace(ofstream& outFile, string morseStrings[91], char englishStrings[91], string mode, string word, char character){
    if (mode == "-m"){
        for (int i = 0; i < 91; i++){
            if (character == englishStrings[i]){
                outFile << morseStrings[i] << " ";
            }
        }
    }
    if (mode == "-t"){
        for (int i = 0; i < 91; i++){
            if (word == morseStrings[i]){
                outFile << (char)tolower(englishStrings[i]);
            }
        }
    }
}

int englishToMorse(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91]){
    string line, word;
    istringstream iss;
    static int charCount = 0;

    getline(inFile, line);
    if (inFile.good()){
        iss.clear();
        iss.str(line);
        while (iss.good()){
            iss >> word;
            for (char c : word){
                searchReplace(outFile, morseStrings, englishStrings, "-m", word, toupper(c));
            }
            outFile << " ";
        }
        charCount += line.length();
    }
    return charCount;
}

int morseToEnglish(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91]){
    string line, word;
    istringstream iss;
    static int charCount = 0;

    getline(inFile, line);
    for (int i = 0; i <= line.length(); i++){ //https://stackoverflow.com/questions/2341759/how-to-find-the-location-of-two-consecutive-spaces-in-a-string
        if (line.find("  ") != string::npos){
            line.replace(line.find("  "), 2, " ws ");
        }
    }
    if (inFile.good()){
        iss.clear();
        iss.str(line);
        while (iss.good()){
            iss >> word;
            if (word == "ws"){
                outFile << " ";
            }
            searchReplace(outFile, morseStrings, englishStrings, "-t", word, '\0');
        }
        charCount += line.length();
    }
    return charCount;
}

void processFile(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91], string mode){
    int charCount, endLine = 0;

    if (mode == "-m"){
        while (!inFile.eof()){
            charCount = englishToMorse(inFile, outFile, morseStrings, englishStrings);
            outFile << '\n';
            endLine++;
    }
    outFile << "Total characters converted successfully (including newline and white spaces): " << charCount + endLine - 1 << endl;
    }
    if (mode == "-t"){
        while (!inFile.eof()){
            charCount = morseToEnglish(inFile, outFile, morseStrings, englishStrings);
            outFile << '\n';
            endLine++;
        }
        
    }
    
}