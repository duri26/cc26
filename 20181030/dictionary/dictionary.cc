///
/// @file    dictionary.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-10-30 21:44:59
///

#include "dictionary.h"

void to_lower(string & word)
{
	for (auto &c : word) 
	{
		if (c >= 'A' && c <= 'Z')
		{
			c +=32;
		}
	}
}

void Dictionary::search(const string & word)
{
	for (auto & elem : _dict)
	{
		if (elem.word == word)
		{
			++elem.count;
			return;
		}
	}

	_dict.push_back(Wordinfo(word));
}

string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

void Dictionary::read(const string & filename)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "ifstream create failed" << endl;
		return;
	}

	string line, word;
	size_t beg, end;

	while (getline(in, line))
	{

		beg = end = 0;
		while(string::npos != beg)
		{

			beg = line.find_first_of(str, end);
			if (string::npos != beg)
			{
				end = line.find_first_not_of(str, beg);

				if (string::npos == end)
				{
					end = line.size();
				}

				word = string(line, beg, end - beg);	
				to_lower(word);
				search(word);
			}
		}
	}

	in.close();
}


void Dictionary::store(const string & filename)
{
	ofstream out(filename);
	if (!out){
		cout << "ofstream create failed" << endl;
		return;
	}

	for (auto & elem : _dict)
	{

		ostringstream ss;
		ss << elem.word << " " << elem.count << "\n";

		out << ss.str();
	}

	out.close();
}

