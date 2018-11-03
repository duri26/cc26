 ///
 /// @file    chararray.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-02 17:14:30
 ///
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
	public:
		CharArray(int size)
			:_size(size)
			 ,_pdata(new char[_size]())
	{}

		char & operator [] (int idx)
		{
			cout<< "char & operator [] (int )"<<idx<<endl;
			static char nullchar ='\0';

			if(idx<0||idx>=_size)
			{
				cout<<"idx 越界 "<<endl;
				return nullchar;
			}
			else 
			{
				return _pdata[idx];
			}
		}
private:
		int _size;
		char * _pdata;
};

int main(void)
{
	const char * pstr="hello word";
	int len=strlen(pstr)+1;
	CharArray ca(len);

	for(int idx=0;idx != len;++idx)
	{
ca [idx]=		pstr[idx];
	}

	cout<<"--------------"<<endl<<endl;
	for(int idx=0;idx != len;++idx)
	{
		cout<<ca[idx];
	}
cout<<endl;

return 0;
}

