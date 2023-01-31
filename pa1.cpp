/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: January 30, 2022
Programming Assignment: PA1
Description: This program will convert a file from English to Morse code and vice versa
Notes: The English text file and Morse strings file must have line feeds (e.g. press enter) at the end of each line
*/

#include "pa1.h"

/*
Function: chooseMode()
 * Date Created: 01/29/2022
 * Date Last Modified: 1/29/2022
 * Description: This function prompts the user to choose a mode between English to Morse and Morse to English
 * Input parameters: Mode and file names
 * Returns: None
 * Pre: User follows the command line instructions
 * Post: None
*/
void chooseMode(string& mode, string& fileNameRead, string& fileNameWrite){
    cout << "Please enter the mode you'd like to use using the following command:" << endl;;
    cout << "English to Morse mode: -m [ENGLISH FILENAME] [MORSE FILENAME]" << endl;
    cout << "Morse to English mode: -t [MORSE FILENAME] [ENGLISH FILENAME]" << endl;

    cin >> mode >> fileNameRead >> fileNameWrite;
}

/*
Function: openFile()
 * Date Created: 01/29/2022
 * Date Last Modified: 1/29/2022
 * Description: This function open files for reading and writing. It also checks if the files are open successfully
 * Input parameters: File names and file streams
 * Returns: None
 * Pre: None
 * Post: None
*/
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

/*
Function: morseEnglishArrays()
 * Date Created: 01/29/2022
 * Date Last Modified: 1/30/2022
 * Description: This function creates two arrays for morse and english characters
 * Input parameters: Two arrays
 * Returns: None
 * Pre: Arrays are properly declared
 * Post: None
*/
void morseEnglishArrays(string morseStrings[91], char englishStrings[91]){
    // English characters using ASCII
    char orgChar = ' ';
    for (int i = 32; i < 91; i++){
        englishStrings[i] = orgChar;
        orgChar++;
    }
    
    // Numbers to morse
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

    // Letters to morse
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

    // Punctuation to morse
    morseStrings[33] = "..--.";
    morseStrings[34] = ".-..-.";
    morseStrings[39] = ".----.";
    morseStrings[40] = "-.--.";
    morseStrings[41] = "-.--.-";
    morseStrings[43] = ".-.-.";
    morseStrings[44] = "--..--";
    morseStrings[45] = "-....-";
    morseStrings[46] = ".-.-.-";
    morseStrings[47] = "-..-.";
    morseStrings[58] = "---...";
    morseStrings[59] = "-.-.-.";
    morseStrings[61] = "-...-";
    morseStrings[63] = "..--..";
}

/*
Function: searchReplace()
 * Date Created: 01/29/2022
 * Date Last Modified: 1/30/2022
 * Description: This function searches for the character or Morse string in the array, replaces it with the Morse code or English character, and writes it to a new file
 * Input parameters: File stream, English and Morse character arrays, mode indicator, and characters and Morse strings to be replaced
 * Returns: None
 * Pre: Write file is opened. Arrays are properly declared and contain characters. English characters are in uppercase.
 * Post: English characters are in uppercase after being replaced and written to a new file.
*/
void searchReplace(ofstream& outFile, string morseStrings[91], char englishStrings[91], string mode, string word, char character){
    // English to Morse
    if (mode == "-m"){
        for (int i = 0; i < 91; i++){
            if (character == englishStrings[i]){
                outFile << morseStrings[i] << " ";
            }
        }
    }
    // Morse to English
    if (mode == "-t"){
        for (int i = 32; i < 91; i++){
            if (word == morseStrings[i] && word != ""){
                outFile << englishStrings[i];
            }
        }
    }
}

/*
Function: englishToMorse()
 * Date Created: 01/29/2022
 * Date Last Modified: 1/30/2022
 * Description: This function reads the file for English characters, searches and replaces with Morse strings, and counts the number of characters successfully converted
 * Input parameters: File stream and English and Morse character arrays
 * Returns: Number of characters successfully converted
 * Pre: Files are opened. Arrays are properly declared and contain characters
 * Post: Character count in integer that includes white spaces, new lines, and line feeds
*/
int englishToMorse(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91]){
    // Declare variables
    string line, word;
    istringstream iss;
    static int charCount = 0;

    // Read line-by-line
    getline(inFile, line);
    if (inFile.good()){
        iss.clear();
        iss.str(line);
        // Read word-by-word
        while (iss.good()){
            iss >> word;
            // Read character-by-character
            for (char c : word){
                searchReplace(outFile, morseStrings, englishStrings, "-m", word, toupper(c));
            }
            outFile << " ";
        }
        charCount += line.length();
    }
    return charCount;
}

/*
Function: morseToEnglish()
 * Date Created: 01/29/2022
 * Date Last Modified: 1/30/2022
 * Description: This function reads the file for Morse strings, searches and replaces with English characters, and counts the number of strings successfully converted
 * Input parameters: File stream and English and Morse character arrays
 * Returns: Number of characters successfully converted
 * Pre: Files are opened. Arrays are properly declared and contain characters
 * Post: Character count in integer that includes white spaces, new lines, and line feeds
 * Citation: https://stackoverflow.com/questions/2341759/how-to-find-the-location-of-two-consecutive-spaces-in-a-string
*/
int morseToEnglish(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91]){
    // Declare variables
    string line, word;
    istringstream iss;
    static int charCount = 0;

    // Read line-by-line
    getline(inFile, line);

    // Find and preserve white spaces
    for (int i = 0; i <= line.length(); i++){ 
        if (line.find("  ") != string::npos){
            line.replace(line.find("  "), 2, " ws ");
        }
    }

    // Read word-by-word
    if (inFile.good()){
        iss.clear();
        iss.str(line);
        // Read character-by-character
        while (iss.good()){
            iss >> word;
            if (word == "ws"){
                outFile << " ";
            }
            searchReplace(outFile, morseStrings, englishStrings, "-t", word, '\0');
            charCount++;
        }
    }
    return charCount;
}

/*
Function: englishToMorse()
 * Date Created: 01/29/2022
 * Date Last Modified: 1/30/2022
 * Description: This function performs as a driver to call the appropriate function based on the mode indicator
 * Input parameters: File streams, English and Morse character arrays, mode indicator
 * Returns: None
 * Pre: Files are opened. Arrays are properly declared and contain characters
 * Post: Character count includes white spaces, new lines, and line feeds
*/
void processFile(ifstream& inFile, ofstream& outFile, string morseStrings[91], char englishStrings[91], string mode){
    // Declare variables
    int charCount, endLine = 0;

    // English to Morse
    if (mode == "-m"){
        while (!inFile.eof()){
            charCount = englishToMorse(inFile, outFile, morseStrings, englishStrings);
            outFile << '\n';
            endLine++;
        }
    outFile << "Total characters converted successfully (including newline and white spaces): " << charCount + endLine - 1 << endl;
    }

    // Morse to English
    if (mode == "-t"){
        while (!inFile.eof()){
            charCount = morseToEnglish(inFile, outFile, morseStrings, englishStrings);
            outFile << '\n';
            endLine++;
        }
    outFile << "Total characters converted successfully (including newline and white spaces): " << charCount - endLine + 1 << endl;   
    }
}

/*
Function: closeFile()
 * Date Created: 01/30/2022
 * Date Last Modified: 1/30/2022
 * Description: This function closes the input and output files
 * Input parameters: File streams
 * Returns: None
 * Pre: Files are opened
 * Post: None
*/
void closeFile(ifstream& inFile, ofstream& outFile){
    inFile.close();
    outFile.close();
}