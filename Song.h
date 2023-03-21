/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 21, 2022
Programming Assignment: PA5
Description: This program implements several tasks required by PA5
Note: I attempted the bonus
*/

#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cctype>

using namespace std;

const int MIN_RATING = 1;
const int MAX_RATING = 5;

// Global function prototypes
string convertToLowercase(string);
string beautyPrint(string);

// Class prototypes
class Song {
	private:
		string title;
		string artist;
		string genre;
		int rating;
		
	public:
		Song();
		Song(string, string, string, int);
		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		int getRating();
		void setRating(int);

		void displaySong();
		string getStringAttributeValue(string);

		const Song & operator=(const Song&);
};

#endif
