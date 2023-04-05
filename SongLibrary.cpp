/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 4, 2023
Programming Assignment: PA6
Description: This program implements several tasks required by PA6
*/

#include "SongLibrary.h"

/*
SongLibrary()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the default value constructor of the SongLibrary class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
SongLibrary::SongLibrary() {
	head = NULL; 
	sortAttribute = "title";
}
/*
SongLibrary
 * Date Created: 04/01/2023
 * Date Last Modified: 04/02/2023
 * Description: This is the copy constructor of the SongLibrary class
 * Input parameters: A SongLibrary object passed by reference
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/

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

/*
~SongLibrary()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the destructor of the SongLibrary class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
SongLibrary::~SongLibrary() {
	destroyList();
}

/*
Function: getHead()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the head getter of the SongLibrary class
 * Input parameters: None
 * Returns: A Song object pointer
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
Song * SongLibrary::getHead() const {
	return head;
}

/*
Function: setHead()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the head setter of the SongLibrary class
 * Input parameters: A Song object pointer
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
}

/*
Function: setHeadWithoutFreeing()
 * Date Created: 04/04/2023
 * Date Last Modified: 04/04/2023
 * Description: This is the head setter of the SongLibrary class. This setter does not free memory of the current head
 * Input parameters: A Song object pointer
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::setHeadWithoutFreeing(Song * newHead){
	head = newHead;
}

/*
Function: getSortAttribute()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This function returns the attribute that the SongLibrary list is sorted by
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

/*
Function: setSortAttribute()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This function returns the attribute that the SongLibrary list is sorted by
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

/*
Function: performLoad()
 * Date Created: 03/15/2023
 * Date Last Modified: 4/1/2023
 * Description: This function performs the loading task
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
 * Date Last Modified: 04/01/2023
 * Description: This function saves Song objects of the linked list to a file
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

/*
Function: performSort()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/04/2023
 * Description: This function sorts Song objects of the linked list based on sortAttribute member
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performSort() {
	// Copy constructor calls performInsertInOrder(), implementing insertion sort
	SongLibrary * tempLibrary = new SongLibrary(*this);
	Song * tempHead = tempLibrary->getHead();
	this->setHead(tempHead); // setHead() frees "this" SongLibrary, then set head to tempLibrary's head

	// Free memory
	tempLibrary->setHeadWithoutFreeing(NULL);
	delete tempLibrary;
}

/*
Function: performSave()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/03/2023
 * Description: This function searches for a Song object in a SongLibrary linked list and returns a pointer to that object if found
 * Input parameters: Two strings, a bool pointer, an int pointer
 * Returns: A Song pointer
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	*found = false;
	Song * curr = head;
	int count = 0;

	// Search by Song object's attributes
	if (searchAttribute != "index"){
		searchAttributeValue = convertToLowercase(searchAttributeValue);

		while (curr != NULL && curr->getStringAttributeValue(searchAttribute) != searchAttributeValue){
			curr = curr->getNext();
			count++;
		}
		if (curr != NULL){
			*found = true;
			*index = count;
			return curr;
		}
	}
	// Search by Song object's "index", AKA position number in the list
	else if (searchAttribute == "index"){
		while (curr != NULL && count != stoi(searchAttributeValue)){
			curr = curr->getNext();
			count++;
		}
		if (curr != NULL){
			*found = true;
			*index = count;
			return curr;
		}
	}
	return NULL;
}

/*
Function: performInsertSongInOrder()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This function inserts a Song object to a SongLibrary linked list in order of sortAttribute member
 * Input parameters: A Song object pointer
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
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
			songToInsert->setNext(currSong);
			head = songToInsert;
		}
		else{
			songToInsert->setNext(currSong);
			prevSong->setNext(songToInsert);
		}
	}
}

/*
Function: performRemoveSong()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This function removes a Song object from a SongLibrary linked list
 * Input parameters: A Song object pointer
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performRemoveSong(Song * songToRemove) {
	if (head != NULL && songToRemove != NULL){
		Song * curr = head;
		if (head == songToRemove){
			head = head->getNext();
			delete curr;
		}
		else {
			Song * prev = NULL;
			while (curr != songToRemove){
				prev = curr;
				curr = curr->getNext();
			}
			prev->setNext(curr->getNext());
			delete curr;
		}
	}
}

/*
Function: performEditSong()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This function edits a Song object's attributes of a SongLibrary linked list
 * Input parameters: A Song object pointer, two strings
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
	if (songToEdit != NULL){
		Song * curr = head;
		while (curr != songToEdit){
			curr = curr->getNext();
		}

		if (attribute == "title"){
			curr->setTitle(convertToLowercase(newAttributeValue));
		}
		else if (attribute == "artist"){
			curr->setArtist(convertToLowercase(newAttributeValue));
		}
		else if (attribute == "genre"){
			curr->setGenre(convertToLowercase(newAttributeValue));
		}
		else {
			if (stoi(newAttributeValue) >= 1 && stoi(newAttributeValue) <= 5){
				curr->setRating(stoi(newAttributeValue));
			}
			else {
				curr->setRating(stoi(newAttributeValue));
				cout << "Your song rating has been overwritten to " << curr->getRating() << endl;
			}
		}
	}
}

/*
Function: destroyList()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This function frees memory address of a list's objects and sets the head pointer to NULL
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::destroyList(){
	Song * currNode = head;
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
 * Date Last Modified: 04/04/2023
 * Description: This function reads in new songs from the input file, decides whether there has been a similar song already in the array. If not, then add it in
 * Input parameters: A file stream passed by reference, an int
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

		Song tempSong(tempTitle, tempArtist, tempGenre, stoi(tempRating));
		Song * tempSongPtr = new Song(tempSong);

		// Check if there's a song that has already been in the library. If so, not adding it.
		if (head != NULL){
			Song * curr = head;
			while (curr != NULL && curr->getTitle() != tempTitle && curr->getArtist() != tempArtist){
				curr = curr->getNext();
			}

			if (curr == NULL){
				performInsertSongInOrder(tempSongPtr);
			}
			// If a song is already on the list, then not adding to the list anymore. Hence, delete that Song object
			else {
				delete tempSongPtr;
				tempSongPtr = NULL;
			}
		}
		if (head == NULL) {
			setHead(tempSongPtr);
		}
	}
}

/*
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

/*
Function: sortLibrary()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is a helper function to call performSort() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::sortLibrary(){
	string userInput = "";

	cout << "Please enter the attribute that you want to sort by (title, artist, genre, rating): ";
	cin >> userInput;
	sortAttribute = convertToLowercase(userInput);

	performSort();
}

/*
Function: searchLibrary()
 * Date Created: 03/20/2023
 * Date Last Modified: 04/03/2023
 * Description: This is a helper function to call performSearch() from command line and prints it out if there is a match
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::searchLibrary(){
	string searchAttribute = "", searchAttributeValue = "";
	Song * foundSong;
	int index = -1;
	bool searchResult = false;

	cout << "Please enter the attribute that you want to search for (title, artist, genre, or rating). If you want to search by index, please enter 'index': ";
	getline(cin, searchAttribute);
	cout << "Please enter the attribute value to be searched. If you search by song index, please enter the index number: ";
	getline(cin, searchAttributeValue);

	foundSong = performSearch(searchAttribute, searchAttributeValue, &searchResult, &index);

	if (searchResult == true) {
		cout << "A song with the given information is found!" << endl;
		cout << endl << "Song Information" << endl;
		cout << "----------------" << endl;
		foundSong->displaySong();
	}
	else {
		cout << "A song with the given information is not found!" << endl;
	}
}

/*
Function: insertSongInLibraryOrder()
 * Date Created: 03/17/2023
 * Date Last Modified: 04/01/2023
 * Description: This is a helper function to call performAddSong() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::insertSongInLibraryOrder(){
	string tempString = "";
	Song tempSong;

	cout << "Please enter the song title: ";
	getline(cin, tempString);
	tempSong.setTitle(tempString);

	cout << "Please enter the song artist: ";
	getline(cin, tempString);
	tempSong.setArtist(tempString);

	cout << "Please enter the song genre: ";
	getline(cin, tempString);
	tempSong.setGenre(tempString);

	cout << "Please enter the song rating: ";
	getline(cin, tempString);
	tempSong.setRating(stoi(tempString));

	Song * tempSongPtr = new Song(tempSong);
	tempSongPtr->setNext(NULL);
	performInsertSongInOrder(tempSongPtr);
}

/*
Function: removeSongFromLibrary()
 * Date Created: 03/20/2023
 * Date Last Modified: 04/03/2023
 * Description: This is a helper function to call performRemoveSong() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::removeSongFromLibrary(){
	string searchAttribute = "", searchAttributeValue = "";
	Song * foundSong;
	int index = -1;
	bool searchResult = false;

	// Search for song to remove
	cout << ".....Searching for the song to remove....." << endl;
	cout << "Please enter the attribute that you want to search for (title, artist, genre, or rating). If you want to search by index, please enter 'index': ";
	getline(cin, searchAttribute);
	cout << "Please enter the attribute value to be searched. If you search by song index, please enter the index number: ";
	getline(cin, searchAttributeValue);

	foundSong = performSearch(searchAttribute, searchAttributeValue, &searchResult, &index);

	if (searchResult == true){
		cout << endl << "Match song information:" << endl;
		foundSong->displaySong();
		performRemoveSong(foundSong);
		cout << endl << "Remove successfully!" << endl;
	}
	else {
		cout << "No song found to delete!" << endl;
	}
}

/*
Function: editSongInLibrary()
 * Date Created: 03/20/2023
 * Date Last Modified: 04/03/2023
 * Description: This is a helper function to call performEdit() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::editSongInLibrary(){
	string searchAttribute = "", searchAttributeValue = "", newAttribute = "", newAttributeValue = "";
	Song * foundSong;
	int index = -1;
	bool searchResult = false;

	// Search for song to edit
	cout << ".....Searching for the song to edit....." << endl;
	cout << "Please enter the attribute that you want to search for (title, artist, genre, or rating). If you want to search by index, please enter 'index': ";
	getline(cin, searchAttribute);
	cout << "Please enter the attribute value to be searched. If you search by song index, please enter the index number: ";
	getline(cin, searchAttributeValue);

	foundSong = performSearch(searchAttribute, searchAttributeValue, &searchResult, &index);

	if (searchResult == true){
		cout << endl << "Match song information:" << endl;
		foundSong->displaySong();

		// Editing song attribute
		cout << endl << ".....Editing song attribute......" << endl;
		cout << "Please enter the attribute that you want to edit (title, artist, genre, or rating): ";
		getline(cin, newAttribute);
		cout << "Please enter the new attribute value: ";
		getline(cin, newAttributeValue);

		performEditSong(foundSong, newAttribute, newAttributeValue);
	}
	else {
		cout << "No song found to edit!" << endl;
	}
}