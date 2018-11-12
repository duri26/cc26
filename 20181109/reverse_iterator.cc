 ///
 /// @file    reverse_iterator.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 17:13:14
 ///
#include <vector>
#include <iterator>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
vector<int> numbers{1,2,3,4,5};
	vector<int> :: reverse_iterator rit = numbers.rbegin();
	
	while(rit != numbers.rend())
{
	cout<<*rit<<" ";
	++rit;
}

cout<<endl;

return 0;
}
