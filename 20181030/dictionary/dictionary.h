 ///
 /// @file    .h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 21:15:15
 ///
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::ostringstream;
using std::cout;
using std::endl;


struct Wordinfo
{
	Wordinfo(string s)
	:word(s)
	,count(1)
	{
	}

	string word;
	int count; 
};

class Dictionary
{
	public:
		void read(const string & filename);
		void store(const string & filename);
	private:
		
		void search(const string & word);
		std::vector<Wordinfo> _dict;
};


#endif
