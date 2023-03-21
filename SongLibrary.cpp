/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 21, 2022
Programming Assignment: PA5
Description: This program implements several tasks required by PA5
Note: I attempted the bonus
*/

#include "SongLibrary.h"

/*
Function: Song()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the default value constructor of the SongLibrary class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
SongLibrary::SongLibrary() {
	numSongs = 0;
	songs = nullptr; 
}

/*
Function: Song()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the destructor of the SongLibrary class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
SongLibrary::~SongLibrary() {
	if (songs != nullptr){
		delete [] songs;
		songs = nullptr;
		numSongs = 0;
	}
}

/*
Function: getNumSongs()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "numSongs" getter of the SongLibrary class
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
int SongLibrary::getNumSongs() {
	return numSongs;
}

/*
Function: getNumSongs()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "numSongs" setter of the SongLibrary class
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

/*
Function: getSongsArray()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "songs" getter of the SongLibrary class
 * Input parameters: None
 * Returns: A Song object
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
Song * SongLibrary::getSongsArray() {
	return songs;
}

/*
Function: getSongsArray()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "songs" setter of the SongLibrary class
 * Input parameters: A Song object pointer
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

/*
Function: displayArray()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This function prints out the songs array
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::displayLibrary() {
	cout << "All Songs In The Library" << endl;
	cout << "------------------------" << endl;
	cout << endl;

	for (int i = 0; i < numSongs; i++){
		cout << "SONG " << i << endl;
 		songs[i].displaySong();
		cout << endl;
	}
}

/*
Function: performLoad()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/19/2023
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

	// Iterate through the songs array
	for (int i = 0; i < numSongs; i++){
		outFile << songs[i].getTitle() << endl;
		outFile << songs[i].getArtist() << endl;
		outFile << songs[i].getGenre() << endl;
		outFile << songs[i].getRating() << endl;
		outFile << endl;
	}

	outFile.close();
}

/*
Function: performSort()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/20/2023
 * Description: This function performs binary sorts on the songs array
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function. The function algorithm is adapted from PA2.
*/
void SongLibrary::performSort(string attribute) {
	int maxElement = 0, index = 0;

  	for (maxElement = numSongs - 1; maxElement > 0; maxElement--) {
    	for (index = 0; index < maxElement; index++) {
      		if (songs[index].getStringAttributeValue(attribute) > songs[index + 1].getStringAttributeValue(attribute) && songs[index].getStringAttributeValue(attribute) != "" && songs[index + 1].getStringAttributeValue(attribute) != "") {
        		swap(songs[index], songs[index + 1]);
      		}
    	}
  	}
}

/*
Function: performSearch()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/20/2023
 * Description: This function searchs for the first match based on a given attribute value
 * Input parameters: Two strings, a Song object pointer, and int pointer
 * Returns: Bool
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	searchAttributeValue = convertToLowercase(searchAttributeValue);

	// Iterate through the songs array
	for (int i = 0; i < numSongs; i++){
		if (songs[i].getStringAttributeValue(searchAttribute) == searchAttributeValue){
			foundSong->setTitle(songs[i].getTitle());
			foundSong->setArtist(songs[i].getArtist());
			foundSong->setGenre(songs[i].getGenre());
			foundSong->setRating(songs[i].getRating());
			*index = i;
			return true;
		}
		else {
			*index = -1;
		}
	}
	return false;
}

/*
Function: performAddSong()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/18/2023
 * Description: This function adds a song to the songs array
 * Input parameters: A Song object
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performAddSong(Song newSong) {
	numSongs += 1;

	Song * tempSongs = new Song[numSongs];
	
	// Iterate through the songs array
	for (int i = 0; i < numSongs - 1; i++){
		tempSongs[i].setTitle(songs[i].getTitle());
		tempSongs[i].setArtist(songs[i].getArtist());
		tempSongs[i].setGenre(songs[i].getGenre());
		tempSongs[i].setRating(songs[i].getRating());
	}

	// setSongsArray also frees the old array
	setSongsArray(tempSongs);
	tempSongs[numSongs - 1] = newSong;
}

/*
Function: performRemoveSong()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/20/2023
 * Description: This function removes a song from the songs array based on the given index number
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performRemoveSong(int indexToRemove) {
	int oldNumSongs = numSongs;
	numSongs -= 1;

	if (numSongs > 0){
		Song * tempSongs = new Song[numSongs];

		// Iterate through both the old and new arrays and implement the copy
		for (int i = 0, j = 0; i <= numSongs, j < oldNumSongs; i++, j++){
			if (j < indexToRemove){
				tempSongs[i].setTitle(songs[j].getTitle());
				tempSongs[i].setArtist(songs[j].getArtist());
				tempSongs[i].setGenre(songs[j].getGenre());
				tempSongs[i].setRating(songs[j].getRating());
			}
			else if (j > indexToRemove){
				tempSongs[i - 1].setTitle(songs[j].getTitle());
				tempSongs[i - 1].setArtist(songs[j].getArtist());
				tempSongs[i - 1].setGenre(songs[j].getGenre());
				tempSongs[i - 1].setRating(songs[j].getRating());
			}
		}
		// setSongArray frees the old array memory
		setSongsArray(tempSongs);
	}
	else {
		// setSongArray frees the old array memory
		setSongsArray(nullptr);
		setNumSongs(0);
	}
}

/*
Function: performEditSong()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/21/2023
 * Description: This function edits an attribute of a song in the songs array base on the index number
 * Input parameters: An int, two strings
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
	newAttributeValue = convertToLowercase(newAttributeValue);

	if (attribute == "title"){
		songs[indexToEdit].setTitle(newAttributeValue);
	}
	else if (attribute == "artist"){
		songs[indexToEdit].setArtist(newAttributeValue);
	}
	else if (attribute == "genre"){
		songs[indexToEdit].setGenre(newAttributeValue);
	}
	else if (attribute == "rating"){
		songs[indexToEdit].setRating(stoi(newAttributeValue));
	}
}

/*
Copy Constructor
 * Date Created: 03/18/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the copy constructor
 * Input parameters: A pass-by-reference SongLibrary object
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
SongLibrary::SongLibrary(const SongLibrary & otherSongLibrary){
	numSongs = otherSongLibrary.numSongs;
	if (numSongs > 0){
		songs = new Song[numSongs];
		for (int i = 0; i < numSongs; i++){
			songs[i] = otherSongLibrary.songs[i];
		}
	}
	else {
		songs = nullptr;
	}
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
	int count = 0;

	// Read in from file
	for (int i = 0; i < numSongFromFile; i++){
		if (!inFile.bad()){
			getline(inFile, tempTitle);
			getline(inFile, tempArtist);
			getline(inFile, tempGenre);
			getline(inFile, tempRating);
			getline(inFile, tempLine);
		}

		// Check if there's a song that has already been in the library. If so, not adding it.
		count = 0;
		if (numSongs > 0){
			for (int j = 0; j < numSongs; j++){
				if (tempTitle != songs[j].getTitle()){
					count++;
				}

				if (count == numSongs){
					Song tempSong(tempTitle, tempArtist, tempGenre, stoi(tempRating));
					performAddSong(tempSong);
				}
			}
		}
		else if (numSongs == 0){
			Song tempSong(tempTitle, tempArtist, tempGenre, stoi(tempRating));
			performAddSong(tempSong);
		}
	}
}

/*
Function: addSongToLibrary()
 * Date Created: 03/17/2023
 * Date Last Modified: 03/18/2023
 * Description: This is a helper function to call performAddSong() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::addSongToLibrary(){
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

	performAddSong(tempSong);
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
Function: swap()
 * Date Created: 02/06/2022
 * Date Last Modified: 03/20/2022
 * Description: This function swaps two Song objects
 * Input parameters: Two pass-by-reference Song objects
 * Returns: None
 * Pre: None
 * Post: None
 * Note: Adapted from Gaddis and PA2
*/
void swap(Song &a, Song &b) {
  	Song temp = a;
  	a = b;
  	b = temp;
}

/*
Function: sortLibrary()
 * Date Created: 03/20/2023
 * Date Last Modified: 03/20/2023
 * Description: This is a helper function to call performSort() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::sortLibrary(){
	string attribute = "";

	cout << "Please enter the attribute that you want your library to be sorted by (title, artist, genre, or rating): ";
	cin >> attribute;

	performSort(attribute);
}

/*
Function: searchLibrary()
 * Date Created: 03/20/2023
 * Date Last Modified: 03/20/2023
 * Description: This is a helper function to call performSearch() from command line and prints it out if there is a match
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::searchLibrary(){
	string searchAttribute = "", searchAttributeValue = "";
	Song * foundSong = new Song;
	int index = 0;
	bool searchResult = false;

	cout << "Please enter the attribute that you want to search for (title, artist, genre, or rating): ";
	getline(cin, searchAttribute);
	cout << "Please enter the attribute value to be searched: ";
	getline(cin, searchAttributeValue);

	searchResult = performSearch(searchAttribute, searchAttributeValue, foundSong, &index);

	// Printing results
	if (searchResult == true) {
		cout << "A song with the " << searchAttribute << " of " << searchAttributeValue << " is found!" << endl;
		cout << "Song Information" << endl;
		cout << "----------------" << endl;
		foundSong->displaySong();
	}
	else {
		cout << "A song with the " << searchAttribute << " of " << searchAttributeValue << " is not found!" << endl;
	}

	// Freeing memory
	delete foundSong;
	foundSong = nullptr;
}

/*
Function: removeSongFromLibrary()
 * Date Created: 03/20/2023
 * Date Last Modified: 03/20/2023
 * Description: This is a helper function to call performRemoveSong() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::removeSongFromLibrary(){
	int indexToRemove = -1;

	cout << "Please enter the song index to be removed from the library: ";
	cin >> indexToRemove;

	performRemoveSong(indexToRemove);
}

/*
Function: editSongInLibrary()
 * Date Created: 03/21/2023
 * Date Last Modified: 03/21/2023
 * Description: This is a helper function to call performEditSong() from command line
 * Input parameters: Void
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a SongLibrary member function
*/
void SongLibrary::editSongInLibrary(){
	string attribute = "", newAttributeValue = "", indexToEdit = "";

	cout << "Please enter the song index that you want to edit: ";
	getline(cin, indexToEdit);
	cout << "Please enter the attribute that you want to edit (title, artist, genre, or rating): ";
	getline(cin, attribute);
	cout << "Please enter the new attribute value: ";
	getline(cin, newAttributeValue);

	performEditSong(stoi(indexToEdit), attribute, newAttributeValue);
}