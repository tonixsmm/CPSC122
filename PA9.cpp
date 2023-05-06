/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 30, 2023
Programming Assignment: PA9
Description: This program implements several tasks required by PA9
I attempted the ART Review Bonus
*/

#include "PA9.h"

/*
Function: countDigits()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function counts how many digits in a given string
 * Input parameters: A string
 * Returns: An int
 * Pre: None
 * Post: None
*/
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
	return count;
}

/*
Function: runTask1()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This is a driver function for Task 1
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
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

/*
Function: countDigits()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function sums up the digits of an integer value
 * Input parameters: An int
 * Returns: An int
 * Pre: None
 * Post: None
*/
int sumDigits(int num) {
	int sum = 0;
	string s = to_string(num);

	// Base case
	if (s.length() == 1){
		return stoi(s);
	}

	// Check condition & Sum digits 
	if (s.at(0) != '-'){ // In case of negative values
		sum += stoi(s.substr(0, 1));
	}

	// Recursive step
	sum += sumDigits(stoi(s.substr(1, s.length() - 1)));

	return sum;
}

/*
Function: runTask2()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This is a driver function for Task 2
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
void runTask2() {
	string userInput = "";
	int input = -1;
	int result = -1;

	cout << endl << "TASK 2: Sum Digits" << endl;
	cout << "------------------" << endl;

	cout << "Please enter a number to count its digit (if any): ";
	getline(cin, userInput);

	input = stoi(userInput);

	result = sumDigits(input);

	cout << "The sum of the digits in the given number is " << result << endl;
}

/*
Function: stringCleaning()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function removes all white space in a given string and converts them to lower case
 * Input parameters: A string
 * Returns: A string
 * Pre: None
 * Post: None
*/
string stringCleaning(string s){
	string tempString = "";
	for (int i = 0; i < s.length(); i++){
		if(!isspace(s.at(i))){
			tempString += tolower(s.at(i));
		}
	}
	return tempString;
}

/*
Function: isPalindrome()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function checks if a given string is a palindrome
 * Input parameters: A bool
 * Returns: A string
 * Pre: None
 * Post: None
*/
bool isPalindrome(string s) {
	bool conditionMet = false;;
	string tempString = "";

	// Clean the string to remove all white space and convert all characters to lower case
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

	return conditionMet;
}
	
/*
Function: runTask3()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This is a driver function for Task 3
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
void runTask3() {
	string userInput = "";
	bool result = false;

	cout << endl << "TASK 3: Palindrome" << endl;
	cout << "------------------" << endl;

	cout << "Please enter a string to check for Palindrome: ";
	getline(cin, userInput);

	result = isPalindrome(userInput);

	if (result == true){
		cout << userInput << " is a Palindrome!" << endl;
	}
	else {
		cout << userInput << " is not a Palindrome!" << endl;
	}
}

/*
Function: runTask4()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This is a driver function for Task 4
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
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

/*
Function: removeFront()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function removes the first character in a given string and pushes the remaining characters to a vector
  				With each new sub-string it generates, the function calls removeBack() to removes the last character in the string
  				and pushes the remaining to a vector
 * Input parameters: A string, a pass-by-reference string vector
 * Returns: None
 * Pre: None
 * Post: None
*/
void removeFront(string s, vector<string>& substrings){
	// Base case
	if (s.length() == 1){
		substrings.push_back(s);
		substrings.push_back("");
		return;
	}

	// Push to vector & call removeBack()
	substrings.push_back(s);
	removeBack(s, substrings);

	// Recursive step
	removeFront(s.substr(1, s.length() - 1), substrings);
}

/*
Function: removeBack()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function removes the last character in a given string and pushes the remaining characters to a vector
 * Input parameters: A string, a pass-by-reference string vector
 * Returns: None
 * Pre: None
 * Post: None
*/
void removeBack(string s, vector<string>& substrings){
	// Base case
	if (s.length() == 1){
		return;
	}

	// Push to vector
	substrings.push_back(s.substr(0, s.length() - 1));

	// Recursive step
	removeBack(s.substr(0, s.length() - 1), substrings);
}

/*
Function: generateSubstrings()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This function calls removeFront() to begin generate sub-strings
 * Input parameters: A string, a pass-by-reference string vector
 * Returns: None
 * Pre: None
 * Post: None
*/
void generateSubstrings(string s, vector<string>& substrings) {
	if (s != ""){
		removeFront(s, substrings);
	}
	else{
		substrings.push_back("");
	}
}

/*
Function: runTask5()
 * Date Created: 04/30/2023
 * Date Last Modified: 04/30/2023
 * Description: This is a driver function for Task 5
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
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
