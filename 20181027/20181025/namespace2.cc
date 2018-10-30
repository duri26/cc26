 ///
 /// @file    namespace1.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-27 15:19:19
 ///
 
#include <iostream>

using std::cout;
using std::endl;


namespace wd
{
	int num=10;

	void display()
	{
		cout << "wd:: display()"<<endl;
	}
namespace duri
{
	int num=26;
}

}

int main()
{
	cout << "num ="<<wd::duri::num<<endl;
	wd::display(); //作用域限定符
	return 0;
}
