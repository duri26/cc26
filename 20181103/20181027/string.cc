 ///
 /// @file    string.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-06 22:36:21
 ///
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class string
{
	public:
	string();
	string(const char * pstr);
	string(const string & rhs);
	string & operator =(const string & rhs);
	~string();

	
	void print();

	private:
char * _pstr;
};

string ::string ()
	:_pstr(new char (0))
{}

string ::string(const char *pstr)
	: _pstr(new char [strlen(pstr)+1]())
{
	strcpy(_pstr,pstr);
}

string ::string (const string & rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]())
{
	strcpy(_pstr,rhs._pstr);
}

string & string :: operator =(const string & rhs)
{
	if(this != &rhs)
	{
		delete [] _pstr;
		_pstr=new char [strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
	}
	return *this;
}

string :: ~string ()
{
	delete [] _pstr;
}


void string:: print()
{
	cout<<_pstr<<endl;
}


int main(void)
{
	string str1;
	str1.print();

	string str2 = "Hello,world";
	string str3("wangdao");

	str2.print();		
	str3.print();	

	string str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}


