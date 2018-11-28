
#include "dictionary.h"

#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

int main(void)
{

	clock_t start, finish;
	start = clock();
	Dictionary dict;

	string inputfilename("english.txt"),outputfilename("dictionary.txt");

	dict.read(inputfilename);
	dict.store(outputfilename);

	finish = clock();
	cout << static_cast<double>(finish - start)/CLOCKS_PER_SEC << "(s)" <<endl;

	return 0;
}
