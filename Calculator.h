/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 17, 2023
Programming Assignment: PA7
Description: This program implements several tasks required by PA7
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "Stack.h"

using namespace std;

bool checkOperatorOnStackPrecedence(string, string);
bool isOperator(string);
void openFile(ifstream&, string);

class Calculator {
	private:
		string symbolTable['Z' + 1];
		// example of composition
		// Calculator "has-a" Stack
		Stack stack; // for converting infix to postfix and for evaluating postfix
	public:
		Calculator();	// DVC
		void setSymbolTable(string[]);
		string convertInfixToPostfix(string);
		string evaluatePostfix(string);

		void getSymbolTable() const;
		void processSymbolTable();
		void processStringValue(ifstream&);
		void processINFIX(ifstream&);
		bool isOperator(char);
		long processMath(string, string, string);
		long computeMath(bool, long, long, string);
		bool checkOperandIsDigit(string);
		string getValFromSymTable(string) const;
};

#endif