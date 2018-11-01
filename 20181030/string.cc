 ///
 /// @file    string.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 17:58:21
 ///
#include <string.h>


#include <iostream>
using std::cout;
using std::endl;

class String
{
	public:
		String()
			: _pstr(new char[1]())
		{
			cout<< "string()"<<endl;
		}

		String(const char *pstr)
		:_pstr(new char[strlen(pstr)+1]())
		{
			strcpy(_pstr,pstr);
			cout<<"string (const char *pstr)"<<endl;
		}

		String(const String & rhs)
		:_pstr(new char [strlen(rhs._pstr)+1]())
		{
strcpy(_pstr,rhs._pstr);
cout << "string (const string & rhs)"<<endl;
		}

		String & operator =(const String & rhs)
		{
			cout <<"string & operator =(const String & rhs)"<<endl;
			if(this !=&rhs)
			{
				delete [] _pstr;

				_pstr =new char [strlen(rhs._pstr)+1]();
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		}

		void print()
		{
			cout<<_pstr<<endl;
		}

		~String()
		{
			if(_pstr)
			{
				delete [] _pstr;
			}
			cout <<  "~String ()"<<endl;
		}

	private:
		char *_pstr;
};


int main(void)
{
	String s1;
	cout << "1111" << endl;
	s1.print();
	cout << "222" << endl;
	String s2("hello");
	cout << "s2 = ";
	s2.print();
	cout << endl;

	String s3 = s2;
	cout << "s3 = ";
	s3.print();
	cout << endl;

	String s4 = "world";
	cout << "s4 = ";
	s4.print();

	String s5 = s1;
	s5.print();

	cout << "222" << endl;

	return 0;
}

