///
/// @file    string.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-02 19:59:21
///
#include <string.h>


#include <limits>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	public:
		String()
			:_pstr(new char[1]())
		{
			cout<<"String()"<<endl;
		}

		String(const char * pstr)
			:_pstr(new char [strlen(pstr)+1]())
		{
			strcpy(_pstr,pstr);
			cout<<"String(const char *)"<<endl;
		}

		String (const String & rhs)
			: _pstr(new char [rhs.size()+1]())
		{ 
			strcpy(_pstr,rhs._pstr);
			cout<<"String(const String &)"<<endl;
		}

		~String()
		{
			if(_pstr)
			{
				delete [] _pstr;
			}
			cout<<"~String()"<<endl;
		}




		String &operator=(const String & rhs)
		{
			return *this =rhs.c_str();
		}

		String &operator=(const char *pstr)
		{
			//if(this != pstr) 错误，不同类型
			if(strcmp(_pstr,pstr))
			{
				delete [] _pstr;
				_pstr =new char [strlen(pstr)+1]();
				strcpy(_pstr,pstr);

			}
			return * this;
		}




		String &operator+=(const String &rhs)
		{
			return *this += rhs.c_str();
		}
		String &operator+=(const char *pstr)
		{
			char *t =_pstr;
			_pstr=new char [size ()+strlen(pstr)+1]();
			strcpy(_pstr,t);
			strcat(_pstr,pstr);
			delete [] t;
			return *this;
		}



		char &operator[](std::size_t index)
		{
			return _pstr[index];
		}
		const char &operator[](std::size_t index) const
		{
			return _pstr[index];
		}




		//  大小与字符 
		std::size_t size() const
		{
			return strlen(_pstr);
		}
		const	 char* c_str() const
		{
			return _pstr;
		}
		friend bool operator==(const String &, const String &);
		friend bool operator!=(const String &, const String &);

		friend bool operator<(const String &, const String &);
		friend bool operator>(const String &, const String &);
		friend bool operator<=(const String &, const String &);
		friend bool operator>=(const String &, const String &);

		friend std::ostream &operator<<(std::ostream &os, const String &s);
		friend std::istream &operator>>(std::istream &is, String &s);
	private:
		char * _pstr;
};

bool  operator==(const String &rhs, const String &lhs)
{
	return  ! strcmp(rhs.c_str(),lhs.c_str());
}

bool operator!=(const String &rhs, const String &lhs)
{
	return strcmp(rhs.c_str(),lhs.c_str());
}

bool operator<(const String &rhs, const String &lhs)
{
	return strcmp(rhs.c_str(),lhs.c_str())<0;
}

bool operator>(const String &rhs, const String &lhs)
{
	return strcmp(rhs.c_str(),lhs.c_str())>0;
}

bool operator<=(const String &rhs, const String &lhs)
{
	return strcmp(rhs.c_str(),lhs.c_str())<=0;
}

bool operator>=(const String &rhs, const String &lhs)
{
	return strcmp(rhs.c_str(),lhs.c_str())>=0;
}


std::ostream &operator<<(std::ostream &os, const String &s)
{
	os<<s._pstr;
	return os;
}

std::istream & operator>>(std::istream & is, String & rhs)
{

	char ptmp[1024] = {0}, *p = ptmp;
	is.get(ptmp, 1024);

	if (is.bad()){
		std::cout << "istream has corrupted!" << std::endl;
		return is;
	}
	else if (!is.good()){
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	while (*p && *p != ' ')
	{
		p++;
	}
	*p = '\0';

	rhs = ptmp;
	return is;
}
//std::istream &operator>>(std::istream &is, String &s)
//{
//	char a[4096]={0},*p=a;
//	is.get(a,4096);
//
//	while(!is.eof())
//	{
//		if(is.bad())
//		{
//			cout<<"istream has corrupted"<<endl;
//			return is;
//		}
//		else if(is.fail())
//		{
//			is.clear();
//			is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//		}
//	}
//		while (*p && *p != ' ')
//		{
//			p++;
//		}
//		*p = '\0';
//
//		s =a ;
//		return is;
//	
//}
String operator+(const String &rhs, const String &lhs)
{
	String t=rhs;
	t += lhs;
	return t;
}

String operator+(const String &rhs, const char *ptrs)
{
char *	t= new char[rhs.size()+strlen(ptrs)+1]();
::	strcpy(t,rhs.c_str());
	strcat(t,ptrs);
	return t;
}
//String operator+(const char *, const String &);
int main(void)
{
	String s1;
	String s2 = "helloworld";

	String s3(" wd ");
	String s4 = (s3);

	cout << "s2 = " << s2 << endl
		<< "s3 = " << s3 << endl
		<<	"s4 = " << s4 << endl;
	cout << "s2 + s3 = " << s2 + s3 << endl;

	String s5 = s2 + s3;
	s5 += s3;
	cout << "s5 = " << s5 << endl;

	cout << "s2 == s3 ? " << (s2 == s3) << endl;
	cout << "s2 > s3 ? " << (s2 > s3) << endl;
	cout << "s2 <= s3 ? " << (s2 <= s3) << endl;

	cout << "s2 + world = " << s2 + " world" << "  " << "world" + s2 << endl;

	String s6;
	s6 = s2;
	cout << "s6 = " << s6 << endl;

	String s7;
	std::cin >> s7;
	cout << "s7 = " << s7 << "\ns7[3] = " << s7[0] << endl;
	return 0;
}

