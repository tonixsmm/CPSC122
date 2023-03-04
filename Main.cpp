/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: March 1, 2022
Programming Assignment: PA4
Description: This program implements several tasks required by PA4
Note: I attempted the bonus
*/

#include "PA4.h"

int main(int argc, char * argv[]) {
	checkInputFile(argc);
	runReadFromFile(argv[1]);
	
	cout << "Bonus Part" << endl;
	cout << "----------" << endl;

	runBonus();
	return 0;
}
