///
/// @file    io1.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-10-30 20:24:54
///

#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::string;
using std::cout;
using std::endl;

void printCinStatus()
{
	cout<<"cin's badbit=" <<cin.bad()<<endl;
	cout<<"cin's failbit="<<cin.fail()<<endl;
	cout<<"cin's eofbit="<<cin.eof()<<endl;
	cout<<"cin's goodbit="<<cin.good()<<endl;
}

int test0(void)
{
	cout<<"sizeof(cin)="<<sizeof(cin)<<endl;
	cout<<"sizeof(cout)="<<sizeof(cout)<<endl;

	int number;
	printCinStatus();

	while(cin >> number)
	{
		cout<< "number="<<number<<endl;
	}

	printCinStatus();
	cout<<endl<<"重置流的状态"<<endl;

	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	printCinStatus();

	string line;
	cin >> line;
	cout <<"line="<<line<<endl;
	return 0;
}

void test1()
{
	int number;
	cout<<"please input a valid integer:"<<endl;
	while(cin>>number,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"stream has corrupted!"<<endl;
			return ;
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		cout<<"number="<<number<<endl;
	}
}

int main(void)
{
//	test0();
test1();
	return 0;
}
