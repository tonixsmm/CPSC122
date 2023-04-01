#include "SongLibrary.h"


SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

SongLibrary::SongLibrary(const SongLibrary& other) {
	head = NULL;
	sortAttribute = other.sortAttribute;

	Song * curr = other.head; 
	while (curr != NULL){
		Song * newSong = new Song(*curr);
		performInsertSongInOrder(newSong);
		curr = curr->getNext();
	}
}


SongLibrary::~SongLibrary() {
	destroyList();
}

Song * SongLibrary::getHead() const {
	return head;
}

void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
}

string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

/*
Function: performLoad()
 * Date Created: 03/15/2023
 * Date Last Modified: 4/1/2023
 * Description: This function performs the loading requirement of PA5
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performLoad(string filename) {
	ifstream inFile;
	int numSongFromFile = 0;

	openFile(inFile, filename);

	// Count the number of song in the input file
	numSongFromFile = countSongFromFile(inFile);
	inFile.clear();
	inFile.seekg(0);

	loadSongFromFile(inFile, numSongFromFile);

	inFile.close();
}

/*
Function: performSave()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/19/2023
 * Description: This function saves the available songs in the songs array to a file
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performSave(string filename) {
	fstream outFile;
	outFile.open(filename, ios::out);
	Song * curr = head;

	while (curr != NULL){
		outFile << curr->getTitle() << endl;
		outFile << curr->getArtist() << endl;
		outFile << curr->getGenre() << endl;
		outFile << curr->getRating() << endl;
		outFile << endl; 
		curr = curr->getNext();
	}

	outFile.close();
}

// TODO: finish this function
void SongLibrary::performSort() {

}

// TODO: finish this function
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	
	return NULL; // TODO: fix this
}

// TODO: finish this function
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	if (head == NULL){
		head = songToInsert;
	}
	else {
		Song * currSong = head;
		Song * prevSong = NULL;

		while (currSong != NULL && currSong->getStringAttributeValue(sortAttribute) < songToInsert->getStringAttributeValue(sortAttribute)){
			prevSong = currSong;
			currSong = currSong->getNext();
		}

		if (prevSong == NULL){
			head = songToInsert;
			songToInsert->setNext(currSong);
		}
		else{
			songToInsert->setNext(currSong);
			prevSong->setNext(songToInsert);
		}
	}
}


// TODO: finish this function
void SongLibrary::performRemoveSong(Song * songToRemove) {
	
}

// TODO: finish this function
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
	
}


void SongLibrary::destroyList(){
	Song * currNode = NULL;
    Song * nextNode = NULL;

    while (currNode != NULL){
        nextNode = currNode->getNext();
        delete currNode;
        currNode = nextNode;
    }
    head = NULL;
}

/*
Function: displayLibrary()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/31/2023
 * Description: This function prints out the songs array
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::displayLibrary(){
	int count = 0;

	cout << endl << "All Songs In The Library" << endl;
	cout << "------------------------" << endl;
	cout << endl;

	Song * curr = head;
	while (curr != NULL){
		cout << "SONG " << count << endl;
		curr->displaySong();
		cout << endl;

		curr = curr->getNext();
		count++;
	}
}

void SongLibrary::addToEnd(Song * newSong){
	if (head == NULL){
        head = newSong;
	    }
    else {
        Song * currNode = head;
        while (currNode->getNext() != NULL){
            currNode = currNode->getNext();
        }
        currNode->setNext(newSong);
    }
}

void SongLibrary::addToFront(Song * newSong){
    if (head == NULL){
        head = newSong;
    }
    else {
        newSong->setNext(head);
        head = newSong;
    }
}

void SongLibrary::reverseList(){
	Song * curr = head;
	Song * prev = NULL;
	Song * nextNode = NULL;

	while (curr != NULL){
		nextNode = curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = nextNode;
	}
	head = prev;
}

/*
openFile
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
Function: countSongFromFile()
 * Date Created: 02/26/2023
 * Date Last Modified: 03/17/2023
 * Description: This function counts the number of song in the input file
 * Input parameters: A file stream
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This function is adapted from PA4
*/
int countSongFromFile(ifstream & inFile){
	int count = 0, numSongFromFile = 0;
	string line = "";

	while (!inFile.eof()){
		getline(inFile, line);
		if (!inFile.bad()){
			count++;
		}
	}
	// There are 4 attributes, plus 1 empty line. So, I divide by 5.
	numSongFromFile = count / 5;

	return numSongFromFile;
}

/*
Function: loadSongFromFile()
 * Date Created: 03/16/2023
 * Date Last Modified: 03/18/2023
 * Description: This function reads in new songs from the input file, decides whether there has been a similar song already in the array. If not, then add it in
 * Input parameters: A file stream, an int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::loadSongFromFile(ifstream & inFile, int numSongFromFile){
	string tempTitle = "", tempArtist = "", tempGenre = "", tempLine = "", tempRating = "";

	// Read in from file
	for (int i = 0; i < numSongFromFile; i++){
		if (!inFile.bad()){
			getline(inFile, tempTitle);
			getline(inFile, tempArtist);
			getline(inFile, tempGenre);
			getline(inFile, tempRating);
			getline(inFile, tempLine);
		}

		Song * tempSong = new Song(tempTitle, tempArtist, tempGenre, stoi(tempRating));
		tempSong->setNext(NULL);

		// Check if there's a song that has already been in the library. If so, not adding it.
		if (head != NULL){
			Song * curr = head;
			while (curr != NULL && curr->getTitle() != tempTitle && curr->getArtist() != tempArtist){\
				curr = curr->getNext();
			}

			if (curr == NULL){
				performInsertSongInOrder(tempSong);
			}
		}
		else{
			head = tempSong;
		}
	}
}

/*
loadLi
Function: loadLibrary()
 * Date Created: 03/18/2023
 * Date Last Modified: 03/18/2023
 * Description: This is a helper function to call performLoad() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::loadLibrary(){
	string fileName = "";

	cout << "Please enter filename to be opened: ";
	cin >> fileName;
	// fileName = "../library.txt";

	performLoad(fileName);
}

/*
Function: saveLibrary()
 * Date Created: 03/19/2023
 * Date Last Modified: 03/19/2023
 * Description: This is a helper function to call performSave() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::saveLibrary(){
	string fileName = "";

	cout << "Enter the filename that you want to save your library to: ";
	cin >> fileName;

	performSave(fileName);;
}