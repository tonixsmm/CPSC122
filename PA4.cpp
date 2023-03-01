/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 1, 2022
Programming Assignment: PA4
Description: This program implements several tasks required by PA4
Note: I attempted the bonus. Please run PA4BonusMain.cpp to see the bonus part
*/

#include "PA4.h"

/*
Function: loadPackages()
 * Date Created: 02/26/2022
 * Date Last Modified: 02/26/2022
 * Description: This function processes the package information in the file 
 * Input parameters: File stream, one string pointer, one int pointer
 * Returns: A dynamically allocated array of struct Package
 * Pre: None
 * Post: None
*/
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
	long position = 0;

	// Read the driver name
	getline(inFile, *driverName);

	// Count the number of packages and set the cursor back to the reading position
	position = inFile.tellg();
	countPackage(inFile, numPackages);
	inFile.clear();
	inFile.seekg(position);

	// Dynamically allocate packageArray
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

/*
Function: computePackageStats()
 * Date Created: 02/26/2022
 * Date Last Modified: 02/26/2022
 * Description: This function computes package statistics
 * Input parameters: An struct Package array, an int, one int pointer, and two double pointers
 * Returns: None
 * Pre: None
 * Post: None
*/
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

/*
Function: countPackage()
 * Date Created: 02/26/2022
 * Date Last Modified: 02/26/2022
 * Description: This function computes package statistics
 * Input parameters: A struct Package array, an int, one int pointer, and two double pointers
 * Returns: None
 * Pre: None
 * Post: None
*/
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
	// Each package has 5 attributes, pluses one for an extra line at the end. Therefore, I divided the count by 6
}

/*
Function: printPackageArray()
 * Date Created: 02/26/2022
 * Date Last Modified: 02/26/2022
 * Description: This function prints Struct Package array
 * Input parameters: A struct Package array, and an int
 * Returns: None
 * Pre: None
 * Post: None
*/
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

/*
Function: checkInputFile()
 * Date Created: 02/27/2022
 * Date Last Modified: 02/27/2022
 * Description: This function checks if the user entered a file name
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
*/
void checkInputFile(int argc){
	if (argc < 2){
		cout << "You did not enter a file name. The program has been terminated!" << endl;
		cout << "Please run it again using the correct format: ./runPA4 <YOUR RELATIVE FILE PATH>" << endl;
		exit(-1);
	}
}

/*
Function: runReadFromFile()
 * Date Created: 02/26/2022
 * Date Last Modified: 02/27/2022
 * Description: This is an utility functions that executes PA4's requirements
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
*/
void runReadFromFile(string filename){
	// Declare variables
	ifstream inFile;
	string driverName = "";
	Package * packageArray = nullptr;
	int numPackage = 0, heaviestId = 0;
	double heaviestWeight = 0.0, avgWeight = 0.0;

	// Open file and run loadPackages()
	openFile(inFile, filename);
	packageArray = loadPackages(inFile, &driverName, &numPackage);

	cout << "Number of packages on " << driverName << "'s truck: " << numPackage << endl;
	cout << endl;
	cout << "Package Information" << endl;
	cout << "-------------------" << endl;
	cout << endl;

	// Print package array
	printPackageArray(packageArray, numPackage);

	// Compute and print package stats
	computePackageStats(packageArray, numPackage, &heaviestId, &heaviestWeight, &avgWeight);
	cout << "Package Stats" << endl;
	cout << "-------------" << endl;
	cout << "ID of the heaviest package: " << heaviestId << endl;
	cout << "Weight of the heaviest package: " << heaviestWeight << endl;
	cout << "Average weight of packages on truck: " << avgWeight << endl;

	// Deallocate memory
	delete [] packageArray;
	packageArray = NULL;

	inFile.close();
}

/*
Function: analyzeString()
 * Date Created: 02/27/2022
 * Date Last Modified: 02/28/2022
 * Description: This function reads in a string, counts the string characters, and calculates their frequencies
 * Input parameters: A string
 * Returns: A struct LetterOccurrence array
 * Pre: None
 * Post: None
*/
LetterOccurrence * analyzeString(string userInput){
	// Declare variables
	istringstream iss;
	string word = "";
	int count = 0;

	// Create a LetterOccurrence array, walk through the string, and count their characters
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

	// Calculate the frequency of each character
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

/*
Function: checkInputFile()
 * Date Created: 02/27/2022
 * Date Last Modified: 02/28/2022
 * Description: This function prints out the LetterOccurrence array
 * Input parameters: A struct LetterOccurrence array
 * Returns: None
 * Pre: None
 * Post: None
*/
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

/*
Function: findMaxOccurrenceChar()
 * Date Created: 02/26/2022
 * Date Last Modified: 02/27/2022
 * Description: This function finds the character that has the largest number of occurrences
 * Input parameters: A struct LetterOccurrence array
 * Returns: An int
 * Pre: None
 * Post: None
*/
int findMaxOccurrenceChar(LetterOccurrence * letterArray){
	int largestValue = letterArray[0].count;

	for (int i = 0; i < 123; i++){
		if (letterArray[i].count > largestValue){
			largestValue = letterArray[i].count;
		}
	}
	return largestValue;
}

/*
Function: plotHistogram()
 * Date Created: 02/27/2022
 * Date Last Modified: 02/28/2022
 * Description: This function prints out the histogram
 * Input parameters: A struct LetterOccurrence array
 * Returns: None
 * Pre: None
 * Post: None
*/
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

/*
Function: charStats()
 * Date Created: 02/27/2022
 * Date Last Modified: 02/28/2022
 * Description: This function computes and prints out the statistics of the characters
 * Input parameters: A struct LetterOccurrence array
 * Returns: None
 * Pre: None
 * Post: None
*/
void charStats(LetterOccurrence * letterArray){
	int maxOccurrence = letterArray[0].count, maxIndex = 0;

	for (int i = 0; i < 123; i++){
		if (letterArray[i].count > maxOccurrence){
			maxOccurrence = letterArray[i].count;
			maxIndex = i;
		}
	}

	// Algorithm to check if there are multiple characters with the same number of occurrences
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

/*
Function: runBonus()
 * Date Created: 02/27/2022
 * Date Last Modified: 02/28/2022
 * Description: This is an utility function that runs the bonus requirements
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
void runBonus(void){
	// Declare variables
	string userInput = "", userResponse = "";
	LetterOccurrence * letterArray;
	
	do {
		// Process input string
		userResponse = "";
		cout << "Please enter a string that only contains alphabet characters: " << endl;
		getline(cin, userInput);
		cout << endl;

		// Plot histogram and print statistics
		letterArray = analyzeString(userInput);
		cout << "Letter Histogram" << endl;
		plotHistogram(letterArray);
		charStats(letterArray);

		// Ask user if they want to continue
		cout << "Do you want to continue? Enter 'quit' to stop the program or any key to continue" << endl;
		getline(cin, userResponse);
	} while (userResponse != "quit");

	// Free memory
	delete [] letterArray;
	letterArray = nullptr;
}