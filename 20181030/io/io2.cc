 ///
 /// @file    io2.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 20:47:23
 ///
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::vector;

vector<string> lines;

void test1()
{
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout<<" ifstream create error"<<endl;
		return ;
	}

	lines.reserve(77);
string vord;
string line;
while(std::getline(ifs,line))
{
	lines.push_back(line);
}

for(auto &elem :lines)
{
	cout<<elem<<endl;
}
ifs.close();
}

void test2()
{
	test1();

	string file="file";
	ofstream ofs(file);
	if(!ofs)
	{
		cout << "ofstream create error "<<endl;
		return ;
	}

	for(auto &line: lines)
	{
		ofs<<line<<"\n";
	}

	ofs.close();
}

void test3()
{
	string file="file";
	ofstream ofs(file,std::ios::app);
	if(!ofs)
		{
			cout<< "ofstream create error"<<endl;
			return ;
		}
	int pos=ofs.tellp();
	cout<< "pos ="<<pos <<endl;

	ofs<<"add new line .\n";
	ofs.close();
}

void test4()
{
	fstream fs("test.txt");
	if(!fs)
	{
		cout<< "fstream cteate error"<<endl;
		return ;
	}

	cout<<"please input 10 integer"<<endl;
	int number;
	for(int idx=0;idx!=10;++idx)
	{
		cin>>number;
		fs<<number<<" ";
	}
	int pos=fs.tellp();
	cout <<"pos ="<<pos<<endl;
fs.seekg(0,std::ios::beg);

cout<<endl
<<"fs.badbit="<<fs.bad()<<endl
<<"fs.failbit="<<fs.fail()<<endl
<<"fs.eofbit="<<fs.eof()<<endl
<<"fs.goodbit="<<fs.good()<<endl;

for(int idx=0;idx!=10;++idx)
{
	fs>>number;
	cout<<endl
<<"fs.badbit="<<fs.bad()<<endl
<<"fs.failbit="<<fs.fail()<<endl
<<"fs.eofbit="<<fs.eof()<<endl
<<"fs.goodbit="<<fs.good()<<endl;
cout<<number<<" ";
}
cout <<endl;
fs.close();
}

int main(void)
{
	test1();
		test2();
test3();
test4();
return 0;
}
