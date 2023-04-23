/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 23, 2023
Programming Assignment: PA8
Description: This program implements several tasks required by PA8
*/

#include "PA8.h"

// no need for changes here
void runPrimesPrompt() {
	Sieve sieve; // reuse same Sieve object
	int n = -1;
	cout << "This program computes all prime numbers up to a maximum using the Sieve of Eratosthenes." << endl;
	do {
		cout << endl << "Please enter n, where n is max value to show primes up to and including (-1 to quit): ";
		cin >> n;
		if (n != -1) {
			sieve.setN(n);
			sieve.run();
		}
	} while (n != -1);
}
