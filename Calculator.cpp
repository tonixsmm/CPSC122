#include "Calculator.h"

void Calculator::getSymbolTable() const{
	for (int i = 'A'; i < 'Z' + 1; i++){
		cout << static_cast<char>(i) << " ";
		cout << symbolTable[i] << endl;
	}
}

void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

// TODO: finish this function
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
	int precedenceTable [3][8];

	precedenceTable

	return false; // TODO: fix this
}

// TODO: finish this function
string Calculator::convertInfixToPostfix(string infix) {
	istringstream iss;

	iss.clear();
	iss.str(infix);

	// TODO: Finish algorithm

	return ""; // TODO: fix this
}

// TODO: finish this function
string Calculator::evaluatePostfix(string postfix) {
	return ""; // TODO: fix this
}

void Calculator::readFromFile(){
    ifstream inFile;

	openFile(inFile, "../input.txt");

	processStringValue(inFile);
	processINFIX(inFile);
}


/*
Function: openFile()
 * Date Created: 02/04/2022
 * Date Last Modified: 02/26/2022
 * Description: This function opens a file and checks if it is opened successfully
 * Input parameters: File stream and file name
 * Returns: None
 * Pre: None
 * Post: None
*/
void openFile(ifstream& inFile, string fileName){
	inFile.open(fileName);

	if (inFile.is_open()){
        cout << "Successfully opened " << fileName << endl;
    }
    else{
        cout << "Failed to open " << fileName << endl;
        exit(-1);
	}
}

void Calculator::processStringValue(ifstream& inFile){
	istringstream iss;
	string line = "", numericValue = "";
	char alphabetChar = ' ';

	while (!inFile.eof() && line != "#"){
		getline(inFile, line);

		if (inFile.good() && line != "#"){
			iss.clear();
			iss.str(line);

			while (iss.good()) {
				iss >> alphabetChar;
				iss >> numericValue;

				symbolTable[static_cast<int>(alphabetChar)] = numericValue;
			}
		}
	}
}

void Calculator::processINFIX(ifstream& inFile){
	istringstream iss;
	string line = "";

	while (!inFile.eof() && line != "#"){
		getline(inFile, line);

		if (inFile.good() && line != "#"){
			cout << line << endl;

			iss.clear();
			iss.str(line);

		}
	}
}