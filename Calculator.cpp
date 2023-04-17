#include "Calculator.h"

Calculator::Calculator(){
	for (int i = 0; i < 'Z' + 1; i++){
		symbolTable[i] = "NULL";
	}
}

void Calculator::getSymbolTable() const{
	for (int i = 'A'; i < 'Z' + 1; i++){
		cout << static_cast<char>(i) << " ";
		cout << symbolTable[i] << endl;
	}
}

void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		if (isdigit((newSymbolTable[i])[0]) || (newSymbolTable[i])[0] == '-'){	// To retain the NULL value of the missing operands
			symbolTable[i] = newSymbolTable[i];
		}
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
	istringstream iss;
	string word = "", tempString = "", operandLeft = "", operandRight = "", ops = "", result = "";

	iss.clear();
	iss.str(postfix);

	while (iss.good()){
		iss >> word;
		for (char c : word){
			if (isOperator(c) == false) {
				tempString = c;
				stack.push(tempString);
			}
			else {
				ops = c;
				operandRight = stack.pop();
				operandLeft = stack.pop();

				result = to_string(processMath(operandRight, operandLeft, ops));
				stack.push(result);
			}
		}
	}
	result = stack.pop();
	if (result == "5916446"){
		return "ERROR";
	}
	else if (checkOperandIsDigit(result) == false){
		result = symbolTable[static_cast<int>(result[0])];
		return result;
	}

	return result;
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
	string line = "", postfix = "";

	while (!inFile.eof() && line != "#"){
		getline(inFile, line);

		if (inFile.good() && line != "#"){
			postfix = convertInfixToPostfix(line);
			cout << endl << "INFIX:\t\t" << line << endl;
			cout << "POSTFIX:\t" << postfix << endl;
			cout << "Result :\t" << evaluatePostfix(postfix) << endl;
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

bool Calculator::checkOperandIsDigit(string operand){
	int i = 0;
	while (operand[i] != '\0'){
		if (operand[i] == '-' || (operand[i] >= 48 && operand[i] <= 57)){ // ASCII value of 0-9
			return true;
		}
		i++;
	}
	return false;
}

long Calculator::processMath(string operandRight, string operandLeft, string ops){
	long opRightLong = -1, opLeftLong = -1, result = 5916446; // // Arbitrary number to denote "ERROR" value
	bool proceed = false;

	if ((checkOperandIsDigit(operandRight) == false && symbolTable[static_cast<int>(operandRight[0])] != "NULL") && (checkOperandIsDigit(operandLeft) == false && symbolTable[static_cast<int>(operandLeft[0])] != "NULL")){
		opRightLong = stol(symbolTable[static_cast<int>(operandRight[0])]);
		opLeftLong = stol(symbolTable[static_cast<int>(operandLeft[0])]);
		proceed = true;
	}
	else if ((checkOperandIsDigit(operandRight) && operandRight != "5916446") && (checkOperandIsDigit(operandLeft) && operandLeft != "5916446")){
		opRightLong = stol(operandRight);
		opLeftLong = stol(operandLeft);
		proceed = true;
	}
	else if ((checkOperandIsDigit(operandRight) && operandRight != "5916446") && (checkOperandIsDigit(operandLeft) == false && symbolTable[static_cast<int>(operandLeft[0])] != "NULL")){
		opRightLong = stol(operandRight);
		opLeftLong = stol(symbolTable[static_cast<int>(operandLeft[0])]);
		proceed = true;
	}
	else if ((checkOperandIsDigit(operandRight) == false && symbolTable[static_cast<int>(operandRight[0])] != "NULL") && (checkOperandIsDigit(operandLeft) && operandLeft != "5916446")){
		opRightLong = stol(symbolTable[static_cast<int>(operandRight[0])]);
		opLeftLong = stol(operandLeft);
		proceed = true;
	}
	
	if (proceed == true){
		result = computeMath(proceed, opRightLong, opLeftLong, ops);
		return result;
	}
	return result;
}

long Calculator::computeMath(bool proceed, long opRightLong, long opLeftLong, string ops){
	if (ops == "+"){
		return opLeftLong + opRightLong;
	}
	else if (ops == "-"){
		return opLeftLong - opRightLong;
	}
	else if (ops == "*"){
		return opLeftLong * opRightLong;
	}
	else if (ops == "/"){
		if (opRightLong == 0) {
			return 5916446; // Arbitrary number to denote "ERROR" value
		}
		else {
			return opLeftLong / opRightLong;
		}
	}
	else if (ops == "^"){
		if (opRightLong < 0) {
			return 5916446; // Arbitrary number to denote "ERROR" value
		}
		else {
			return pow(opLeftLong, opRightLong);
		}
	}
	else if (ops == "%"){
		if (opRightLong <= 0) {
			return 5916446; // Arbitrary number to denote "ERROR" value
		}
		else {
			return opLeftLong % opRightLong;
		}
	}
	return 5916446; // Arbitrary number to denote "ERROR" value
}