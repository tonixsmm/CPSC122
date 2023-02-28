#include "PA4.h"

// TODO: add parameters to main() for command line args
int main(int argc, char * argv[]) {
	checkInputFile(argc);
	runReadFromFile(argv[1]);
	runBonus();
	return 0;
}
