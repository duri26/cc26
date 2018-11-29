///
/// @file    index.h
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-28 22:03:00
///

#ifndef __WD_INDEX_H__
#define __WD_INDEX_H__

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

	class Index
	{
		public:
			void read(const string & filename);
			void store(const string & filename);
		private:

			void insert(const string & word);

			vector<pair<string,int>> _word; 
			unordered_map<string, set<int>> _index;
	};

}

#endif
