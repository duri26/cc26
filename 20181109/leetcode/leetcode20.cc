///
/// @file    leetcode20.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-12 22:35:38
///
#include <string>
#include <stack>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::stack;

class Solution
{
	public:
		bool isValid(const string s)
		{
			if(s.empty())
				return true;
			if(s.size()%2)
				return false;

			stack<char> st;
			auto it =s.begin();
			for(;it !=s.end();++it)
			{
				if(st.empty())
				{
					st.push(*it);
					continue;
				}
				char ch = st.top();
				switch(ch)
				{
					case '(':
						if(*it ==')')
							st.pop();
						else
							st.push(*it);
						break;
					case '[' :
						if(*it ==']')
							st.pop();
						else
							st.push(*it);
						break;
					case '{':
						if(*it == '}')
							st.pop();
						else
							st.push(*it);
						break;
					default:
						return false;
				}
			}
			if(st.empty())
				return true;
			else
				return false;
		}
};

int main(void)
{
	Solution s;
	cout << "() " << s.isValid("()") << endl;
	cout << "()[]{} " << s.isValid("()[]{}") << endl;
	cout << "(] " << s.isValid("(]") << endl;
	cout << "([)] " << s.isValid("([)]") << endl;
	cout << "{[]} " << s.isValid("{[]}") << endl;

	return 0;
}
