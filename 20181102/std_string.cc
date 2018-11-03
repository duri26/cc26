 ///
 /// @file    std_string.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-02 23:21:28
 ///
#include <stdio.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	cout<<"sizeof(string)="<<sizeof(string)<<endl;

	string s1="hello";
	string s2="hello";
	string s3=s1;


    printf("s1's address: %p\n", s1.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s3's address: %p\n", s3.c_str());

	s3[0] = 'X';
	printf("s1's address: %p\n", s1.c_str());
	printf("s2's address: %p\n", s2.c_str());
	printf("s3's address: %p\n", s3.c_str());
	cout << "s1 = " << s1 << endl;
	cout << "s3 = " << s3 << endl;
 
	return 0;
}
