#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void openFile(ifstream&, string);
void processFile(ifstream&);

int main(){
	// Open file
	ifstream inFile;
	openFile(inFile, "sentence.txt");
	// Process file
	processFile(inFile);
	// Close file
	inFile.close();
	return 0;
}

void openFile(ifstream& inFile, string fname){
	inFile.open(fname);
	if (inFile.is_open()){
		cout << "Successfully opened file" << endl;
	}
	else {
		cout << "Failed to open file" << endl;
		exit(-1); // to kill the program
	}
}

void processFile(ifstream& inFile){
	string line, word;
	istringstream iss;

	ofstream outFile;
	outFile.open("chars.txt");

	while(!inFile.eof()){
		getline(inFile, line);
		if (inFile.good()){
			// to read line by line from the file
			// cout << line << endl;

			// to read word by word from the line
			iss.clear(); // clear out state from previous iteration
			iss.str(line);
			while(iss.good()){
				iss >> word;
				cout << word << endl;

				// to read character by character from the word
				for (char c : word){ // range-based for loop
					outFile << c << endl;
				}

				// or the normal for loop
				// for (int i = 0; i < word.length(); i++){
				// 	cout << word[i] << endl;
				// }
			}
		}
	}
	outFile.close();
}
