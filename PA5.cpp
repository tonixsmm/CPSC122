/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 21, 2022
Programming Assignment: PA5
Description: This program implements several tasks required by PA5
Note: I attempted the bonus
*/

#include "PA5.h"

/*
Function: displayMenu()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/15/2023
 * Description: This function prints out command options
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Display library" << endl;
	cout << "2) Load library" << endl;
	cout << "3) Store library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Add song to library" << endl;
	cout << "7) Remove song from library" << endl;
	cout << "8) Edit song in library" << endl;
	cout << "9) Quit" << endl;
}

/*
Function: getValidChoice()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/15/2023
 * Description: This function validates user's input
 * Input parameters: None
 * Returns: An int
 * Pre: None
 * Post: None
*/
int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

/*
Function: executeUserChoice()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/15/2023
 * Description: This is a driver function that calls out necessary functions to perform tasks
 * Input parameters: An int and a pass-by-reference SongLibrary object
 * Returns: None
 * Pre: None
 * Post: None
*/
void executeUserChoice(int choice, SongLibrary& lib) {
	switch (choice) {
		case 1:
			lib.displayLibrary();
			break;
		case 2:
			lib.loadLibrary();
			break;
		case 3: 
			lib.saveLibrary();
			break;
		case 4:
			lib.sortLibrary();
			break;
		case 5:
			lib.searchLibrary();
			break;
		case 6:
			lib.addSongToLibrary();
		 	break;
		case 7:
			lib.removeSongFromLibrary();
			break;
		case 8:
			lib.editSongInLibrary();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

/*
Function: runMusicManager()
 * Date Created: 03/15/2023
 * Date Last Modified: 03/15/2023
 * Description: This is a driver function that calls out necessary functions to perform tasks
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}