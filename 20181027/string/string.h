 ///
 /// @file    string.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-29 17:55:24
 ///

#ifndef __STRING_H__
#define __STRING_H__

class string
{
	public:
		string();
		string(const char *pstr);
		string(const string & rhs);
		string & operator=(const string &rhs);
		~string();

		void print();

	private:
		char * _pstr;
};

#endif
