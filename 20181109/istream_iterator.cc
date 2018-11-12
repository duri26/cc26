 ///
 /// @file    istream_iterator.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 15:29:36
 ///
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;

int main(void)
{
	vector<int> numbers;
	istream_iterator<int> isi(cin);

//	std::copy(isi,istream_iterator<int>(),numbers.begin());
//错误////////////////////////////////////////////////////////////////
	std::copy(isi,istream_iterator<int>(),std::back_inserter(numbers));

	std::copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout,"\n "));

	return 0;
}
