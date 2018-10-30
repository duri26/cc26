 ///
 /// @file    namespace1.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-27 15:19:19
 ///
 
#include <iostream>

using namespace std;//using 编译指令

namespace wd
{
	int num=10;

	void display()
	{
		cout << "wd:: display()"<<endl;
	}
}

int main()
{
	cout << "num ="<<wd::num<<endl;
	wd::display(); //作用域限定符
	return 0;
}
