///
/// @file    cow_string.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-04 23:06:36
///
#include <stdio.h> 
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class String
{

	class CharProxy
	{
		public:
			CharProxy (String &self, int idx)
			: _self(self)
			  ,_idx(idx)
		{
		cout<<"CharProxy()"<<endl;
		}
			char & operator=(char ch);

			operator char()
			{
				cout<<"operator char()"<<endl;
				return _self._pstr[_idx];
			}

		private :
			String & _self;
			int _idx;
	};

	friend std::ostream & operator <<(std::ostream & os,const String & rhs);

	public:
		String()
			: _pstr(new char[5]()+4)
		{
			initRefcount();
		}

		String(const char * pstr)
			:_pstr(new char [strlen(pstr)+5]()+4)
		{
			strcpy(_pstr,pstr);
			initRefcount();
		}

		String(const String & rhs)
			:_pstr(rhs._pstr)
		{
			increaseRefcount();
		}

		~String()
		{
			release();
		}

		void release()
		{
			decreaseRefcount();
			if(0==refcount() )
			{
				delete [] (_pstr -4);
				cout <<">>> delete data "<<endl;
			}
		}

		String & operator=(const String & rhs)
		{
			cout<<"String & operator =(const String &)"<<endl;
			if(this != &rhs)
			{
				release();
				_pstr=rhs._pstr;
				increaseRefcount();
			}
			return *this;
		}

		friend std::ostream & operator<<(std::ostream &os,const String &rhs);

		const char * c_str() const
		{
			return _pstr;
		}

		int refcount() const
		{
			return * reinterpret_cast<int*>(_pstr - 4);
		}

		int size() const
		{
			return strlen (_pstr);
		}


#if 0
		char & operator [](int idx)
		{
			static char nullchar = '\0';
			if(idx<0||idx>=size())
			{
				cout<<">>>idx 越界 "<<endl;
				return nullchar;
			}
			else 
			{
				if (refcount() > 1)
				{
					decreaseRefcount();
					char * ptmp =new char [size() +5]()+4;
					strcpy(ptmp,_pstr);
					_pstr=ptmp;
					initRefcount();
				}
				return _pstr[idx];
			}
		}
#endif

CharProxy operator [](int idx)
{
	return CharProxy(*this ,idx);
}
	private:
		void initRefcount()
		{
			*reinterpret_cast <int *>(_pstr -4)=1;
		}

		void increaseRefcount()
		{
			++*reinterpret_cast<int *>(_pstr -4);
		}

		void decreaseRefcount()
		{
			--*reinterpret_cast<int*> (_pstr -4);
		}

	private :
		char * _pstr;
};

std::ostream & operator << (std::ostream &os,const String & rhs)
{
cout<<"operator << (os,rhs)"<<endl;
	os <<rhs._pstr;
	return os;
}

char & String ::CharProxy::operator =(char ch)
{

	cout<<"operator = (char ch)"<<endl;
	static char nullchar = '\0';
	if(_idx < 0 || _idx >= _self.size())
	{
		cout << ">>> idx 越界" << endl;
		return nullchar;
	} else {
		if(_self.refcount() > 1) {
			_self.decreaseRefcount();	
			char * ptmp = new char[_self.size() + 5]() + 4;
			strcpy(ptmp, _self._pstr);
			_self._pstr = ptmp;
			_self.initRefcount();
		}
		_self._pstr[_idx] = ch;
		return _self._pstr[_idx];
	}
}

int main(void )
{
	String s1="hello word";
	String s2=s1;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	printf("s1's address %p\n",s1.c_str());
	printf("s2's address %p\n",s2.c_str());
	cout<<"s1' refcount ="<<s1.refcount()<<endl;
	cout<<"s2' refcount ="<<s2.refcount()<<endl<<endl;




	String s3 = "wangdao";
	String s4(s3);
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	s2 = s3;
	cout << "执行赋值操作:" << endl;
	cout << "s2 = " << s2 << endl;
	printf("s3's address: %p\n", s3.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s4's address: %p\n", s4.c_str());

	cout << "s3' refcount = " << s3.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s4' refcount = " << s4.refcount() << endl << endl;




	s3[0] = 'A';
	cout << "执行写操作:" << endl;

	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	printf("s3's address: %p\n", s3.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s4's address: %p\n", s4.c_str());
	cout << "s3' refcount = " << s3.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s4' refcount = " << s4.refcount() << endl << endl;

	cout << "执行读操作:" << endl;
	cout << "s2[0] = " << s2[0] << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	printf("s3's address: %p\n", s3.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s4's address: %p\n", s4.c_str());
	cout << "s3' refcount = " << s3.refcount() << endl;
	cout << "s2' refcount = " << s2.refcount() << endl;
	cout << "s4' refcount = " << s4.refcount() << endl << endl;

	return 0;
}


