 ///
 /// @file    dictionary.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-28 16:34:05
 ///

#include "index.h"

#include <ctype.h>

namespace wd
{




void Index::read(const string & filename)
{
	ifstream in(filename);
	if(!in)
		{
			cout<<" ifstream create failed "<<endl;
		exit(-1);
		}

	string line,word;
	int size;
	while(getline(in,line))
	{
		istringstream iss(line);

		while(iss>>word,iss>>size)
		{
			_word.push_back(pair<string,int>(word,size));
		}
	}

	
in.close();
}

void Index::store(const string & filename)
{
	ofstream out(filename);
	if(!out)
	{
		cout<<" ofstream create failed "<<endl;
		exit(-1);
	}

	for(auto it= _word.begin();it !=_word.end();++it)
	{
		ostringstream ss;
		ss <<it->first<<"  "<<it->second<<"\n";

		out<<ss.str();
	}
	out.close();
}

}
