///
/// @file    string.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-10-29 20:07:59
///
#include <string.h>

#include"string.h"

#include <iostream>
using std::cout;
using std::endl;

string::string()
	//	:_pstr(new char(NULL))
	:_pstr(new char(0))
{
}

string::string(const char *pstr)
	:_pstr(new char[strlen(pstr)+1]())
{
	strcpy(_pstr,pstr);
}

string::string(const string &rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]())
{
	strcpy(_pstr,rhs._pstr);
}

string & string:: operator=(const string &rhs)
{
	if(this != &rhs)
	{
		delete [] _pstr;
		_pstr=new char [strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
	}
	return *this;
}
string::~string()
{
	delete [] _pstr;
}

void string::print()
{
	cout<<_pstr<<endl;
}

