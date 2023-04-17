#include "PA7.h"

int main() {
	// TODO: your code here
	Calculator cal;

	// cal.readFromFile();
	// cal.getSymbolTable();

	string tempArr['Z' + 1];
	for (int i = 0; i < 'Z' + 1; i++){
		tempArr[i] = "NULL";
	}
	// for (int i = 48; i <= 57; i++){ // ASCII 0-9
	// 	tempArr[i] = "NUM";
	// }
	tempArr['A'] = "1";
	tempArr['B'] = "2";
	tempArr['C'] = "3";
	
	cal.setSymbolTable(tempArr);
	cal.getSymbolTable();

	string result = cal.convertInfixToPostfix("A-(B+C)");
	cout << result << endl;
	cout << cal.evaluatePostfix(result) << endl;

	string s = "-3";
	long num = stol(s);
	cout << num << endl;

	return 0;
}
