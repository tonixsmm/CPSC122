#include "PA4.h"

// TODO: finish the functions and define/call additional functions
Package * loadPackages(ifstream& inFile, string * driverName, int * numPackages) {
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
	string line;
	int count = 0;

	while (!inFile.eof()){
		getline(inFile, line);
		count++;
	}
	*numPackage = (count - 1) / 6; // Each package has 5 attributes, pluses one for an extra line at the end
}

void printStructArray(Package * packageArray, int size){
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
	string driverName;
	Package * packageArray;
	int numPackage;
	long position;

	openFile(inFile, filename);
	getline(inFile, driverName);
	position = inFile.tellg();

	countPackage(inFile, &numPackage);

	inFile.clear();
	inFile.seekg(position);

	packageArray = loadPackages(inFile, &driverName, &numPackage);
	printStructArray(packageArray, numPackage);

	delete [] packageArray;
	packageArray = NULL;

	inFile.close();
}