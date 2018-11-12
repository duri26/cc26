 ///
 /// @file    remove_if.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 15:49:11
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
using std::remove;

int main(void)
	{
		vector <int> numbers{4,3,2,4,1,4,5,6,4};
		std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout, " "));
		cout<<endl;
remove(numbers.begin(),numbers.end(),4);
		std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
cout<<endl;
		numbers.erase(remove(numbers.begin(),numbers.end(),4),numbers.end());

		std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout," "));
		cout<<endl;

		return 0;
	}
