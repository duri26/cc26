 ///
 /// @file    leetcode146.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-12 22:47:28
 ///
#include <list>
#include <unordered_map>
#include <iostream>
using std::cout;
using std::endl;
using std::list;
using std::unordered_map;

class LRUCache
{
	struct CacheNode
	{
		int key;
		int value;

		CacheNode(int k,int v)
			:key(k),value(v)
		{}
	};

	public:
	LRUCache(int capacity)
		:_capacity(capacity)
	{}

	int get(int key)
	{
		auto it = _hashTable.find(key);
		if(it == _hashTable.end())
			return -1;
		else
		{
			_data.splice(_data.begin(),_data,_hashTable[key]);
			_hashTable[key]= _data.begin();
			return _hashTable[key]->value;
		}
	}

	void put(int key,int value)
	{
		auto it = _hashTable.find(key);
		if(it ==_hashTable.end())
		{
			if(_hashTable.size() == _capacity)
			{
				_hashTable.erase(_data.back().key);
				_data.pop_back();
			}
			_data.push_front(CacheNode(key,value));
			_hashTable[key] = _data.begin();
		}
		else
		{
			_hashTable[key]->value = value;
			_data.splice(_data.begin(),_data,_hashTable[key]);
			_hashTable[key] = _data.begin();
		}
	}
	private:
list<CacheNode> _data;
unordered_map<int ,list<CacheNode>::iterator>_hashTable;
size_t _capacity;
};

int main(void)
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;

	return 0;
}

