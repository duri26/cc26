 ///
 /// @file    dictionary.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-28 16:34:05
 ///

#include "dictionary1.1.h"

#include <ctype.h>


namespace wd
{

void  Dictionary::strProcess(string & word)
{
	for(auto &c: word)
	{
		if(!isalpha(c))
		{
			c = ' ';
		}
		else 
		{
			c=tolower(c);
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


void Dictionary::read(const string & filename)
{
	ifstream in(filename);
	if(!in)
		{
			cout<<" ifstream create failed "<<endl;
		exit(-1);
		}

	string line,word;
	while(getline(in,line))
	{
		strProcess(line);
		istringstream iss(line);

		while(iss>>word)
		{
			insert(word);
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
