#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		Song * head;
		string sortAttribute; // NEW: keep track of what attribute the library is currently ordered by
	public:
		SongLibrary();
		SongLibrary(const SongLibrary&); // NEW: copy constructor
		~SongLibrary();
		Song * getHead() const; // UPDATED: name
		void setHead(Song *); // UPDATED: name
		string getSortAttribute() const; // NEW: getter for sortAttribute
		void setSortAttribute(string); // NEW: setter for sortAttribute
		
		void displayLibrary();
		void performLoad(string);
		void performSave(string);
		void performSort(); // UPDATED: no parameter for sort attribute, using Song's sortAttribute member variable
		Song * performSearch(string, string, bool *, int *); // UPDATED: parameter list and return type
		void performInsertSongInOrder(Song *); // NEW: replaces addSong()
		void performRemoveSong(Song *); // UPDATED: parameter list
		void performEditSong(Song *, string, string); // UPDATED: parameter list

		void destroyList();
		void addToEnd(Song *);
		void addToFront(Song *);
		void reverseList();
		void loadSongFromFile(ifstream&, int);
		string getValueFromIndex(int, string);
		
		void loadLibrary();
		void saveLibrary();
		void sortLibrary();
		void searchLibrary();
		void insertSongInLibraryOrder();
		void removeSongFromLibrary();
		void editSongInLibrary();
};

void openFile(ifstream&, string);
int countSongFromFile(ifstream&);

#endif
