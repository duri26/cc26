 ///
 /// @file    functionobject.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-02 17:41:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Test
{
	public:
		int operator ()(int x,int y)
		{
			return x + y;
		}

		int operator () (int x,int y,int z)
		{
			return x * y *z;
		}

	private:
//		int _cnt;
};

int func1(int x,int y)
{
	static int c =0;
	++c;
	return x + y;
}


int main(void)
{
	Test test;
	cout<<"test(3,6)="<<test(3,6)<<endl;
	cout<<"test(1,1,1)="<<test(1,1,1)<<endl;
	cout<<"func1(3,6)="<<func1(3,6)<<endl;

	Test test2;
	return 0;
}
