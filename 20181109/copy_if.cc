 ///
 /// @file    copy_if.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 17:20:37
 ///
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::ostream_iterator;

int main(void)
{
	vector<int> numbers{3,2,1,5,6,4};
	list <int> li {11,33,44,55};

	std::copy_if(li.begin(),li.end(),std::back_inserter(numbers),[](int n)
			{
			if(n >20)
			return true;
			else
			return false;
			});
	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	return 0;
}
