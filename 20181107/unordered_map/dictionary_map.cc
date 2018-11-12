///
/// @file    dictionary_map.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-09 20:05:16

#include <time.h>
#include <ctype.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::ifstream;
using std::ofstream;
using std::ostringstream;

class dictionary
{
	public:
		void read(const string & filename);
		void store(const string & filename);

	private:
		void insert(const string & word);
		std::unordered_map<string ,size_t>  _dict;
};

string & to_lower( string & word)
{
	for(auto & c: word)
	{
		if(c >= 'A' && c <= 'Z')
		{
			c += 32;
		}
	}
	return word;
}

void dictionary :: insert(const string & word)
{
	auto iter = _dict.find(word);
	if(iter == _dict.end())
	{
		_dict.insert(make_pair(word,1));
	}
	else
	{
		++iter->second;
	}
}

size_t find_first_alp(const string s,size_t pos)
{
	string ::const_iterator iter =s.begin() +pos;

	while(iter != s.end())
	{
		if(isalpha(*iter))
		{
			return iter - s.begin();
		}
		iter ++;
	}
	return -1;
}

size_t find_first_not_alp(const string s, size_t pos)
{
	string ::const_iterator iter = s.begin() + pos;

	while(iter != s.end())
	{
		if(!isalpha(*iter))
		{
			return iter - s.begin();
		}
		iter++;
	}
	return -2;
}

void dictionary::read(const string & filename)
{
	ifstream in(filename);
	if(!in)
	{
		cout<<"ifstream create failed"<<endl;
		return ;
	}

	string line,word;
	size_t beg,end;

	while(getline(in, line))
	{
		beg = end = 0;
		while(string :: npos != beg)
		{
			beg = find_first_alp(line,end);
			if(string ::npos !=beg)
			{
				end = find_first_not_alp(line,beg);
				if(string ::npos == end)
				{
					end = line.size();
				}

				word =string (line,beg,end - beg);
				insert(to_lower(word));
			}
		}
	}
	in.close();
}


void dictionary::store(const string & filename)
{
	ofstream out(filename);
	if(!out)
	{
		cout<<"ofstream create failed"<<endl;
		return ;
	}

	for (auto & elem : _dict)
	{
		ostringstream ss;
		ss<<elem.first<<"  "<<elem.second<<"\n";

		out<<ss.str();
	}
	out.close();
}

int main(void)
{
	time_t begin,end;
	begin=time(NULL);



	clock_t start, finish;
	start = clock();
	dictionary dict;

	string inputfilename("The_Holy_Bible.txt"),outputfilename("dictionary.txt");

	dict.read(inputfilename);
	dict.store(outputfilename);
	end =time(NULL);
	cout << static_cast<double>(end/1.0- begin/1.0) << "(s)" <<endl;
	finish = clock();
	cout << static_cast<double>(finish - start)/CLOCKS_PER_SEC << "(s)" <<endl;
	return 0;
}

