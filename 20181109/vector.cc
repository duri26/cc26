 ///
 /// @file    vector.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 16:08:43
 ///
#include <vector> 
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> numbers;
	numbers.push_back(1);
	bool flag =true;
	for(auto it = numbers.begin();it != numbers.end();++it)
	{
		cout<<*it<<" ";
			if(flag)
			{
				numbers.push_back(2);//在遍历容器的过程中，如果添加元素，有可能引起动态扩容，从而造成迭代器失效；
				flag=false;
			}
	}
	cout<<endl;
return 0;
}
