///
/// @file    string.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-13 17:05:37
///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class string
{
	public:
		string()
		: _pstr(new char[1]())
	{
		cout<<"string ()"<<endl;
	}

	string (const char * pstr)
		: _pstr(new char [strlen(pstr)+1]())
	{
		strcpy(_pstr,pstr);
		cout<<"string (const *)"<<endl;
	}

	string (const string & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1]())
	{
		strcpy(_pstr,rhs._pstr);
		cout<<"string (const string &)"<<endl;
	}

	string & operator =(const string & rhs)
	{
		cout<<"string & operator =(cosnt string &)"<<endl;
		if(this != &rhs)
		{
			delete [] _pstr;

			_pstr = new char [strlen(rhs._pstr)+1]();
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}

	void print()
	{
		cout<<_pstr<<endl;
	}

	~string ()
	{
		if(_pstr)
		{
			delete [] _pstr;
		}
		cout<<"~string()"<<endl;
	}
	private:
	char * _pstr;
};



int main(void)
{
	string s1;
	cout << "1111" << endl;
	s1.print();
	cout << "222" << endl;
	string s2("hello");
	cout << "s2 = ";
	s2.print();
	cout << endl;

	string s3 = s2;
	cout << "s3 = ";
	s3.print();
	cout << endl;

	string s4 = "world";
	cout << "s4 = ";
	s4.print();

	string s5 = s1;
	s5.print();

	cout << "222" << endl;

	return 0;
}


