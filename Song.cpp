#include "Song.h"

// TODO: finish this function
string convertToLowercase(string s) {
	string tempString = "";
	for (char c : s){
		tempString += tolower(c);
	}
	return tempString;
}

// TODO: finish Song default value constructor
Song::Song() {
	title = "";
	artist = "";
	genre = "";
	rating = 1;
}

// TODO: finish Song explicit value constructor
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = convertToLowercase(titleParam);
	artist = convertToLowercase(artistParam);
	genre = convertToLowercase(genreParam);
	setRating(ratingParam);
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

// TODO: finish this function
void Song::displaySong() {
	cout << "Title:\t" << beautyPrint(title) << endl;
	cout << "Artist:\t" << beautyPrint(artist) << endl;
	cout << "Genre:\t" << beautyPrint(genre) << endl;
	cout << "Rating:\t" << rating << endl;
}

// TODO: finish this function
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