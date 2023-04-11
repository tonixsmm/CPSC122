#include "Calculator.h"

void Calculator::setSymbolTable(string newSymbolTable[]) {
	// copy over since can't assign one array to the other
	for (int i = 'A'; i <= 'Z'; i++) {
		symbolTable[i] = newSymbolTable[i];
	}
}	

// TODO: finish this function
bool checkOperatorOnStackPrecedence(string operatorOnStack, string currentOperator) {
	return false; // TODO: fix this
}

// TODO: finish this function
string Calculator::convertInfixToPostfix(string infix) {
	return ""; // TODO: fix this
}

// TODO: finish this function
string Calculator::evaluatePostfix(string postfix) {
	return ""; // TODO: fix this
}