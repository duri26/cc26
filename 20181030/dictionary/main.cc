 ///
 /// @file    main.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 23:25:34
 ///
 //


//可以用 O2 
#include "dictionary.h"

int main(void)
{

	Dictionary dict;

	string inputfilename("The_Holy_Bible.txt"),outputfilename("dictionary.txt");

	dict.read(inputfilename);
	dict.store(outputfilename);

	return 0;
}

