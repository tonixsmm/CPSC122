#include "PA9.h"

// TODO: finish this function
int countDigits(string s) {
	int count = 0;
	// Base case
	if (s.length() == 0){
		return 0;
	}

	// Count digits
	if (isdigit(s.at(0))){
		count++;
	}

	// Recursive step
	count += countDigits(s.substr(1, s.length() - 1));
	return count; // TODO: fix this
}

// TODO: finish this function by testing countDigits()
void runTask1() {
	string input = "";
	int result = -1;

	cout << "TASK 1: Counting Digits" << endl;
	cout << "-----------------------" << endl;

	cout << "Please enter a string to count its digit (if any): ";
	getline(cin, input);

	result = countDigits(input);

	if (result == -1){
		cout << "There are no digits in the given string!" << endl;
	}
	else {
		cout << "There is/are " << result << " digit(s) in the given string!" << endl;
	}
}

// TODO: finish this function
int sumDigits(int num) {
	int sum = 0;
	string s = to_string(num);

	// Base case
	if (s.length() == 1){
		return stoi(s);
	}

	// Check condition & Sum digits 
	if (s.at(0) != '-'){
		sum += stoi(s.substr(0, 1));
	}

	// Recursive step
	sum += sumDigits(stoi(s.substr(1, s.length() - 1)));

	return sum; // TODO: fix this
}

// TODO: finish this function by testing sumDigits()
void runTask2() {
	int input = -1;
	int result = -1;

	cout << endl << "TASK 2: Sum Digits" << endl;
	cout << "------------------" << endl;

	cout << "Please enter a number to count its digit (if any): ";
	cin >> input;

	result = sumDigits(input);

	cout << "The sum of the digits in the given number is " << result << endl;
}

string stringCleaning(string s){
	string tempString = "";
	for (int i = 0; i < s.length(); i++){
		if(!isspace(s.at(i))){
			tempString += tolower(s.at(i));
		}
	}
	return tempString;
}

// TODO: finish this function
bool isPalindrome(string s) {
	bool conditionMet = false;;
	string tempString = "";
	tempString = stringCleaning(s);

	// Base case
	if (tempString.length() == 0){
		conditionMet = true;
		return true;
	}
	
	// Recursive step
	if (tempString.substr(0, 1) == tempString.substr(tempString.length() - 1, -1)){
		conditionMet = isPalindrome(tempString.substr(1, tempString.length() - 2));
	}
	else {
		conditionMet = false;
		return false;
	}

	return conditionMet; // TODO: fix this
}
	
// TODO: finish this function by testing isPalindrome()
void runTask3() {
	string input = "";
	bool result = false;

	cout << endl << "TASK 3: Palindrome" << endl;
	cout << "------------------" << endl;

	cout << "Please enter a string to check for Palindrome: ";
	getline(cin, input);

	result = isPalindrome(input);

	if (result == true){
		cout << input << " is a Palindrome!" << endl;
	}
	else {
		cout << input << " is not a Palindrome!" << endl;
	}
}

// TODO: finish this function by testing getMaxValue() and getMaxValueHelper()
void runTask4() {
	int input = -1, result = -1;
	LinkedList list;
	
	cout << endl << "TASK 4: LinkedList Max Value" << endl;
	cout << "----------------------------" << endl;

	do{
		cout << "Please enter a number to add to the linked list (-1 to finish adding): ";
		cin >> input;

		if (input != -1){
			list.appendNode(input);
		}	
	} while (input != -1);
	
	result = list.getMaxValue();

	if (result == -1){
		cout << "The list is empty!" << endl;
	}
	else {
		cout << result << " is the max value of the list!" << endl;
	}
}

void removeFront(string s, vector<string>& substrings){
	// Base case
	if (s.length() == 1){
		substrings.push_back(s);
		substrings.push_back("");
		return;
	}

	substrings.push_back(s);
	removeBack(s, substrings);
	// Recursive step
	removeFront(s.substr(1, s.length() - 1), substrings);
}

void removeBack(string s, vector<string>& substrings){
	// Base case
	if (s.length() == 1){
		return;
	}

	substrings.push_back(s.substr(0, s.length() - 1));
	// Recursive step
	removeBack(s.substr(0, s.length() - 1), substrings);
}

// TODO: finish this function
void generateSubstrings(string s, vector<string>& substrings) {
	if (s != ""){
		removeFront(s, substrings);
	}
	else{
		substrings.push_back("");
	}
}

// TODO: finish this function by testing generateSubstrings()
void runTask5() {
	string input = "";
	vector<string> substrings;
	
	cout << endl << "TASK 5: Substrings Generator" << endl;
	cout << "----------------------------" << endl;
	cout << "Please enter a string to produce its substrings: ";
	cin >> input;

	generateSubstrings(input, substrings);

	cout << "Substrings: ";
	for (int i = 0; i < substrings.size() - 1; i++){
		cout << "'" << substrings[i] << "', ";
	}
	cout << "'" << substrings[-1] << "'" << endl;
}

// BONUS ONLY: utility function for BONUS task
// no need for any changes here
void displayMaze(char maze[8][8]) {
	int i, j;
	cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
	for(i = 0; i < 8; i++) {
		cout << i;
		for(j = 0; j < 8; j++) {
			cout << " " << maze[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// TODO: BONUS ONLY finish this function
bool traverseMaze(char maze[8][8], Coordinates solution[], int * steps, int currRow, int currCol) {
	return false; // TODO: fix this
}

// TODO: BONUS ONLY finish this function by testing traverseMaze()
void runBONUSTask() {
	
}
