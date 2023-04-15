#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include "Stack.h"

using namespace std;

bool checkOperatorOnStackPrecedence(string, string);
void openFile(ifstream&, string);

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string);

		void getSymbolTable() const;

		void readFromFile();
		void processSymbolTable();
		void processStringValue(ifstream&);
};

#endif