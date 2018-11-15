 ///
 /// @file    string.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-14 17:01:01
 ///
#include <string.h>

#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;


class String
{
	public:
		String()
			: _pstr(new char[1]())
		{}

		String(const char * pstr)
			: _pstr(new char [strlen(pstr)+1]())
		{
			strcpy(_pstr,pstr);
			cout<<"String (const char *)"<<endl;
		}

		String(const String & rhs)
		: _pstr(new char[strlen(rhs._pstr)+1]())
		{
			strcpy(_pstr,rhs._pstr);
			cout<<"String(const String &)"<<endl;
		}

		String & operator=(const String & rhs)
		{
			cout<<"String operator =(const String &)"<<endl;
			if(this != &rhs)
			{
				delete [] _pstr;
				_pstr = new char [strlen(rhs._pstr)+1]();
				strcpy(_pstr,rhs._pstr);
			}
			return * this;
		}


		String (String && rhs)
			: _pstr(rhs._pstr)
		{
			rhs._pstr =NULL;
			cout<<"String (String &&)"<<endl;
		}

		String & operator =(String && rhs)
		{
			cout<< "String & operator =(String &&)"<<endl;
			if(this != &rhs)
			{
				delete [] _pstr;
				_pstr=rhs._pstr;
				rhs._pstr =NULL;
			}
			return * this;
		}

		~String ()
		{
			delete [] _pstr;
			cout<<"~String ()"<<endl;
		}

		friend std::ostream & operator <<(std::ostream &os,const String & rhs);

	private:
		char * _pstr;
};

String str("hello,word");

String && func()
{
	return std::move(str);
}

std::ostream & operator <<(std::ostream & os,const String & rhs)
{
	os <<rhs._pstr;
	return os;
}


int test0()
{
cout<<"test0()  "<<endl;
	
	vector<String> vec;
	vec.push_back("hello word pushback");

	String  s1("hello");
	String  s2("shenzhen");
cout<<"s1 = world "<<endl;
	s1 = "world";
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2 = "<<s2<<endl;

	s2 = std::move(s1);
	cout<<"执行std::move()之后:   "<<endl;
	
	cout<<"s2 = "<<s2<<endl;
	cout<<"s1 = "<<s1<<endl;

	return 0;
}

void test1()
{
	int a = 1;
   int b = 3;
   cout<<"a = "<<a <<endl;
   cout<<"b = "<<b <<endl;

   b =std::move(a);  //对内置类型不太管用 a 还可以使

   cout<<"a = "<<a <<endl;
   cout<<"b = "<<b <<endl;
}


int main(void)
{

	test1();

	return 0;
}
