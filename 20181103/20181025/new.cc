 ///
 /// @file    new.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-03 15:00:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
int * p1=new int(1);
cout<<"new "<< *p1<< "sizeof(p1)="<<sizeof(p1)<<"----"<<"sizeof(*p1)="<<sizeof(*p1)<<endl;

int *p2=new int [6]();

for(int i=0;i<6;++i)
{
	p2[i]=i;
}

cout<<"*p2   "<<*p2<<"p2[3]  "<<p2[3]<<endl;
cout<<"sizeof(p2)="<<sizeof(p2)<<"  sizeof(*p2)=  "<<sizeof(*p2)<<endl;

delete [] p2;
return 0;
}
