#include "SongLibrary.h"

SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}

// TODO: finish SongLibrary destructor
SongLibrary::~SongLibrary() {
	if (songs != nullptr){
		delete [] songs;
		songs = nullptr;
		numSongs = 0;
	}
}

int SongLibrary::getNumSongs() {
	return numSongs;
}

void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

Song * SongLibrary::getSongsArray() {
	return songs;
}

void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

// TODO: finish this function
void SongLibrary::displayLibrary() {
	cout << "All Songs In The Library" << endl;
	cout << "------------------------" << endl;
	cout << endl;

	for (int i = 0; i < numSongs; i++){
		cout << "SONG " << i + 1 << endl;
 		songs[i].displaySong();
		cout << endl;
	}
}

// TODO: finish this function
void SongLibrary::performLoad(string filename) {
	ifstream inFile;
	int numSongFromFile = 0;

	openFile(inFile, filename);

	numSongFromFile = countSongFromFile(inFile);
	inFile.clear();
	inFile.seekg(0);

	loadSongFromFile(inFile, numSongFromFile);

	inFile.close();
}

// TODO: finish this function
void SongLibrary::performSave(string filename) {
	fstream outFile;
	outFile.open(filename, ios::out);

	for (int i = 0; i < numSongs; i++){
		outFile << songs[i].getTitle() << endl;
		outFile << songs[i].getArtist() << endl;
		outFile << songs[i].getGenre() << endl;
		outFile << songs[i].getRating() << endl;
		outFile << endl;
	}

	outFile.close();
}

// TODO: finish this function
void SongLibrary::performSort(string attribute) {
	
}

// TODO: finish this function
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	
	return false;
}

// TODO: finish this function
// CHECK FOR A MORE EFFICIENT WAY
void SongLibrary::performAddSong(Song newSong) {
	numSongs += 1;

	Song * tempSongs = new Song[numSongs];
		
	for (int i = 0; i < numSongs - 1; i++){
		tempSongs[i].setTitle(songs[i].getTitle());
		tempSongs[i].setArtist(songs[i].getArtist());
		tempSongs[i].setGenre(songs[i].getGenre());
		tempSongs[i].setRating(songs[i].getRating());
	}

	setSongsArray(tempSongs);
	tempSongs[numSongs - 1] = newSong;

	// delete [] tempSongs;	// Double check if there is a leak here

}

// TODO: finish this function
void SongLibrary::performRemoveSong(int indexToRemove) {
	
}

// TODO: finish this function
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
	
}

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
open
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

int countSongFromFile(ifstream & inFile){
	int count = 0, numSongFromFile = 0;
	string line = "";

	while (!inFile.eof()){
		getline(inFile, line);
		if (!inFile.bad()){
			count++;
		}
	}
	numSongFromFile = count / 5;

	return numSongFromFile;
}

void SongLibrary::loadSongFromFile(ifstream & inFile, int numSongFromFile){
	string tempTitle = "", tempArtist = "", tempGenre = "", tempLine = "", tempRating = "";
	int count = 0;

	for (int i = 0; i < numSongFromFile; i++){
		if (!inFile.bad()){
			getline(inFile, tempTitle);
			getline(inFile, tempArtist);
			getline(inFile, tempGenre);
			getline(inFile, tempRating);
			getline(inFile, tempLine);
		}

		count = 0;
		// Check if there's a song that has already been in the library. If so, not loading it.
		if (numSongs > 0){
			for (int j = 0; j < numSongs; j++){
				if (tempTitle != songs[j].getTitle()){
					count++;
				}

				if (count == numSongs){
					Song tempSong(tempTitle, tempArtist, tempGenre, stoi(tempRating));
					performAddSong(tempSong);
					// count = 0;
				}
			}
		}
		else if (numSongs == 0){
			Song tempSong(tempTitle, tempArtist, tempGenre, stoi(tempRating));
			performAddSong(tempSong);
			// count = 0;
		}
	}
}

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

void SongLibrary::loadLibrary(){
	string fileName = "";

	cout << "Please enter filename to be opened: " << endl;
	cin >> fileName;
	// fileName = "../library.txt";

	performLoad(fileName);
}

void SongLibrary::saveLibrary(){
	string fileName = "";

	cout << "Enter the filename that you want to save your library to: " << endl;
	cin >> fileName;
	// fileName = "../SaveTest.txt";

	performSave(fileName);;
}