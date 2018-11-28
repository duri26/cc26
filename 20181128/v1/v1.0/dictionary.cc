 ///
 /// @file    dictionary.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-28 16:34:05
 ///

#include "dictionary.h"

#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::ostringstream;

namespace wd
{

void  Dictionary::to_lower(string & word)
{
	for(auto c: word)
	{
		if(!isalpha(c))
		{
			c = ' ';
		}
		else 
		{
			tolower(c);
		}
	}
}

void Dictionary::insert(const string & word)
{
	auto iter =_dict.find(word);
	if(iter == _dict.end())
	{
		_dict.insert(make_pair(word,1));
	}
	else 
	{
		++iter->second;
	}
}

size_t Dictionary::find_first_alp(const string s,size_t pos)
{
	string ::const_iterator iter=s.begin() +pos;

	while(iter != s.end())
	{
		if(isalpha(*iter))
		{
			return iter-s.begin();
		}
		iter++;
	}
	return -1;
}


size_t Dictionary::find_first_not_alp(const string s,size_t pos)
{
	string ::const_iterator iter=s.begin() +pos;

	while(iter != s.end())
	{
		if(!isalpha(*iter))
		{
			return iter-s.begin();
		}
		iter++;
	}
	return -1;
}

void Dictionary::read(const string & filename)
{
	ifstream in(filename);
	if(!in)
	{
		cout<<" ifstream create failed "<<endl;
		exit(-1);
	}

	string line,word;
	size_t beg,end;

	while(getline(in,line))
	{
		beg = end = 0;
		while(string ::npos != beg)
		{
			beg = find_first_alp(line,end);
			if(string ::npos != beg)
		{
			end =find_first_not_alp(line,beg);
			if(string ::npos == end)
			{
				end =line.size();
			}

			word = string(line,beg,end - beg);
			Dictionary::to_lower(word);
			insert(word);
		}
		}	
	}
in.close();
}

void Dictionary::store(const string & filename)
{
	ofstream out(filename);
	if(!out)
	{
		cout<<" ofstream create failed "<<endl;
		exit(-1);
	}

	for(auto & elem : _dict)
	{
		ostringstream ss;
		ss <<elem.first<<"  "<<elem.second<<"\n";

		out<<ss.str();
	}
	out.close();
}

}
