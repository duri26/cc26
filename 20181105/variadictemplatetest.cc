 ///
 /// @file    variadictemplatetest.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-05 23:55:56
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#if 0
void print()
{
	cout<<endl;
}
#endif
void print()
{
	cout<<endl;
}

template <typename T>
void print(T t)
	{
		cout<< t<<endl; ;
	}

template <typename T,typename ... Args>
void print (T t,Args... args)
{
	cout<<t<<"  ";
	print(  args...);
}


int main(void)
{
	print(2,6,6,"hello",6,3,"hi");

	return 0;
}
