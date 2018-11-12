 ///
 /// @file    replace_if.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 16:17:59
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
using std::replace_if;

int main(void)
{
	vector<int> numbers{4,3,2,4,1,6,4,2};
	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

#if 0
	std::less<int> lt;
	replace_if(numbers.begin(),numbers.end(),std::bind2nd(lt,4),10);
#endif

	replace_if(numbers.begin(),numbers.end(),[](int n)
			{
			if(n>4)
			return true;
			else
			return false;
			},10);

	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	return 0;
}
