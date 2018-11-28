 ///
 /// @file    dictionary.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-28 16:26:19
 ///


#ifndef __WD_DICTIONARY_H__
#define __WD_DICTIONARY_H__

#include <string>
#include <unordered_map>

using std::string;

namespace wd
{

class Dictionary
{
	public:
		void read(const string &);
		void store(const string &);
	private:
		size_t find_first_alp(const string,size_t);
		size_t find_first_not_alp(const string,size_t);

	private:
		void insert(const string & word);
		std::unordered_map<string,size_t> _dict;
};

}

#endif
