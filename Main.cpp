/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: February 21, 2022
Programming Assignment: PA3
Description: This program implements several tasks required by PA3
Note: I attempted the bonus
*/

#include "PA3.h"

int main() {
	srand(time(0)); // this should be the ONLY call to srand() in PA3
	
	// Task 1
	cout << "TASK 1" << endl;
	runTask1();
	cout << "****************" << endl;
	
	// Task 2
	cout << endl;
	cout << "TASK 2" << endl;
	runTask2();
	cout << "****************" << endl;
	
	// Task 3
	cout << endl;
	cout << "TASK 3" << endl;
	runTask3();

	return 0;
}
