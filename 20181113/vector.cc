 ///
 /// @file    vector.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-13 11:02:32
 ///
#include <string.h>

#include <vector> 
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> numbers{1,2,3,4,5,6,7,8,9};//vecotr有三个指针，start,finish,endofstroge;

	cout<<"sizeof(numbers) = "<<sizeof(numbers)<<endl;
//cout<<"strlen(numbers) =" <<strlen(numbers)<<endl;
	return 0;
}
