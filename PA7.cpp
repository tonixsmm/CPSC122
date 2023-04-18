/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 17, 2023
Programming Assignment: PA7
Description: This program implements several tasks required by PA7
*/

#include "PA7.h"

/*
Function: runPA7()
 * Date Created: 04/17/2023
 * Date Last Modified: 04/17/2023
 * Description: This is the driver function to perform PA7
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
*/
void runPA7(){
    ifstream inFile;
    Calculator cal;

    openFile(inFile, "../input.txt");

	cal.processStringValue(inFile);

	cout << "INFIX - POSTFIX Conversion" << endl;
	cout << "--------------------------" << endl;
	cal.processINFIX(inFile);

	inFile.close();
}