///
/// @file    leetcode127.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-12 23:22:09
///
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::set;

class Solution
{
	public:
		int ladderLength(const string & start,const string & end, const set<string> & dict)
		{
			if(0==dict.count(end))
			{
				return 0;
			}

		set<string> visited;


		int level = 0;
		bool found = false;
		auto nextStates = [&](const string & word)
		{
			vector<string>  result;
			for(size_t idx = 0; idx != word.size(); ++idx)
			{
				string copy(word);
				for(char ch = 'a';ch <= 'z';++ch)
				{
					if(ch == copy[idx])
						continue;
					std::swap(ch,copy[idx]);
					if((dict.count(copy)>0 ||copy ==end) && !visited.count(copy))
					{
						result.push_back(copy);
					visited.insert(copy);
				}
				std::swap(ch,copy[idx]);
			}
		}
		return result;
};

queue<string> current,next;
current.push(start);
while(!current.empty() && !found)
{
	++level;
	while(!current.empty() && !found)
	{
		string str=current.front();
		current.pop();
		const auto newStates = nextStates(str);
		for(auto & state: newStates)
		{
			next.push(state);
			if(state == end)
			{
				found = true;
				break;
			}
		}
	}
	swap(next,current);
}
if(found)
	return level + 1;
	else 
	return 0;
	}	
};

int main(void)
{
#if 0
	string start = "hit";
	string end = "cog";
	set<string> dict{"hot", "dot", "dog", "log", "lot"};
#endif

#if 1
	string start = "hit";
	string end = "cog";
	set<string> dict{"hot", "dot", "dog", "log", "lot", "cog"};
#endif

	Solution s;
	cout << s.ladderLength(start, end, dict) << endl;
	return 0;
}
