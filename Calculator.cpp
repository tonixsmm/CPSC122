/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 4, 2023
Programming Assignment: PA6
Description: This program implements several tasks required by PA6
*/

#include "Calculator.h"

/*
Calculator()
 * Date Created: 04/17/2023
 * Date Last Modified: 04/17/2023
 * Description: This is the default value constructor of the Calculator class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
Calculator::Calculator(){
	for (int i = 0; i < 'Z' + 1; i++){
		symbolTable[i] = "NULL";
	}
}

/*
Function: getSymbolTable()
 * Date Created: 04/15/2023
 * Date Last Modified: 04/15/2023
 * Description: This function prints out the symbolTable of the Calculator class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
void Calculator::getSymbolTable() const{
	for (int i = 'A'; i < 'Z' + 1; i++){
		cout << static_cast<char>(i) << " ";
		cout << symbolTable[i] << endl;
	}
}

/*
Function: getSymbolTable()
 * Date Created: 04/13/2023
 * Date Last Modified: 04/17/2023
 * Description: This function copys over another array's values to symbolTable array
 * Input parameters: A string array
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		if (isdigit((newSymbolTable[i])[0]) || (newSymbolTable[i])[0] == '-'){	// To retain the NULL value of the missing operands
			symbolTable[i] = newSymbolTable[i];
		}
	}
}	

/*
Function: checkOperatorOnStackPrecedence()
 * Date Created: 04/13/2023
 * Date Last Modified: 04/15/2023
 * Description: This function checks if the first operator passed into the function has a higher precedence than the second one
 * Input parameters: Two strings
 * Returns: Bool
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
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
	// Find the associated precedence value
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
	// Compare precedence value
	if (precedenceValOnStack > precedenceValCurrItem){
		return true;
	}
	else {
		return false;
	}
}

/*
Function: convertInfixToPostfix()
 * Date Created: 04/13/2023
 * Date Last Modified: 04/16/2023
 * Description: This function converts an infix expression to postfix
 * Input parameters: A string
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
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

/*
Function: evaluatePostfix()
 * Date Created: 04/13/2023
 * Date Last Modified: 04/17/2023
 * Description: This function evaluates the value of the postfix string using the symbolTable
 * Input parameters: A string
 * Returns: A string
 * Pre: None
 * Post: "ERROR" means the postfix expression cannot be evaluated
 * Note: This is a Calculator class member function
*/
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

	// Result handling
	if (result == "5916446"){ // 5916446 is an arbitrary value to denotes NULL value
		return "ERROR";
	}
	else if (checkOperandIsDigit(result) == false){ // If the expression does not have an operator, returns the operand value
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

/*
Function: processStringValue()
 * Date Created: 04/13/2023
 * Date Last Modified: 04/15/2023
 * Description: This function reads from file the value associated with each character and saves it to the symbolTable array
 * Input parameters: File stream object
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
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

				// Save to symbolTable array
				symbolTable[static_cast<int>(alphabetChar)] = numericValue;
			}
		}
	}
}

/*
Function: processINFIX()
 * Date Created: 04/15/2023
 * Date Last Modified: 04/17/2023
 * Description: This function reads in the infix expression, converts to postfix, evaluates its value, and prints everything to the console
 * Input parameters: File stream object
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
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

/*
Function: isOperator()
 * Date Created: 04/16/2023
 * Date Last Modified: 04/16/2023
 * Description: This function checks if a character is an operator
 * Input parameters: A character
 * Returns: Bool
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
bool Calculator::isOperator(char c){
	char operatorArr[8] = {'(', ')', '^', '*', '/', '%', '+', '-'};
	for (int i = 0; i < 8; i++){
		if (c == operatorArr[i]){
			return true;
		}
	}
	return false;
}

/*
Function: checkOperandIsDigit()
 * Date Created: 04/17/2023
 * Date Last Modified: 04/17/2023
 * Description: This function checks if a string represents a number
 * Input parameters: A string
 * Returns: Bool
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
bool Calculator::checkOperandIsDigit(string operand){
	int i = 0;
	while (operand[i] != '\0'){
		if (operand[i] == '-' || (operand[i] >= 48 && operand[i] <= 57)){ // ASCII value of 0-9. '-' for negative values
			return true;
		}
		i++;
	}
	return false;
}

/*
Function: getValFromSymTable()
 * Date Created: 04/17/2023
 * Date Last Modified: 04/17/2023
 * Description: This function returns the value of a symbolTable object (represented by ASCII values of characters)
 * Input parameters: A string
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Calculator class member function
*/
string Calculator::getValFromSymTable(string s) const{
	string tempString = "";
	tempString = symbolTable[static_cast<int>(s[0])];
	return tempString;
}

/*
Function: processMath()
 * Date Created: 04/16/2023
 * Date Last Modified: 04/17/2023
 * Description: This function checks the conditions of the operands and performs necessary value conversion to make sure mathematic evaluation is only performed when valid values are passed in
 * Input parameters: Three strings
 * Returns: A long int
 * Pre: None
 * Post: 5916446 denotes NULL values (ERROR)
 * Note: This is a Calculator class member function
*/
long Calculator::processMath(string operandRight, string operandLeft, string ops){
	long opRightLong = -1, opLeftLong = -1, result = 5916446; // // Arbitrary number to denote "ERROR" value
	bool proceed = false;

	// Condition checking
	if ((checkOperandIsDigit(operandRight) == false && getValFromSymTable(operandRight) != "NULL") && (checkOperandIsDigit(operandLeft) == false && getValFromSymTable(operandLeft) != "NULL")){
		opRightLong = stol(getValFromSymTable(operandRight));
		opLeftLong = stol(getValFromSymTable(operandLeft));
		proceed = true;
	}
	else if ((checkOperandIsDigit(operandRight) && operandRight != "5916446") && (checkOperandIsDigit(operandLeft) && operandLeft != "5916446")){
		opRightLong = stol(operandRight);
		opLeftLong = stol(operandLeft);
		proceed = true;
	}
	else if ((checkOperandIsDigit(operandRight) && operandRight != "5916446") && (checkOperandIsDigit(operandLeft) == false && getValFromSymTable(operandLeft) != "NULL")){
		opRightLong = stol(operandRight);
		opLeftLong = stol(getValFromSymTable(operandLeft));
		proceed = true;
	}
	else if ((checkOperandIsDigit(operandRight) == false && getValFromSymTable(operandRight) != "NULL") && (checkOperandIsDigit(operandLeft) && operandLeft != "5916446")){
		opRightLong = stol(getValFromSymTable(operandRight));
		opLeftLong = stol(operandLeft);
		proceed = true;
	}
	
	// Decide if the conditions are met. If so, allows mathematic evaluation to perform
	if (proceed == true){
		result = computeMath(proceed, opRightLong, opLeftLong, ops);
		return result;
	}
	return result;
}

/*
Function: computeMath()
 * Date Created: 04/16/2023
 * Date Last Modified: 04/16/2023
 * Description: This function computes mathematic evaluation by handling special operator cases
 * Input parameters: A bool, two long ints, and a string
 * Returns: A long int
 * Pre: None
 * Post: 5916446 denotes NULL value (ERROR)
 * Note: This is a Calculator class member function
*/
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