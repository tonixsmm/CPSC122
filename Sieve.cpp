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

// TODO: finish this function
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

void Sieve::createNumQueue(){
	for (int i = 2; i <= n; i++){
		numsQ->enqueue(i);
	}
}

void Sieve::transferQueue(){
	int temp = -1;
	Node * curr = numsQ->getHead();
	while (curr != NULL){
		temp = curr->value;
		primesQ->enqueue(temp);
		curr = curr->next;
	}
}