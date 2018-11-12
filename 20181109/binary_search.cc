 ///
 /// @file    binary_search.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 16:45:43
 ///
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using std::cout;
using std::endl;
using std::binary_search;
using std::vector;
using std::list;
using std::sort;

int test0(void)
{
	vector<int> numbers{3,2,1,5,4,6};

	sort(numbers.begin(),numbers.end());

	if(binary_search(numbers.begin(),numbers.end(),6))
	{
		cout<<"查找成功"<<endl;
	}
	else
	{
		cout<<"查找失败"<<endl;
	}

	return 0;
}

int test1(void)
{
	vector<int> numbers{3,2,1,5,6,4,6,3,6,6,3};

	sort(numbers.begin(),numbers.end());

	auto lit=std::lower_bound(numbers.begin(),numbers.end(),6);
	auto uit=std::upper_bound(numbers.begin(),numbers.end(),6);
	for(;lit != uit; ++lit)
	{
		cout<< * lit<<" ";
	}
	cout<<endl;

}


int main(void)
{
	test1();

	return 0;
}
