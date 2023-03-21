#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

void openFile(ifstream &, string);
int countSongFromFile(ifstream &);
void swap(Song &, Song &);

class SongLibrary {
	private:
		int numSongs;
		Song * songs;
		
		// TODO: add your additional private member functions here
	public:
		SongLibrary();
		~SongLibrary();
		int getNumSongs();
		void setNumSongs(int);
		Song * getSongsArray();
		void setSongsArray(Song *);

		void displayLibrary();
		void performLoad(string);
		void performSave(string);
		void performSort(string);
		bool performSearch(string, string, Song *, int *);
		void performAddSong(Song);
		void performRemoveSong(int);
		void performEditSong(int, string, string);

		// TODO: add your additional public member functions here
		SongLibrary(const SongLibrary & otherSongLibrary);
		void loadSongFromFile(ifstream &, int);
		void addSongToLibrary();
		void loadLibrary();
		void saveLibrary();
		void sortLibrary();
		void searchLibrary();
		void removeSongFromLibrary();
};

#endif
