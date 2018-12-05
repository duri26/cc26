 ///
 /// @file    dictionary.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 21:31:03
 ///

#ifndef __WD_DICTIONARY_H__
#define __WD_DICTIONARY_H__

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

namespace wd
{

class Dictionary
{
	class AutoRelease
	{
		public:
			~AutoRelease();
	};
	public:
	static Dictionary * getInstance();
	std::vector<std::pair<std::string ,size_t >> & getDict()
	{
		return _dict;
	}
	std::unordered_map<std::string ,std::set<int>> & getIndexTable()
	{
		return _indexTable;
	}

	void initDict(const std::string & );
	void initIndex(const std::string & );

	private:
	Dictionary() {}

	private:
	std::vector<std::pair<std::string ,size_t >> _dict;
	std::unordered_map<std::string ,std::set<int>> _indexTable;

	static AutoRelease _ar;
	static Dictionary * _pInstance;
};

#define getDict() Dictionary::getInstance()->getDict()
#define getIndexTable() Dictionary::getInstance()->getIndexTable()
}

#endif
