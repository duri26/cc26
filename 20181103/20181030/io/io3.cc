 ///
 /// @file    io3.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-13 23:42:05
 ///
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ostringstream;
using std::istringstream;
using std::ifstream;

void test0()
{
	int n1=100,n2 =200;
	stringstream ss;
	ss << "n1=  "<<n1<<"n2=  "<<n2<<endl;

	string line =ss.str();
	cout<<line<<endl<<endl;

	string word;
	int number;
	while(ss>> word >>number, !ss.eof())
	{
		cout<<word<<"             "<<number<<'\n';
	}
	cout<<endl;
}

int main(void )
	{
		test0();


		return 0;
	}
