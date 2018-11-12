 ///
 /// @file    list.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-09 09:30:35
 ///
#include <list> 
#include <iostream>
using std::cout;
using std::endl;
using std::list;

int main(void)
{
	list<int> numbers{1, 2, 3, 4, 5};
	list<int> numbers2;

	cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
	cout << "sizeof(numbers2) = " << sizeof(numbers2) << endl;

	return 0;
}

