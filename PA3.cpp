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
	string * stringArr = new string[size];
	string line, word;
	istringstream iss;

	for (int i = 0; i < 2; i++){
		int count = 0;

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
	bubbleSort(stringArr, size);

	return stringArr;
}

void generateSentence(string * sentence,
		const string * articlesArr, const int articlesSize,
		const string * nounsArr, const int nounsSize,
		const string * verbsArr, const int verbsSize, 
		const string * prepsArr, const int prepsSize) {
	
	string tempElem;

	tempElem = *(articlesArr + (rand() % articlesSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');
		
	tempElem = *(nounsArr + (rand() % nounsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	tempElem = *(verbsArr + (rand() % verbsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	tempElem = *(prepsArr + (rand() % prepsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	tempElem = *(articlesArr + (rand() % articlesSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}
	sentence->push_back(' ');

	tempElem = *(nounsArr + (rand() % nounsSize));
	for (char c : tempElem){
		sentence->push_back(c);
	}

	// Formatting sentence
	sentence->push_back('!');
	sentence->at(0) = toupper(sentence->at(0));

}

void runTask3(){
	ifstream inFile;
	string sentence;
	string * articlesArr = NULL;
	string * nounsArr = NULL;
	string * verbsArr = NULL;
	string * prepsArr = NULL;
	string checkPartOfSpeech;
	int articlesSize = 0, nounsSize = 0, verbsSize = 0, prepsSize = 0, sentenceSize = 0;

	openFile(inFile, "../input_words.txt");
	inFile >> sentenceSize;

	cout << "WORD BANK" << endl;
	cout << "=========" << endl;
	for (int i = 0; i < 4; i++){
		inFile >> checkPartOfSpeech;
		if (checkPartOfSpeech == "Articles"){
			inFile >> articlesSize;
			articlesArr = createWordsArray(inFile, articlesSize);
			cout << "Articles: ";
			printArray(articlesArr, articlesSize);
		}
		else if (checkPartOfSpeech == "Nouns"){
			inFile >> nounsSize;
			nounsArr = createWordsArray(inFile, nounsSize);
			cout << "Nouns: ";
			printArray(nounsArr, nounsSize);
		}
		else if (checkPartOfSpeech == "Verbs"){
			inFile >> verbsSize;
			verbsArr = createWordsArray(inFile, verbsSize);
			cout << "Verbs: ";
			printArray(verbsArr, verbsSize);
		}
		else if (checkPartOfSpeech == "Prepositions"){
			inFile >> prepsSize;
			prepsArr = createWordsArray(inFile, prepsSize);
			cout << "Prepositions: ";
			printArray(prepsArr, prepsSize);
		}
	}
	
	cout << endl;
	cout << "GENERATED SENTENCES" << endl;
	cout << "===================" << endl;
	for (int i = 0; i < sentenceSize; i++){
		sentence.clear();
		generateSentence(&sentence, articlesArr, articlesSize, nounsArr, nounsSize, verbsArr, verbsSize, prepsArr, prepsSize);
		cout << i + 1 << ". " << sentence << endl;
	}

	inFile.close();
	delete [] articlesArr;
	delete [] nounsArr;
	delete [] verbsArr;
	delete [] prepsArr;
}

void printArray(string * arr, const int size){
	for (int i = 0; i < size; i++){
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

void swap(int &a, int &b) {
  	int temp = a;
  	a = b;
  	b = temp;
}

void bubbleSort(string * array, const int size){
	int maxElement;
  	int index;

  	for (maxElement = size - 1; maxElement > 0; maxElement--) {
    	for (index = 0; index < maxElement; index++) {
      		if (array[index] > array[index + 1]) {
        		swap(array[index], array[index + 1]);
      		}
    	}
  	}
}