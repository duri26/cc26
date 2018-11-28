 ///
 /// @file    dictionary_shared_ptr.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-28 20:09:14
 ///

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string.h>

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>

using std::vector;
using std::string ;
using std::map;
using std::unordered_map;
using std::set;
using std::shared_ptr;
using std::pair;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::endl;
using std::cout;

namespace wd
{

class Dictionary
{

	public:
		void read(const string & filename);
		void store(const string & filename);
	private:
		
		void strProcess(string &);
		void insert(const string & word);
		unordered_map<string, size_t> _dict;
};


}

#endif 
