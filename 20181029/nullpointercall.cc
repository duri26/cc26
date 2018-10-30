 ///
 /// @file    nullpointercall.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 14:15:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class nullpointercall
{
	public:
		void func1()
		{
			cout<<"func1()"<<endl;
		}
		void func2(int ix)
		{
			cout<<"func2() ix="<<ix<<endl;
		}
		void func3()
		{
			cout<<"func3() _iy="<<_iy<<endl;
		}
		void func4()
		{
			cout<<"funx4() _ix="<<_ix<<endl;
		}
private:
		int _ix;
		static int _iy;
};

int nullpointercall::_iy=100;
int main()
{
	nullpointercall *p=NULL;
	p->func1();
	p->func2(1);
	p->func3();
//	p->func4();
	return 0;
}
