 ///
 /// @file    1.c
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 10:50:42
 ///
 
//#include <iostream>
//using std::cout;
//using std::endl;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[100]="hello world";
	char  *p=(char*)malloc(sizeof(int)*10);
		strcpy(p,"hello world");
	char *q=p;
	printf("sizeof: a:%lu ,p: %lu,q:%lu\n",sizeof(a),sizeof(p),sizeof(q));//q,p,的空间都是8，是64位的地址字节为8，只是求得了地址的空间，不是申请的堆空间
	printf("strlen: a:%lu ,p: %lu,q:%lu\n",strlen(a),strlen(p),strlen(q));//q,p,的空间都是8，是64位的地址字节为8，只是求得了地址的空间，不是申请的堆空间
	return 0;
}
