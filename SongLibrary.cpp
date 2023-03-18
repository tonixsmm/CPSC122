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
	cout << "All Songs in the Library" << endl;
	cout << "------------------------" << endl;

	for (int i = 0; i < numSongs; i++){
		songs[i].displaySong();
	}
}

// TODO: finish this function
void SongLibrary::performLoad(string filename) {
	
}

// TODO: finish this function
void SongLibrary::performSave(string filename) {
	
}

// TODO: finish this function
void SongLibrary::performSort(string attribute) {
	
}

// TODO: finish this function
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
	
	return false;
}

// TODO: finish this function
void SongLibrary::performAddSong(Song newSong) {
	numSongs += 1;
	Song * tempSongs = new Song[numSongs];
	for (int i = 0; i < numSongs - 1; i++){
		tempSongs[i] = songs[i];
	}
	
	tempSongs[numSongs - 1] = newSong;
	setSongsArray(tempSongs);
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