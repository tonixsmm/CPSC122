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
