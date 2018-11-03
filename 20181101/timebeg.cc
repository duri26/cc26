 ///
 /// @file    timebeg.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-01 10:41:03
 ///
#include <time.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;


int main(){
		time_t beg=::time(NULL);
::sleep(3);
		time_t end=::time(NULL);
time_t t=::time(&t);
		cout <<end-beg<<endl;
		cout <<beg-end<<endl;
cout<<"beg:   "<<beg<<endl;
cout<<"end:   "<<end<<endl;
sleep(5);
cout << t<<endl;
		return 0;
		}
