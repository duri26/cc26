 ///
 /// @file    DictProducer.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 16:45:27
 ///

#ifndef __DURI_DICTPRODUCER_H__
#define __DURI_DICTPRODUCER_H__

#include "SplitTool.h"

#include <unordered_map>
#include <set>

namespace duri
{

class Configuration;

class DictProducer
{
	public:
		DictProducer();
		DictProducer(SplitTool * splitTool);
		void buildEnDict();
		void buildCnDict();
		void buildIndex();
		void store() const;

	private:
		void getFiles();
		void push_dict(const string &);
		void strProcess(string &);

	private:
		string _dir;
		vector<string> _files;
		SplitTool * _splitTool;
		std::unordered_map<string, size_t> _dict;
		std::unordered_map<string, std::set<size_t>> _index;
};

}

#endif
