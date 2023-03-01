#include "PA4.h"

// TODO: finish the functions and define/call additional functions
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
	long position = 0;

	getline(inFile, *driverName);

	position = inFile.tellg();
	countPackage(inFile, numPackages);
	inFile.clear();
	inFile.seekg(position);

	Package * packageArray = new Package[*numPackages];

	for (int i = 0; i < *numPackages; i++){
		if (inFile.good()){
			inFile >> packageArray[i].id;
			inFile >> packageArray[i].weight;
			inFile >> packageArray[i].width;
			inFile >> packageArray[i].length;
			inFile >> packageArray[i].height;
		}
	}
	return packageArray;
}


void computePackageStats(const Package packages[], const int numPackages, int * heaviestId, double * heaviestWeight, double * avgWeight) {
	double aggregatedWeight = 0.0;
	*heaviestWeight = packages[0].weight;
	*heaviestId = packages[0].id;

	for (int i = 0; i < numPackages; i++){
		if (packages[i].weight > *heaviestWeight){
			*heaviestWeight = packages[i].weight;
			*heaviestId = packages[i].id;
		}
		aggregatedWeight += packages[i].weight;
	}

	*avgWeight = aggregatedWeight / numPackages;
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

void countPackage(ifstream& inFile, int * numPackage){
	string line = "";
	int count = 0;

	while (!inFile.eof()){
		getline(inFile, line);
		if (!inFile.bad()){
			count++;
		}
	}
	*numPackage = (count - 1) / 6; 
	// Each package has 5 attributes, pluses one for an extra line at the end. Therefore, divided by 6
}

void printPackageArray(Package * packageArray, int size){
	for (int i = 0; i < size; i++){
		cout << "Package ID: " << packageArray[i].id << endl;
		cout << "Package Weight: " << packageArray[i].weight << endl;
		cout << "Package Width: " << packageArray[i].width << endl;
		cout << "Package Length: " << packageArray[i].length << endl;
		cout << "Package Height: " << packageArray[i].height << endl;
		cout << endl;
	}
}

void checkInputFile(int argc){
	if (argc < 2){
		cout << "You did not enter a file name. The program has been terminated!" << endl;
		cout << "Please run it again using the correct format: ./runPA4 <YOUR RELATIVE FILE PATH>" << endl;
		exit(-1);
	}
}

void runReadFromFile(string filename){
	ifstream inFile;
	string driverName = "";
	Package * packageArray = nullptr;
	int numPackage = 0, heaviestId = 0;
	double heaviestWeight = 0.0, avgWeight = 0.0;

	openFile(inFile, filename);

	packageArray = loadPackages(inFile, &driverName, &numPackage);

	cout << "Number of packages on " << driverName << "'s truck: " << numPackage << endl;
	cout << endl;
	cout << "Package Information" << endl;
	cout << "-------------------" << endl;
	cout << endl;

	printPackageArray(packageArray, numPackage);

	computePackageStats(packageArray, numPackage, &heaviestId, &heaviestWeight, &avgWeight);

	cout << "Package Stats" << endl;
	cout << "-------------" << endl;
	cout << "ID of the heaviest package: " << heaviestId << endl;
	cout << "Weight of the heaviest package: " << heaviestWeight << endl;
	cout << "Average weight of packages on truck: " << avgWeight << endl;

	delete [] packageArray;
	packageArray = NULL;

	inFile.close();
}

LetterOccurrence * analyzeString(string userInput){
	istringstream iss;
	string word = "";
	int count = 0;

	LetterOccurrence * letterArray = new LetterOccurrence[123]; 
	// Size of 123 to cover just enought of the last lowercase character ASCII value

	iss.clear();
	iss.str(userInput);
	while (iss.good()) {
		iss >> word;
		for (char c : word){
			letterArray[static_cast<int>(c)].count += 1;
			count++;
		}
	}

	// ASCII value for uppercase characters. A is 65 and Z is 90
	for (int i = 65; i <= 90; i++){
		letterArray[i].frequency = static_cast<double>(letterArray[i].count) / count;
	}
	// ASCII value for lowercase characters. a is 97 and z is 122
	for (int i = 97; i <= 122; i++){
		letterArray[i].frequency = static_cast<double>(letterArray[i].count) / count;
	}

	return letterArray;
}

void printLetterArray(LetterOccurrence * letterArray){
	for (int i = 65; i <= 90; i ++){
		cout << char(i);
		cout << ": Count: " << letterArray[i].count;
		cout << " Freq: " << setprecision(2) << fixed << letterArray[i].frequency << endl;
	}
	for (int i = 97; i <= 122; i ++){
		cout << char(i);
		cout << ": Count: " << letterArray[i].count;
		cout << " Freq: " << setprecision(2) << fixed << letterArray[i].frequency << endl;
	}
}

int findMaxOccurrenceChar(LetterOccurrence * letterArray){
	int largestValue = letterArray[0].count;

	for (int i = 0; i < 123; i++){
		if (letterArray[i].count > largestValue){
			largestValue = letterArray[i].count;
		}
	}
	return largestValue;
}

void plotHistogram(LetterOccurrence * letterArray){
	int largestValue = findMaxOccurrenceChar(letterArray);

	char histArr[largestValue + 2][52];
	// There are 26 alphabetic character, times 2 for upper and lower cases. Hence, there are 52 "columns"
	// The character with the largest number of occurrence is the row size, pluses 1 for character line and 1 for line feed
	// Plotting algorithm
	for (int i = 65, m = 0; i <= 90; i++, m++){
		for (int j = 0; j < (largestValue - letterArray[i].count); j++){
			histArr[j][m] = ' ';
		}
		for (int k = 1; k <= (letterArray[i].count); k++){
			histArr[largestValue - k][m] = '*';
		}
		histArr[largestValue][m] = static_cast<char>(i);
	}
	for (int i = 97, m = 26; i <= 122; i++, m++){
		for (int j = 0; j < (largestValue - letterArray[i].count); j++){
			histArr[j][m] = ' ';
		}
		for (int k = 1; k <= (letterArray[i].count); k++){
			histArr[largestValue - k][m] = '*';
		}
		histArr[largestValue][m] = static_cast<char>(i);
	}
	cout << endl;

	// Print out the histogram
	for (int i = 0; i < (largestValue + 1); i++){
		for (int j = 0; j < 52; j++){
			cout << histArr[i][j];
		}
		cout << endl;
	}
}

void charStats(LetterOccurrence * letterArray){
	int maxOccurrence = letterArray[0].count, maxIndex = 0;

	for (int i = 0; i < 123; i++){
		if (letterArray[i].count > maxOccurrence){
			maxOccurrence = letterArray[i].count;
			maxIndex = i;
		}
	}

	string tempString1(1, static_cast<char>(maxIndex));
	string tempString2 = to_string(maxOccurrence);
	string tempString3 = to_string(letterArray[maxIndex].frequency);

	for (int i = 0; i < 123; i++){
		if (letterArray[i].count == maxOccurrence && static_cast<char>(i) != static_cast<char>(maxIndex)){
			string tempString4(1, static_cast<char>(i));
			tempString1 += ", " + tempString4;

			tempString2 += ", ";
			tempString2 += to_string(letterArray[i].count);

			tempString3 += ", ";
			tempString3 += to_string(letterArray[i].frequency);
		}
	}

	// Print responses
	cout << endl;
	cout << "The letter with the maximum number of occurrences: " << tempString1 << endl;
	cout << "The number of occurrences of the letter with the maximum number of occurrences: " << tempString2 << endl;
	cout << "The frequency of the letter with the maximum number of occurrences: " << tempString3 << endl;
	cout << endl;
}

void runBonus(void){
	string userInput = "", userResponse = "";
	LetterOccurrence * letterArray;
	
	do {
		userResponse = "";
		cout << "Please enter a string that only contains alphabet characters: " << endl;
		getline(cin, userInput);
		cout << endl;

		letterArray = analyzeString(userInput);
		cout << "Letter Histogram" << endl;
		plotHistogram(letterArray);
		charStats(letterArray);

		cout << "Do you want to continue? Enter 'quit' to stop the program or any key to continue" << endl;
		getline(cin, userResponse);
	} while (userResponse != "quit");

	delete [] letterArray;
	letterArray = nullptr;
}