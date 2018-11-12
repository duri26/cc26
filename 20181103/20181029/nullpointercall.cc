 ///
 /// @file    nullpointercall.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-07 14:19:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class NullPointerCall
{
public:
	void func1()
	{	cout << "func1()" << endl;	}

	void func2(int ix)
	{	cout << "func2() ix = " << ix << endl;	}

	static void func3() 
	{	cout << "func3()  _iy = " << _iy << endl;}

	void func4()
	{
		cout << "func4()  _ix = " << endl;
	cout<<_ix<<endl;
	}

private:
	int _ix;
	static int _iy;
};

int NullPointerCall::_iy = 100;
 
int main(void)
{
//	NullPointerCall * p = new NullPointerCall;
	NullPointerCall * p = NULL;
	p->func1();//NullPointerCall 有确定的指针类型，可以在代码区找到func1();
	p->func2(1);
	p->func3();//静态区，也可以直接访问；
	p->func4();//空指针找不到 private 的 _ix;

	return 0;
}

