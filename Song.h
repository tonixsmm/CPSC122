/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 4, 2023
Programming Assignment: PA6
Description: This program implements several tasks required by PA6
*/

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cctype>

using namespace std;

const int MIN_RATING = 1;
const int MAX_RATING = 5;

string convertToLowercase(string);
string beautyPrint(string);

class Song {
	private:
		string title;
		string artist;
		string genre;
		int rating;
		Song * next; // NEW: link for linking Songs together in a linked list
	public:
		Song();
		Song(string, string, string, int);
		Song(const Song&); // NEW: copy constructor
		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		int getRating();
		void setRating(int);
		
		Song * getNext(); // NEW: getter for next
		void setNext(Song *); // NEW: setter for next
		
		void displaySong();
		
		string getStringAttributeValue(string);
};

#endif
