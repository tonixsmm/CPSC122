/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 4, 2023
Programming Assignment: PA6
Description: This program implements several tasks required by PA6
*/


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

/*
Song()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the default value constructor of Song class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
Song::Song() {
	title = "";
	artist = "";
	genre = "";
	rating = 1;
	next = NULL;
}

/*
Song()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the explicit value constructor of Song class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = titleParam;
	artist = artistParam;
	genre = genreParam;
	rating = ratingParam;
	next = NULL;
}

/*
Song()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the copy constructor of Song class
 * Input parameters: A Song object passed by reference
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
Song::Song(const Song& other) {
	title = other.title;
	artist = other.artist;
	genre = other.genre;
	rating = other.rating;
	next = NULL;
}

/*
Function: getTitle()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the title getter of the Song class
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
string Song::getTitle() {
	return title;
}

/*
Function: setTitle()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the title setter of the Song class
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

/*
Function: getArtist()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the artist getter of the Song class
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
string Song::getArtist() {
	return artist;
}

/*
Function: setArtist()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the artist setter of the Song class
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

/*
Function: getGenre()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the genre getter of the Song class
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
string Song::getGenre() {
	return genre;
}

/*
Function: setGenre()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the genre setter of the Song class
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

/*
Function: getRating()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the rating getter of the Song class
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
int Song::getRating() {
	return rating;
}

/*
Function: setRating()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the rating setter of the Song class
 * Input parameters: A string
 * Returns: None
 * Pre: Rating will be set according to the global variable declared above
 * Post: None
 * Note: This is a Song class member function
*/
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

/*
Function: getNext()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the next pointer getter of the Song class
 * Input parameters: None
 * Returns: A Song pointer
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
Song * Song::getNext() {
	return next;
}

/*
Function: setNext()
 * Date Created: 04/01/2023
 * Date Last Modified: 04/01/2023
 * Description: This is the next pointer setter of the Song class
 * Input parameters: A Song object pointer
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song class member function
*/
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

/*
Function: displaySong()
 * Date Created: 03/17/2023
 * Date Last Modified: 03/18/2023
 * Description: This function displays a Song object attributes
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
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