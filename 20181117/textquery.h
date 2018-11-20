 ///
 /// @file    textquery.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-19 20:45:49
 ///

#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include "queryresult.h"

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
//Textquery.cc
#include <cstddef>
#include <sstream>
#include <cctype>
#include <cstring>
#include <utility>

//Textquery.cc
using std::size_t;
using std::istringstream;
using std::getline;
using std::cerr;
using std::cin;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

using std::shared_ptr;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;
using std::ostream;
using std::cout;
using std::endl;

class QueryResult;

class TextQuery
{
	public:
		typedef vector<string> ::size_type line_no;
		TextQuery(ifstream &);
		QueryResult query(const string &) const;
		void display_map();

	private:
		shared_ptr<vector<string>> file;

		map<string,shared_ptr<set<line_no>>> wm;

		static string cleanup_str(const string &);
};

#endif

