 ///
 /// @file    io3.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 21:29:32
 ///
#include <string>
#include <sstream>
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
	int n1=100,n2=200;
	stringstream ss;
	ss<<"n1="<<n1<<"n2="<<n2<<endl;
	string line =ss.str();
	cout<<line<<endl<<endl;

	string word;
	int number;
	while(ss>>word >>number, !ss.eof())
	{
		cout <<word<<" "<<number<<"\n";
	}
	cout<<endl;
}

string int2str(int number)
{
	ostringstream oss;
	oss<<number;
	return oss.str();
}

void readConfig(const string &file)
{
	ifstream ifs(file);
	if(!ifs)
	{
		cout<<"ifstream create error"<<endl;
		return ;
	}

	string key,value;
	string line;
	while(getline (ifs,line))
	{
		istringstream iss(line);
		iss>>key>>value;
		cout<<key<<"--->"<<value<<endl;
	}
	ifs.close();
}

int main(void)
{
	test0();
	cout<<int2str(1024)<<endl;
	cout<<std::to_string (1024)<<endl<<endl;

	readConfig("file");
	return 0;
}
