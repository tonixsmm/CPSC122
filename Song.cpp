/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 21, 2022
Programming Assignment: PA5
Description: This program implements several tasks required by PA5
Note: I attempted the bonus
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
Function: Song()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the default value constructor of the Song class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
Song::Song() {
	title = "";
	artist = "";
	genre = "";
	rating = 1;
}

/*
Function: Song()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the explicit value constructor of the Song class
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = convertToLowercase(titleParam);
	artist = convertToLowercase(artistParam);
	genre = convertToLowercase(genreParam);
	setRating(ratingParam);
}

/*
Function: getTitle()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "title" getter of the Song class
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
string Song::getTitle() {
	return title;
}

/*
Function: setTitle()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "title" setter of the Song class
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

/*
Function: getArtist()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "artist" getter of the Song class
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
string Song::getArtist() {
	return artist;
}

/*
Function: setArtist()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "title" setter of the Song class
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

/*
Function: getGenre()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "genre" getter of the Song class
 * Input parameters: None
 * Returns: A string
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
string Song::getGenre() {
	return genre;
}

/*
Function: setGenre()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "title" setter of the Song class
 * Input parameters: A string
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

/*
Function: getTitle()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "rating" getter of the Song class
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
int Song::getRating() {
	return rating;
}

/*
Function: setRating()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/17/2023
 * Description: This is the "rating" setter of the Song class
 * Input parameters: An int
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a Song member function
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
Operator Overloaing
 * Date Created: 03/18/2023
 * Date Last Modified: 03/18/2023
 * Description: This is the operator overloading
 * Input parameters: A pass-by-reference Song object
 * Returns: A Song object
 * Pre: None
 * Post: None
 * Note: This is a Song member function
*/
const Song & Song::operator=(const Song& right){
	if (this != &right){
		title = right.title;
		artist = right.artist;
		genre = right.genre;
		rating = right.rating;
		return *this;
	}
	else {
		return right;
	}
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
		if ((isspace(tempString[i]) || tempString[i] == 40 || tempString[i] == 91 || tempString[i] == 123) && i <= static_cast<int>(tempString.length()) - 1){
			tempString[i + 1] = toupper(tempString[i + 1]);
		}
	}
	return tempString;
}