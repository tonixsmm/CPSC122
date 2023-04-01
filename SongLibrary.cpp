#include "SongLibrary.h"


SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

SongLibrary::SongLibrary(const SongLibrary& other) {
	head = NULL;
	sortAttribute = other.sortAttribute;

	Song * curr = other.head; 
	while (curr != NULL){
		Song * newSong = new Song(*curr);
		performInsertSongInOrder(newSong);
		curr = curr->getNext();
	}
}


SongLibrary::~SongLibrary() {
	destroyList();
}

Song * SongLibrary::getHead() const {
	return head;
}

void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		destroyList();
	}
	head = newHead;
}

string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

// TODO: finish this function
void SongLibrary::performLoad(string filename) {
	
}

// TODO: finish this function
void SongLibrary::performSave(string filename) {
	
}

// TODO: finish this function
void SongLibrary::performSort() {

}

// TODO: finish this function
Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	
	return NULL; // TODO: fix this
}

// TODO: finish this function
void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	if (head == NULL){
		head = songToInsert;
	}
	else {
		Song * currSong = head;
		Song * prevSong = NULL;

		while (currSong != NULL && currSong->getStringAttributeValue(sortAttribute) < songToInsert->getStringAttributeValue(sortAttribute)){
			prevSong = currSong;
			currSong = currSong->getNext();
		}

		if (prevSong == NULL){
			head = songToInsert;
			songToInsert->setNext(currSong);
		}
		else{
			songToInsert->setNext(currSong);
			prevSong->setNext(songToInsert);
		}
	}
}


// TODO: finish this function
void SongLibrary::performRemoveSong(Song * songToRemove) {
	
}

// TODO: finish this function
void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
	
}


void SongLibrary::destroyList(){
	Song * currNode = NULL;
    Song * nextNode = NULL;

    while (currNode != NULL){
        nextNode = currNode->getNext();
        delete currNode;
        currNode = nextNode;
    }
    head = NULL;
}

void SongLibrary::displayLibrary(){
	int count = 0;

	cout << endl << "All Songs In The Library" << endl;
	cout << "------------------------" << endl;
	cout << endl;

	Song * curr = head;
	while (curr != NULL){
		cout << "SONG " << count << endl;
		curr->displaySong();
		cout << endl;

		curr = curr->getNext();
		count++;
	}
}

void SongLibrary::addToEnd(Song * newSong){
	if (head == NULL){
        head = newSong;
	    }
    else {
        Song * currNode = head;
        while (currNode->getNext() != NULL){
            currNode = currNode->getNext();
        }
        currNode->setNext(newSong);
    }
}

void SongLibrary::addToFront(Song * newSong){
    if (head == NULL){
        head = newSong;
    }
    else {
        newSong->setNext(head);
        head = newSong;
    }
}

void SongLibrary::reverseList(){
	Song * curr = head;
	Song * prev = NULL;
	Song * nextNode = NULL;

	while (curr != NULL){
		nextNode = curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = nextNode;
	}
	head = prev;
}