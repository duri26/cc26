 ///
 /// @file    pod.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 15:19:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct Foo
{
	int x;
	int y;
	Foo(int a ,int b )  //列表初始化
//		:x(a),y(b)
	{
		cout<<"Foo construction"<<endl;
		
	}

};

int main(void)
{
	Foo foo{123,123};
	cout<<"x: "<<foo.x<<" ------y: "<<foo.y<<endl;

	return 0;
}
