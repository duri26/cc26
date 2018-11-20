 ///
 /// @file    queryresult.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-19 20:59:03
 ///

#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>

using std::shared_ptr;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;
using std::ostream;
using std::cout;
using std::endl;


class QueryResult
{
	friend  ostream & print(ostream &,const QueryResult &);

	public:
	typedef vector<string> ::size_type line_no;
	typedef set<line_no>::const_iterator line_it;

	QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f)
		:sought(s),lines(p),file(f)
	{
	}

	set<line_no>::size_type size() const 
	{
		return lines->size();
	}

	line_it begin() const
	{
		return lines->begin();
	}

	line_it end() const
	{
		return lines->end();
	}

	shared_ptr<vector<string>> get_file()
	{
		return file;
	}

	private:
	string sought;
	shared_ptr <set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

ostream & print(ostream & ,const QueryResult &);

#endif 
