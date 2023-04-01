#include "Song.h"

/*
Function: convertToLowerCase()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This function converts a string to all lowercase
 * Input parameters: A string
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a global function
*/
string convertToLowercase(string s) {
	string tempString = "";
	for (char c : s){
		tempString += tolower(c);
	}
	return tempString;
}

Song::Song() {
	title = "";
	artist = "";
	genre = "";
	rating = 1;
	next = NULL;
}

Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = titleParam;
	artist = artistParam;
	genre = genreParam;
	rating = ratingParam;
	next = NULL;
}

Song::Song(const Song& other) {
	title = other.title;
	artist = other.artist;
	genre = other.genre;
	rating = other.rating;
	next = NULL;
}

string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

Song * Song::getNext() {
	return next;
}

void Song::setNext(Song * newNext) {
	next = newNext;
}

/*
Function: getStringAttributeValue()
 * Date Created: 03/16/2023
 * Date Last Modified: 03/17/2023
 * Description: This function returns the attribute value of a Song object's attribute
 * Input parameters: A string
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
string Song::getStringAttributeValue(string attribute) {
	if (convertToLowercase(attribute) == "title") {
		return getTitle();
	}
	else if (convertToLowercase(attribute) == "artist") {
		return getArtist();
	}
	else if (convertToLowercase(attribute) == "genre") {
		return getGenre();
	}
	else if (convertToLowercase(attribute) == "rating") {
		return to_string(getRating());
	}
	else {
		return "";
	}
}


void Song::displaySong() {
	cout << "Title:\t" << beautyPrint(title) << endl;
	cout << "Artist:\t" << beautyPrint(artist) << endl;
	cout << "Genre:\t" << beautyPrint(genre) << endl;
	cout << "Rating:\t" << rating << endl;
}

/*
Function: beautyPrint()
 * Date Created: 03/18/2023
 * Date Last Modified: 03/18/2023
 * Description: This function capitalizes the beginning character of a string for printing
 * Input parameters: A string
 * Returns: A string
 * Pre: None
 * Post: None
*/
string beautyPrint(string word){
	string tempString = word;
	
	tempString[0] = toupper(tempString[0]);
	for (int i = 0; i < static_cast<int>(tempString.length()); i++){
		if ((isspace(tempString[i]) || tempString[i] == 38 || tempString[i] == 40 || tempString[i] == 91 || tempString[i] == 123) && i <= static_cast<int>(tempString.length()) - 1){
			tempString[i + 1] = toupper(tempString[i + 1]);
		}
	}
	return tempString;
}