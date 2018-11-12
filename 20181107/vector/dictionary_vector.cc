///
/// @file    dictionary_vector.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-07 23:34:37
///
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostringstream;

struct wordinfo
{
	wordinfo(string s)
		:word(s)
		 ,count(1)
	{}

	string word;
	int  count;
};

class dictionary
{
	public:
		void read(const string & filename);
		void store(const string & filename);

	private:

		void search(const string & word);
		std::vector <wordinfo> _dict;
};


void to_lower(string & word)
{
	for(auto & c: word)
	{
		if(c>='A' && c<='Z')
			c += 32;
	}
}


void dictionary:: search(const string & word)
{
	for(auto & elem: _dict)
	{
		if(elem.word==word)
		{
			++elem.count;
			return ;
		}
	}
	_dict.push_back(word);
}

string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

void dictionary ::read(const string & filename)
{
	ifstream in(filename);
	if(!in)
	{
		cout<<"ifstream create failed"<<endl;
		return ;
	}

	string line,word;
	size_t beg,end;

	while(getline(in,line))
	{
		beg =end =0;
		while(string::npos != beg)
		{
			beg=line.find_first_of(str,end);
			if(string::npos != beg)
			{
				end = line.find_first_not_of(str,beg);

				if(string::npos==end)
				{
					end =line.size();
				}

				word =string (line,beg,end-beg);
				to_lower(word);
				search(word);
			}
		}
	}
	in.close();
}

void dictionary ::store(const string & filename)
{
	ofstream out (filename);
	if(!out)
	{
		cout<<"ofstream cteate failed"<<endl;
	return ;
	}

	for(auto & elem :_dict)
{
	ostringstream ss;
	ss <<elem.word<<" "<<elem.count<<"\n";

	out<<ss.str();
}
out.close();
}

int main(void)
{
	clock_t start,finish;

	start =clock();
	dictionary dict;

	string inputfilename("The_Holy_Bible.txt"),outputfilename("dictionary.txt");

	dict.read(inputfilename);
	dict.store(outputfilename);

	finish =clock();
	cout<<static_cast<double>(finish - start)/CLOCKS_PER_SEC<<"(s)"<<endl;

	return 0;
}
