#ifndef PA4_H
#define PA4_H

#include <iostream>
#include <fstream>

using namespace std;

struct Package {
	int id;
	double weight;
	int width;
	int length;
	int height;
};

Package * loadPackages(ifstream&, string *, int *);
void computePackageStats(const Package[], const int, int * heaviestId, double *, double *);
// TODO: add your additional function prototypes here


#endif
