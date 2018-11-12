 ///
 /// @file    textquery.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-09 21:23:34
 ///
#include <ctype.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::ifstream;

class TextQuery
{
	public:
	void readFile(const string & filename);
	void query(const string & word);

	private:
	void insert(const string & word,int line);

	vector <string> _lines;
	map<string, set<int>> _wordLines;
};



string & to_lower(string & word)
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

void TextQuery::insert(const string & word,int line)
{
	auto iter = _wordLines.find(word);
	if(iter == _wordLines.end())
	{
		_wordLines.insert(make_pair(word,set<int>{line}));
	}
	else
	{
		iter->second.insert(line);
	}
}

size_t find_first_alp(const string s, size_t pos)
{
	string ::const_iterator iter = s.begin() + pos;

	while(iter != s.end())
	{
		if(isalpha(*iter))
		{
			return iter - s.begin();
		}
		iter++;
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
return -1;
}

void TextQuery::readFile(const string & filename)
{
	ifstream in(filename);
	if(!in)
	{
		cout<< "ifstream create failed "<<endl;
		return ;
	}

	string line,word;
	size_t beg,end,lineNum = 0;

	while(getline(in,line))
	{
		++lineNum;
		_lines.push_back(line);

		beg=end=0;
		while(string::npos != beg)
		{
			beg =find_first_alp(line,end);
			if(string ::npos != beg)
			{
				end = find_first_not_alp(line,beg);
				if(string ::npos ==end)
				{
					end = line.size();
				}

				word =string(line, beg, end -beg);
				insert(to_lower(word),lineNum);
				}
		}
	}
	in.close();
}

void TextQuery::query(const string & word)
{
	string lowerWord =word;
	to_lower(lowerWord);

	auto cit = _wordLines.find(lowerWord);
	if(cit == _wordLines.cend())
	{
		cout<<word<<"occurs 0 times"<<endl;
		return ;
	}
	else
	{
		cout<<word<<"occurs"<<cit->second.size()<<"times"<<endl;
		auto cit2 = cit->second.cbegin();
		while(cit2 != cit->second.cend())
		{
			cout<<"(line "<<*cit2<<") "<<_lines[*cit2 -1]<<endl;
			++cit2;
		}
	}
}


int main(void)
{
	string queryWord("china");
	TextQuery tq;
	tq.readFile("china_daily.txt");
	tq.query(queryWord);

	return  0;
}
