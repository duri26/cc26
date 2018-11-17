 ///
 /// @file    textquery.cc
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
		QueryResult(string s, shared_ptr<vector<string>> p,
				shared_ptr<pair<int, set<int>>> 1)
			:sought(s)
			 ,content(p)
			 ,lines(1)
		{}

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
if(it != wm.end())
{
	return QueryResult(word,content,nodata);
}
else
{
	return QueryResult(word, content,it->sencond);
}
}

std::ostream & operator <<(std::ostream & os,const QueryResult & qu)
{
	int count = qu.lines->first;
	os<<qu.sought<<" occurs "<<(count>1?"times":"time")<<endl;

	if(count > 0)
	{
		auto it = qu.lines->second.begin();
	
	while(it != qu.lines->sencond.begin())
	{
		os<<"("<<*it <<")"<<*(qu.content-begin()+*it)<<endl;
		++it;
	}
}
return os;
}


