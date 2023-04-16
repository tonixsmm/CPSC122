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
	string tempString = "";
	int precedenceValOnStack = -2, precedenceValCurrItem = -2;
	int precedenceTable[3][8];

	// Precedence character initialization
	char tempCharArr[8] = {'(', ')', '^', '*', '/', '%', '+', '-'};
	for (int i = 0; i < 8; i++){
		precedenceTable[0][i] = tempCharArr[i];
	}

	// Precendence "on stack" initialization
	int tempStackArr[8] = {0, -1, 5, 4, 4, 4, 2, 2};
	for (int i = 0; i < 8; i++){
		precedenceTable[1][i] = tempStackArr[i];
	}

	// Precedence "current item" initialization
	int tempCurrArr[8] = {7, 0, 6, 3, 3, 3, 1, 1};
	for (int i = 0; i < 8; i++){
		precedenceTable[2][i] = tempCurrArr[i];
	}

	// Comparison algorithm
	for (int i = 0; i < 8; i++){ // "on stack"
		tempString = static_cast<char>(precedenceTable[0][i]);
		if (operatorOnStack == tempString){
			precedenceValOnStack = precedenceTable[1][i];
		}
	}

	for (int i = 0; i < 8; i++){ // "current item"
		tempString = static_cast<char>(precedenceTable[0][i]);
		if (currentOperator == tempString){
			precedenceValCurrItem = precedenceTable[2][i];
		}
	}

	if (precedenceValOnStack > precedenceValCurrItem){
		return true;
	}
	else {
		return false;
	}
}

// TODO: finish this function
string Calculator::convertInfixToPostfix(string infix) {
	istringstream iss;
	string postfixString = "", tempString = "", word = "";

	iss.clear();
	iss.str(infix);

	while (iss.good()){
		iss >> word;
		for (char c : word){
			if (isOperator(c) == false){
				tempString = c;
				postfixString += tempString;
			}
			else if (c == '('){
				tempString = c;
				stack.push(tempString);
			}
			else if (c == ')'){
				while (stack.peek() != "("){
					postfixString += stack.pop();
				}
				if (stack.peek() == "("){
					stack.pop();
				}
			}
			else {
				tempString = c;
				while (!stack.isEmpty() && checkOperatorOnStackPrecedence(stack.peek(), tempString) == true){
					postfixString += stack.pop();
				}
				stack.push(tempString);
			}
		}
	}
	while (!stack.isEmpty()){
		postfixString += stack.pop();
	}

	return postfixString;
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

	inFile.close();
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
			convertInfixToPostfix(line);
		}
	}
}

bool Calculator::isOperator(char c){
	char operatorArr[8] = {'(', ')', '^', '*', '/', '%', '+', '-'};
	for (int i = 0; i < 8; i++){
		if (c == operatorArr[i]){
			return true;
		}
	}
	return false;
}