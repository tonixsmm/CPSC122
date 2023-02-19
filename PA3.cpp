#include "PA3.h"

////////////////////////////////////
// TASK 1
////////////////////////////////////
// TODO: finish the function and define/call three additional functions
void answerIntegerQuestions(int num, bool * isMultiple, bool * isSumEven, bool * isPrime) {
	// call a function to answer the first question
	*isMultiple = checkMultiplication(num);
	// call a function to answer the second question
	*isSumEven = checkSumEven(num);
	// call a function to answer the third question
	*isPrime = checkPrime(num);
}

bool checkMultiplication(int num){
	if (num % 7 == 0 || num % 11 == 0 || num % 13 == 0){
		return true;
	}
	else{
		return false;
	}
}

bool checkSumEven(int num){
	int sum = 0;

	string numConverted = to_string(num);
	for (char i : numConverted){
		sum += int(i);
	}

	if (sum % 2 == 0){
		return true;
	}
	else{
		return false;
	}
}

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

void runTask1(){
	ifstream inFile;
	bool isMultiple, isSumEven, isPrime;
	string line;
	int num;

	openFile(inFile, "../numbers.txt");

	while (!inFile.eof()){
		getline(inFile, line);

		if (inFile.good()){
			num = stoi(line);
			answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);

			cout << "Number " << num;

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
// TODO: finish the function
bool findWinningLotteryTicket(const int winningTicketNum, const int * playerNumbers, const int numPlayerNumbers) {
	for (int i = 0; i < numPlayerNumbers; i++){
		if (*(playerNumbers + i) == winningTicketNum){
			return true;
		}
	}
	return false;
}

void runTask2(){
	int playerNums[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
	int playerNumsSize = 10, winningNum = 0;
	bool winner = false;

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
// TODO: finish the functions and define additional functions
string * createWordsArray(ifstream& inFile, const int size) {

	return NULL;
}



void generateSentence(string * sentence,
		const string * articlesArr, const int articlesSize,
		const string * nounsArr, const int nounsSize,
		const string * verbsArr, const int verbsSize, 
		const string * prepsArr, const int prepsSize) {
	
}
