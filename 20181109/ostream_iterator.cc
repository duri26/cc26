 ///
 /// @file    ostream_iterator.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 11:52:39
 ///
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::copy;

int main(void)
{
	vector<int> numbers{2,3,4,5,1};
ostream_iterator<int> osi(cout, "  ");
copy(numbers.begin()+2,numbers.end(),osi);


	return 0;
}
