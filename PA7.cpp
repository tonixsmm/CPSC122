#include "PA7.h"

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