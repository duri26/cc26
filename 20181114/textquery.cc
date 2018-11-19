///
// @file    textquery.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-15 23:45:00
///

#include <string.h>

#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::set;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::pair;
using std::cin;
using std::shared_ptr;


class QueryResult;

class TextQuery
{
	public:
		TextQuery(ifstream & );
		QueryResult query(const string &)const;

	private:
		void strProcess(string &);

		shared_ptr<vector<string>> content;
		map<string ,shared_ptr<pair<int,set<int>>>> wm;
};

void TextQuery::strProcess(string & str)
{
	for(auto c: str)
	{
		if(!isalpha(c))
		{
			c=' ';
		}
		else
		{
			tolower(c);
		}
	}
}

TextQuery::TextQuery(ifstream & is)
	:content(new vector<string>)
{
	string line,word;
	int count = 0;

	while(getline(is,line))
	{
		content->push_back(line);

		strProcess(line);
		istringstream iss(line);

		while(iss >> word)
		{
			auto & tmp =wm[word];
			if(!tmp)
			{
				tmp.reset(new pair<int ,set<int>>());

			}
			++tmp->first;
			tmp->second.insert(count);
		}
		++count;
	}
}


class QueryResult
{
	public:
		QueryResult(string s, shared_ptr<vector<string>> p,shared_ptr<pair<int, set<int>>> l)
			:sought(s)
			 ,content(p)
			 ,lines(l)
	{
	}

		friend std::ostream & operator<<(std::ostream & ,const QueryResult &);

	private:
		string sought;
		shared_ptr<vector<string>> content;
		shared_ptr<pair<int ,set<int>>> lines;

};

QueryResult TextQuery::query(const string & word) const
{
	static shared_ptr<pair<int ,set<int>>> nodata(new pair<int,set<int>>());

	auto it = wm.find(word);
	//if(it != wm.end()) 写错
	if(it == wm.end())
	{
		return QueryResult(word,content,nodata);
	}
	else
	{
		return QueryResult(word, content,it->second);
	}
}

std::ostream & operator<<(std::ostream & os, const QueryResult & qr)
{
	int times = qr.lines->first;
	os << qr.sought << " occurs " << times
		<< (times > 1 ? " times" : " time") << endl;

	if (times > 0)
	{
		auto it = qr.lines->second.begin();

		while (it != qr.lines->second.end())
		{
			os << "(" << *it <<") " 
				<<*(qr.content->begin() + *it) << endl;
			++it;
		}
	}

	return os;
}

int main(void)
{
	ifstream in("china_daily.txt");
	if(!in)
	{
		cout<<"file open failed"<<endl;
		return 0;
	}

	TextQuery tq(in);
	string word;
	while(cin>> word)
	{
		QueryResult ret(tq.query(word));
		cout<<ret;
	}

	in.close();
	return 0;
}
