 ///
 /// @file    namespace1.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-27 15:19:19
 ///
 
#include <iostream>

using std::cout;
using std::endl;

int num=1;

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

using namespace wd;
int main()
{
	cout << "num ="<<wd::duri::num<<endl;
	wd::display(); //作用域限定符
cout << "num="<<wd::num<<endl;
cout << "num="<<::num<<endl;
return 0;
}
