 ///
 /// @file    DictProducer.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-08 10:54:18
 ///

#ifndef __DICT_DICTPRODUCER_H__
#define __DICT_DICTPRODUCER_H__

#include "SplitTool.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

namespace dict
{

class Configuration;

class DictProducer
{
	public:
		DictProducer();
		DictProducer(SplitTool * splitTool);
		void buildDict();
		void buildIndex();
		void store() const;

	private:
		void getStopWordsDict(const string &);
		void getFiles();
		void getAllFiles(vector<string> &,const string &);
		void strProcess(std::string &);
		int getBytesCode(char);

	private:
		std::string _dir;
		std::vector<std::string> _enFiles;
		std::vector<std::string> _cnFiles;
		SplitTool * _splitTool;
		std::unordered_set<std::string> _stopWordsDict;
		std::unordered_map<std::string, size_t> _dict;
		std::unordered_map<std::string, std::set<size_t>> _index;
};

}

#endif
