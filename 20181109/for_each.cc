///
/// @file    for_each.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-10 11:26:12
///
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using std::cout;
using std::endl;
using std::for_each;
using std::vector;
using std::set;
void print(int & n)
{
	cout<<n<<" ";
}

void display(int & number)
{
	++number;
	cout<<number<<"  ";
}

int main(void)
{
	vector<int> numbers{3,2,1,5,4,6};

	for_each(numbers.begin(),numbers.end(),display);

	cout<<endl;
	for_each(numbers.begin(),numbers.end(),[&](int n)
		{
		cout<<*numbers.begin()<<"  "<<n <<"\n";
		});
	cout<<endl;
for_each(numbers.begin(),numbers.end(),[&](int z){
		cout<<++z<<" ";
		});

	cout<<endl;
	for_each(numbers.begin(),numbers.end(),print);
	return 0;
}
