 ///
 /// @file    vector.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-13 20:41:17
 ///
#include <vector> 
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void printvector(vector <int> & vec)
{
	cout<<"vec's size = "<<vec.size()<<endl
		<<"vec's capacity = "<<vec.capacity()<<endl;
}


int main(void)
{
	vector<int> n;
	n.reserve(4);

	printvector(n);

	n.push_back(1);
	printvector(n);

	n.push_back(2);
	printvector(n);

	n.push_back(3);
	printvector(n);

	n.push_back(4);
	printvector(n);

	n.push_back(5);
	printvector(n);

	n.push_back(6);
	printvector(n);

	n.push_back(7);
	printvector(n);

	for(size_t idx =0;idx != n.size();++idx)
	{
		cout<<n[idx]<<" ";
	}
	cout<<endl;

	cout<<endl<<"auto:"<<endl;
	for(auto & elem : n)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

	return 0;
}
