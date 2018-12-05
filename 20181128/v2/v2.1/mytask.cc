 ///
 /// @file    mytask.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 21:45:25
 ///

#include "mytask.h"
#include "bitmap.h"
#include "dictionary.h"
#include "cachemanager.h"
#include "thread.h"

#include <json/json.h>

namespace wd
{

MyTask::MyTask(const string & queWord,const TcpConnectionPtr & conn)
	:_queryWord(queWord)
	 ,_conn(conn)
	{}

void MyTask::excute()
{
	if(!_queryWord.size())
	{
		_conn->sendInLoop("no");
		return;
	}

	Cache & cache = CacheManager::getCache(atoi(pthreadName));
	string result = cache.getElement(_queryWord);
	if(result.size())
	{
		_conn->sendInLoop(result);
		return ;
	}

	auto dict = getDict();
	auto index = getIndexTable();

	BitMap candidata(dict.size());

	for(int i= 0;i!=getLength(_queryWord);++i)
	{
		string s =getNthChar(_queryWord,i);
		auto container = index[s];
		for(int idx: container)
		{
			candidata.setMap(idx);
		}
	}

	for(size_t idx = 0; idx != candidata.size(), ++idx)
	{
		if(candidata.isSet(idx))
		{
			int dist = distance(dict[idx].first);
			if(dist <= 3)
			{
				_resultQue.push(MyResult(
							dict[idx].first
							,dict[idx].second
							,dist));
			}
		}
	}
	response();
}

void MyTask::response()
{
	Json::Value item;

	for(size_t i =0; i != 6; ++i)
	{
		if(_resultQue.size())
		{
			item[to_string(i)] = _resultQue.top()._word;
			_resultQue.pop();
		}
		else
		{
			break;
		}
	}

	string sendItem = item.toStyledString();

	if(_resultQue.size())
		CacheManager::getCache(atoi(pthreadName)).addElement(_queryWord,sendItem);
	_conn->sendInLoop(sendItem);
}

int MyTask::distance(const string & rhs)
{
	const int size1 = getLength(_queryWord),size2 = getLength(rhs);
	if(size1 == 0)
		return size2;
	if(size2 == 0)
		return size1;
	vector<vector<int >> ed(size1 + 1,vector<int>(size2 + 1,0));

	for(int i = 0;i != size1 +1;++i)
	{
		ed[i][0] = i;
	}
	for(int i =0; i != size2 +1; ++i)
	{
		ed[0][i] = i;
	}

	for(int i = 1; i != size1 + 1;++i)
	{
		for(int j=1; j!= size2 + 1; ++j)
		{
			if(getNthChar(_queryWord, i -1) == getNthChar(rhs,j - 1))
				ed[i][j] = ed[i-1][j-1];
			else 
				ed[i][j] = min(min(ed[i][j - 1] +1,ed[i -1][j] +1)
						,ed[i -1][j-1]+1);
		}
	}
	return ed[size1][size2];
}

string MyTask::getNthChar(const string & word,int n)
{
	int pos = 0;
	while(n--)
	{
		pos += getBytesCode(word[pos]);
	}
	return string (word,pos,getBytesCode(word[pos]));
}

int MyTask::getLength(const string & word)
{
	int cnt = 0;
	for(auto cit = word.cbegin();cit != word.cend();)
	{
		cit += getBytesCode(*cit);
		++cnt;
	}
	return cnt;
}

int MyTask::getBytesCode(char c)
{
	if(!(c & 0x80))
{
	return 1;
}

int cnt = 0;
do{
	c <<= 1;
	cnt ++;
}
while(c & 0x80);
return cnt;
}

}
