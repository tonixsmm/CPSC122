/*
Name: Tony Nguyen
Class: CPSC 122 01
Date: April 23, 2023
Programming Assignment: PA8
Description: This program implements several tasks required by PA8
*/

#include "Sieve.h"

Sieve::Sieve() {
	n = 0;
	numsQ = new DoublyLinkedQueue();
	primesQ = new DoublyLinkedQueue();
}

Sieve::~Sieve() {
	if (numsQ != NULL) {
		delete numsQ;
	}
	if (primesQ != NULL) {
		delete primesQ;
	}
}

int Sieve::getN() const {
	return n;
}

void Sieve::setN(int nParam) {
	n = nParam;
}

/*
Function: computePrimes()
 * Date Created: 04/23/2023
 * Date Last Modified: 04/23/2023
 * Description: This function inserts value to a queue (numsQ) with the provided max number, then performs
  				the Sieve of Eratosthenes prime number checking algorithm, and insert the prime values to a new queue.				
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
void Sieve::computePrimes() {
	int p = -1;
	createNumQueue();
	
	do{
		p = numsQ->dequeue();
		primesQ->enqueue(p);
		numsQ->removeDivisibleBy(p);
	} while(p < sqrt(n));
	transferQueue();

	numsQ->clear();
}

/*
Function: reportResults()
 * Date Created: 04/22/2023
 * Date Last Modified: 04/23/2023
 * Description: This function prints out primesQ (the queue of prime numbers) and its prime counting statistics, 
				and returns the size of primesQ
 * Input parameters: A passed-by-reference double
 * Returns: An int
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function. I added  primesQ->clear() to clear the old
   		 queue for the next run, as compared to the original implementation
*/
int Sieve::reportResults(double& primePercent) {
	int numPrimes = 0;
	
	cout << "Primes up to " << n << " are as follows: " << endl;
	primesQ->displayQueue();
	
	numPrimes = primesQ->size();
	primePercent = static_cast<double>(numPrimes) / n * 100;
	primesQ->clear();

	return numPrimes;
}

void Sieve::run() {
	int numPrimes = 0;
	double primePercent = 0.0;
	
	computePrimes();
	numPrimes = reportResults(primePercent);
	cout << numPrimes << " / " << n << " = " << primePercent << "% primes" << endl;
}

/*
Function: createNumQueue()
 * Date Created: 04/23/2023
 * Date Last Modified: 04/23/2023
 * Description: This function inserts values from 2 to n (max number value) to the numsQ queue
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
void Sieve::createNumQueue(){
	for (int i = 2; i <= n; i++){
		numsQ->enqueue(i);
	}
}

/*
Function: transferQueue()
 * Date Created: 04/23/2023
 * Date Last Modified: 04/23/2023
 * Description: This function transfers the values of numsQ to primesQ
 * Input parameters: None
 * Returns: None
 * Pre: None
 * Post: None
 * Note: This is a DoublyLinkedQueue class member function
*/
void Sieve::transferQueue(){
	int temp = -1;

	Node * curr = numsQ->getHead();
	while (curr != NULL){
		temp = curr->value;
		primesQ->enqueue(temp);
		curr = curr->next;
	}
}