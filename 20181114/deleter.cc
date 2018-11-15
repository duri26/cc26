 ///
 /// @file    deleter.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-14 20:17:31
 ///
#include <stdio.h>
#include <memory>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::string;

struct FileCloser
{
	void operator ()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout<<">>>fclose(fp) "<<endl;
		}
	}
};

void test0()
{
	unique_ptr<FILE,FileCloser> up(fopen("test.txt","w+"));

	string str("hello world");
	fwrite(str.c_str(),1,str.size(),up.get());
}


void test1()
{
	shared_ptr<FILE> sp(fopen("test.txt","a+"),FileCloser());
	string str("shared_ptr hello");
	fwrite(str.c_str(),1,str.size(),sp.get());
}

int main(void)
{
	test1();

	return 0;
}

