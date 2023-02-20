/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: February 21, 2022
Programming Assignment: PA3
Description: This program implements several tasks required by PA3
Note: I attempted the bonus
*/

#include "PA3.h"

////////////////////////////////////
// TASK 1
////////////////////////////////////

/*
Function: answerIntegerQuestions()
 * Date Created: 02/16/2022
 * Date Last Modified: 02/18/2022
 * Description: This function call functions to answer task 1 questions
 * Input parameters: An integer, and three pointers to functions
 * Returns: None
 * Pre: None
 * Post: None
*/
void answerIntegerQuestions(int num, bool * isMultiple, bool * isSumEven, bool * isPrime) {
	// call a function to answer the first question
	*isMultiple = checkMultiplication(num);
	// call a function to answer the second question
	*isSumEven = checkSumEven(num);
	// call a function to answer the third question
	*isPrime = checkPrime(num);
}

/*
Function: checkMultiplication()
 * Date Created: 02/16/2022
 * Date Last Modified: 02/16/2022
 * Description: This function check if an integer is a multiple of 7, 11, or 13
 * Input parameters: An integer number
 * Returns: Bool
 * Pre: None
 * Post: None
*/
bool checkMultiplication(int num){
	if (num % 7 == 0 || num % 11 == 0 || num % 13 == 0){
		return true;
	}
	else{
		return false;
	}
}

/*
Function: checkSumEven()
 * Date Created: 02/18/2022
 * Date Last Modified: 02/18/2022
 * Description: This function check a number if the sum of its digits is even
 * Input parameters: An integer number
 * Returns: Bool
 * Pre: None
 * Post: None
*/
bool checkSumEven(int num){
	int sum = 0;

	// Counting the sum of digits
	string numConverted = to_string(num);
	for (char i : numConverted){
		sum += int(i);
	}

	// Checking if the sum is even
	if (sum % 2 == 0){
		return true;
	}
	else{
		return false;
	}
}

/*
Function: checkPrime()
 * Date Created: 02/18/2022
 * Date Last Modified: 02/18/2022
 * Description: This function checks if a number is a prime number
 * Input parameters: An integer number
 * Returns: Bool
 * Pre: None
 * Post: None
*/
bool checkPrime(int num){
	if (num > 1){
		for (int i = 2; i < sqrt(num); i++){
			if (num % i == 0){
				return false;
			}
		}
		return true;
	}
	return false;
}

/*
Function: openFile()
 * Date Created: 02/04/2022
 * Date Last Modified: 02/16/2022
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
Function: runTask1()
 * Date Created: 02/18/2022
 * Date Last Modified: 02/18/2022
 * Description: This function acts as the driver for task 1
 * Input parameters: void
 * Returns: None
 * Pre: None
 * Post: None
*/
void runTask1(){
	// Declaration of variables
	ifstream inFile;
	bool isMultiple, isSumEven, isPrime;
	string line;
	int num;

	// Opening the file
	openFile(inFile, "../numbers.txt");

	// Reading the file
	while (!inFile.eof()){
		getline(inFile, line);

		if (inFile.good()){
			// Converting the string to an integer
			num = stoi(line);
			answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);

			cout << "Number " << num;

			// Printing the results
			if (isMultiple == true){
				cout << " is a multiple of 7, 11, or 13, ";
			}
			else{
				cout << " is not a multiple of 7, 11, or 13, ";
			}

			if (isSumEven == true){
				cout << "the sum of its digits is even, ";
			}
			else{
				cout << "the sum of its digits is odd, ";
			}

			if (isPrime == true){
				cout << "and it is a prime number." << endl;
			}
			else{
				cout << "and it is not a prime number." << endl;
			}
		}
	}
}

////////////////////////////////////
// TASK 2
////////////////////////////////////

/*
Function: findWinningLotteryTicket()
 * Date Created: 02/16/2022
 * Date Last Modified: 02/18/2022
 * Description: This function checks if a person win the lottery ticket
 * Input parameters: Two integers and an array of integers
 * Returns: Bool
 * Pre: None
 * Post: None
*/
bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers, const int numPlayerNumbers) {
	for (int i = 0; i < numPlayerNumbers; i++){
		if (*(playerNumbers + i) == winningTicketNum){
			return true;
		}
	}
	return false;
}

/*
Function: runTask2()
 * Date Created: 02/16/2022
 * Date Last Modified: 02/18/2022
 * Description: This function acts as a driver for task 2
 * Input parameters: Void
 * Returns: Bool
 * Pre: None
 * Post: None
*/
void runTask2(){
	// Declare variables
	int playerNums[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
	int playerNumsSize = 10, winningNum = 0;
	bool winner = false;

	// Prompt user for input
	cout << "Enter the winning lottery ticket number: ";
	cin >> winningNum;

	winner = findWinningLotteryTicket(winningNum, playerNums, playerNumsSize);

	if (winner == true){
		cout << "You won!" << endl;
	}
	else {
		cout << "You lost!" << endl;
	}
}

////////////////////////////////////
// TASK 3
////////////////////////////////////

/*
Function: createWordsArray()
 * Date Created: 02/19/2022
 * Date Last Modified: 02/19/2022
 * Description: This function reads from file, loads the words into an array, and sorts them using bubble sort
 * Input parameters: File stream and size of the array
 * Returns: Pointer to string array
 * Pre: None
 * Post: None
*/
string * createWordsArray(ifstream& inFile, const int size) {
	// Declare variables and dynamically allocated array
	string * stringArr = new string[size];
	string line, word;
	istringstream iss;

	// Read file
	for (int i = 0; i < 2; i++){
		int count = 0;

		// Read line-by-line
		getline(inFile, line);
		if (inFile.good()){
			iss.clear();
			iss.str(line);

			// Read word-by-word
			while (iss.good()){
				iss >> word;
				*(stringArr + count) = word;
				count++;
			}
		}
	}
	// Sort the array using bubble sort
	bubbleSort(stringArr, size);

	return stringArr;
}

/*
Function: generateSentence()
 * Date Created: 02/19/2022
 * Date Last Modified: 02/19/2022
 * Description: This function randomly generates a sentence using the words in parts of speech arrays
 * Input parameters: A pointer to a string, four arrays, and four sizes
 * Returns: Bool
 * Pre: None
 * Post: None
*/
void generateSentence(string * sentence,
		const string * articlesArr, const int articlesSize,
		const string * nounsArr, const int nounsSize,
		const string * verbsArr, const int verbsSize, 
		const string * prepsArr, const int prepsSize) {
	
	string tempElem;

	// Article
	tempElem = *(articlesArr + (rand() % articlesSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	// Noun	
	tempElem = *(nounsArr + (rand() % nounsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	// Verb
	tempElem = *(verbsArr + (rand() % verbsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	// Preposition
	tempElem = *(prepsArr + (rand() % prepsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	// Article
	tempElem = *(articlesArr + (rand() % articlesSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	// Noun
	tempElem = *(nounsArr + (rand() % nounsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}

	// Formatting sentence
	sentence->push_back('!');
	sentence->at(0) = toupper(sentence->at(0));
}

/*
Function: runTask3()
 * Date Created: 02/19/2022
 * Date Last Modified: 02/19/2022
 * Description: This function acts as a driver to run task 3
 * Input parameters: Void
 * Returns: Void
 * Pre: None
 * Post: None
*/
void runTask3(){
	// Declare variables
	ifstream inFile;
	string sentence;
	string * articlesArr = NULL;
	string * nounsArr = NULL;
	string * verbsArr = NULL;
	string * prepsArr = NULL;
	string checkPartOfSpeech;
	int articlesSize = 0, nounsSize = 0, verbsSize = 0, prepsSize = 0, sentenceSize = 0;

	// Open file and read the number of sentence that needs to be generated
	// openFile(inFile, "../input_words.txt");
	openFile(inFile, "../test_file.txt");
	inFile >> sentenceSize;

	// Read file, check which type of parts of speech it is, and create words arrays
	for (int i = 0; i < 4; i++){
		inFile >> checkPartOfSpeech;
		if (checkPartOfSpeech == "Articles"){
			inFile >> articlesSize;
			articlesArr = createWordsArray(inFile, articlesSize);
		}
		else if (checkPartOfSpeech == "Nouns"){
			inFile >> nounsSize;
			nounsArr = createWordsArray(inFile, nounsSize);
		}
		else if (checkPartOfSpeech == "Verbs"){
			inFile >> verbsSize;
			verbsArr = createWordsArray(inFile, verbsSize);
		}
		else if (checkPartOfSpeech == "Prepositions"){
			inFile >> prepsSize;
			prepsArr = createWordsArray(inFile, prepsSize);
		}
	}

	// Print the word bank
	cout << "WORD BANK" << endl;
	cout << "=========" << endl;
	cout << "Articles: ";
	printArray(articlesArr, articlesSize);
	cout << "Nouns: ";
	printArray(nounsArr, nounsSize);
	cout << "Verbs: ";
	printArray(verbsArr, verbsSize);
	cout << "Prepositions: ";
	printArray(prepsArr, prepsSize);
	
	// Generate sentences
	cout << endl;
	cout << "GENERATED SENTENCES" << endl;
	cout << "===================" << endl;
	for (int i = 0; i < sentenceSize; i++){
		sentence.clear();
		generateSentence(&sentence, articlesArr, articlesSize, nounsArr, nounsSize, verbsArr, verbsSize, prepsArr, prepsSize);
		cout << i + 1 << ". " << sentence << endl;
	}

	// Close file and free memories
	inFile.close();
	delete [] articlesArr;
	delete [] nounsArr;
	delete [] verbsArr;
	delete [] prepsArr;

	// Set pointers to NULL
	articlesArr = NULL;
	nounsArr = NULL;
	verbsArr = NULL;
	prepsArr = NULL;
}

/*
Function: printArray()
 * Date Created: 02/19/2022
 * Date Last Modified: 02/19/2022
 * Description: This function prints out array elements
 * Input parameters: An array and its size
 * Returns: Void
 * Pre: None
 * Post: None
*/
void printArray(string * arr, const int size){
	for (int i = 0; i < size; i++){
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

/*
Function: openFile()
 * Date Created: 02/06/2022
 * Date Last Modified: 02/06/2022
 * Description: This function swaps two integers
 * Input parameters: Two integers
 * Returns: None
 * Pre: Two intergers must be previously intialized and passed by reference
 * Post: None
 * Note: Adapted from Gaddis
*/
void swap(int &a, int &b) {
  	int temp = a;
  	a = b;
  	b = temp;
}

/*
Function: bubbleSort()
 * Date Created: 02/06/2022
 * Date Last Modified: 02/19/2022
 * Description: This function performs bubble sort early exit algorithm
 * Input parameters: Two integers
 * Returns: None
 * Pre: Two intergers must be previously intialized and passed by reference
 * Post: None
 * Note: Adapted from Gaddis and PA2
*/
void bubbleSort(string * array, const int size){
	int maxElement, index;

  	for (maxElement = size - 1; maxElement > 0; maxElement--) {
    	for (index = 0; index < maxElement; index++) {
      		if (*(array + index) > *(array + (index + 1))) {
        		swap(*(array + index), *(array + (index + 1)));
      		}
    	}
  	}
}

/*
Function: sortedChecking()
 * Date Created: 02/06/2022
 * Date Last Modified: 02/07/2022
 * Description: This function checks if a vector is sorted
 * Input parameters: A vector
 * Returns: Boolean value of true or false
 * Pre: None
 * Post: None
 * Note: Adpatded from PA2
*/
bool sortedChecking(string * array, const int size){
	// Declare variables
    long count = 0;
    
	// Going through the array and counts how many times the array is sorted
    for (int i = 1; i < size; i++){
        if (*(array + (i - 1)) <= *(array + i)){
            count++;
        }
    }
    
	// Check if the array is sorted
    if (count == (size - 1)){
        return true;
    }
    else {
        return false;
    }
}