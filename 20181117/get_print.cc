 ///
 /// @file    get_print.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-20 11:17:00
 ///

#include "query.h"
#include "textquery.h"

#include <stdexcept>

using std::runtime_error;

TextQuery get_file(int argc,char **argv)
{
	ifstream infile;
	if(2 != argc)
	{
		cout<<"please input one  file name";
		exit(-1);
	}
	if(2 == argc)
		infile.open(argv[1]);
	if(!infile)
	{
		throw runtime_error("No input file");
	}

	return TextQuery(infile);
}

bool get_word(string &s1)
{
	cout<<"enter a word to search for,or q to quit: ";
	cin>>s1;
	if(!cin||"q" == s1)
		return false;
	else 
		return true;
}

bool get_words(string &s1,string &s2)
{
	cout<<"enter two words to search for ,or q to quit : ";
	cin >> s1;
	if(!cin|| "q" == s1)
		return false;
	cin >> s2;
	return true;
}
