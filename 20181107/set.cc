 ///
 /// @file    set.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-09 22:36:16
 ///
 
#include <math.h>

#include <set>
#include <iostream>

using std::cout;
using std::endl;
using std::set;

template <typename Container>
void display(const Container & c)
{
	for(auto & elem : c)
	{
		cout<< elem<<" ";
}
cout<<endl;
}

void test0()
{
int arr[10] ={ 1,4,4,5,2,4,3,9,8};
set<int> numbers(arr,arr+9);
display(numbers);

size_t cnt = numbers.count(4);
cout<<"cnt ="<<cnt<<endl;
cnt = numbers.count(6);
cout<<"cnt ="<<cnt<<endl;
}


int main(void)
{
	test0();

	return 0;
}
