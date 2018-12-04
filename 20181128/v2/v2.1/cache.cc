 ///
 /// @file    cache.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 16:46:46
 ///

#include "cache.h"
#include "thread.h"
#include "Mylogger.h"

#include <fstream>
#include <sstream>

namespace wd
{

bool operator<(const Cache::CacheNode & cache1
		,const Cache::CacheNode & cache2)
{
	return cache1.key<cache2.key;
}

Cache::Cache(size_t capacity)
:_capacity(capacity)
{
}

Cache::Cache(const Cache & cache)
	:_capacity(cache._capacity)
	 ,_cache(cache._cache)
	 ,_hashMap(cache._hashMap)
{
}

size_t Cache::size() const 
{
	return _hashMap.size();
}

string Cache::getElement(string key)
{
	auto it = _hashMap.find(key);
	if(it == _hashMap.end())
	{
		return string();
	}
	else
	{
		if(it->second != _cache.begin())
		{
			cout<<it->second->value<<"\n\n"<<endl;
			_cache.splice(_cache.begin(),_cache,it->second);
		}
		_hashMap[key]= _cache.begin();
		_recentlyUpdateCache.emplace(key,_cache.begin()->value);

		return _cache.begin()->value;
	}
}

void Cache::addElement(string key,string value)
{
	_recentlyUpdateCache.emplace(key,value);

	auto it = _hashMap.find(key);
	if(it == _hashMap.end())
	{
		_cache.emplace_front(key,value);
		if(_hashMap.size() != _capacity)
		{
			_hashMap[key] = _cache.begin();
		}
		else
		{
			_hashMap.erase(_cache.end()->key);
			_hashMap.emplace(key,_cache.begin());
			_cache.pop_back();
		}
	}
	else
	{
		it->second->value =value;
		if(it->second != _cache.begin())
		{
			_cache.splice(_cache.begin(),_cache,it->second);
		}
		_hashMap[key] = _cache.begin();
	}
}

void Cache::readFromFile(const string & filename)
{
	ifstream input(filename);
	if(!input)
	{
		duri::LogWarn("  Open cache file \"%s\" failed",filename.c_str());
		return ;
	}
	else
	{
		duri::LogInfo("  Open cache file \"%s\" success",filename.c_str());
	}

	string key,value;
	char ch;
	bool flag;
	while(input >> key)
	{
		flag = false;
		while(input.get(ch))
		{
			if(ch == '{')
			{
				flag = true;
				value.push_back(ch);
			}
			else if(ch == '}')
			{
				value.push_back(ch);
				break;
			}
			else if(flag)
			{
				value.push_back(ch);
			}
		}
		cout<<" key = "<<key
			<<" value = "<<value<<" \n\n\n "<<endl;
		_cache.emplace_back(key,value);
		if(_cache.size() == _capacity)
		{
			break;
		}
	}
	for(auto it = _cache.begin();it != _cache.end();++it)
	{
		_hashMap.emplace(it->key,it);
	}
	input.close();
}

void Cache::writeToFile(const string & filename)const
{
	ofstream output(filename);
	if(!output)
	{
		duri::LogWarn("  Open cache store file\"%s\" failed",filename.c_str());
		output.close();
		return;
	}
	else 
	{
		duri::LogInfo("  Open cache store file \"%s\" success",filename.c_str());
	}
	
	for(const auto & ele: _cache)
	{
		output<< ele.key<<" "<<ele.value<<"\n";
	}

	output.close();
}

const set<Cache::CacheNode> & Cache::getRecentlySet() const 
{
	return _recentlyUpdateCache;
}

set<Cache::CacheNode> & Cache::getRecentlySet()
{
	return _recentlyUpdateCache;
}

void Cache::update(const Cache & cache)
{
	auto pairs = cache.getRecentlySet();
	for(const auto & pair: pairs)
	{
		addElement(pair.key,pair.value);
	}
}

}
