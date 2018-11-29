 ///
 /// @file    DictProducer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 19:53:36
 ///

#include "DictProducer.h"
#include "Mylogger.h"
#include "Configuration.h"

#include <string.h>
#include <dirent.h>
#include <sys/types.h>

#include <fstream>
#include <sstream>

namespace duri
{

DictProducer::DictProducer()
	:_splitTool(NULL)
{
	_dir =getConfig("enDictionaryDir");
	if(_dir.size() == 0)
	{
		LogError("no dictionary soure file");
		exit(EXIT_FAILURE);
	}
}

DictProducer::DictProducer(SplitTool * splitTool)
: _splitTool(splitTool)
{
	_dir =getConfig("cnDictionayDir");
	if(_dir.size() == 0)
	{
		LogError("no dictionary soure file");
		exit(EXIT_FAILURE);
	}
}

void DictProducer::buildEnDict()
{
	getFiles();
	std::ifstream input;

	std::string line,word;
	for(const auto & file: _files)
	{
		input.open(file);
		if(input)
		{
			LogInfo("open dictionary file \"%s\" success"
					,file.c_str());
			while(getline(input,line))
			{
				strProcess(line);

				std::istringstream ss(line);
				while(ss >> word)
				{
					_dict[word]++;
				}
			}
		}
		else
		{
			LogError("open dictionary file \"%s\" failed"
					,file.c_str());
		}
		input.close();
	}
	LogInfo("build dict.dat success");
}

void DictProducer::buildCnDict()
{


}

void DictProducer::getFiles()
{
	DIR * dir = opendir(_dir.c_str());
		if(!dir)
	{
		LogError("no such dirctionay");
	}

	struct dirent * fileInfo;
	string file;

	//无递归查找子目录
	while((fileInfo = readdir(dir)) !=  NULL)
	{
      if(fileInfo->d_type == DT_REG)
	  {
		  file = _dir + "/" + fileInfo->d_name;
		  _files.push_back(file);
		  LogDebug("add \"%s\" to dictionary files",file.c_str());
	  }
	}
}


void DictProducer::buildIndex()
{
	size_t idx = 0;
	for(const auto & record : _dict)
	{
		for(const auto & c: record.first)
		{
			char s[2] ={c};
			auto it = _index.find(s);
			if(it == _index.end())
		{
			_index.insert(std::make_pair(string(s)
						,std::set<size_t>{idx}));
		}
			else
			{
				it->second.insert(idx);
			}
		}
		++idx;
	}
	LogInfo("create index.dat success");
}

void DictProducer::store() const 
{
	std::string file =getConfig("dictionaryStoreFile");
	if(file.size() == 0)
	{
		LogError("no dictionary store file");
		exit(EXIT_FAILURE);
	}

	std::ofstream output(file);
	for(const auto & record: _dict)
	{
		output<<record.first<<" "<<record.second<<"\n";
	}
	output.close();

	file = getConfig("indexStoreFile");
	if(file.size() == 0)
	{
		LogError("no index store file");
		exit(EXIT_FAILURE);
	}

	output.open(file);
	for(const auto & record: _index)
	{
		output<<record.first<< ":";
		for(const auto & i: record.second)
		{
			output<<" "<<i;
		}
		output<<"\n";
	}
	output.close();
}

void DictProducer::strProcess(string & str)
{
	for(auto & c:str)
	{
		if(!isalpha(c))
		{
			c = ' ';
		}
		else 
		{
			c =tolower(c);
		}
	}
}

}

