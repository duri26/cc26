 ///
 /// @file    weak_ptr.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-14 21:03:39
 ///
#include <memory> 
#include <iostream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

int main(void)
{
	weak_ptr<int> wp;
	{
		shared_ptr<int>sp(new int(33));
		wp=sp;
		cout<<"sp's use_count = "<<sp.use_count()<<endl;

		cout<<"wp's expired = "<<wp.expired()<<endl;

		shared_ptr<int> sp2 =wp.lock();
		if(sp2)
		{
			cout<<"weak_ptr 提升成功"<<endl;
			cout<<*sp2<<endl;
			cout<<"sp2's use_count = "<<sp2.use_count()<<endl;
		}
		else
		{
			cout<<"weak_ptr提升失败"<<endl;
			cout<<*sp2<<endl<<endl;
		}
	}

	cout<<"wp's expired = "<<wp.expired()<<endl;
	shared_ptr<int> sp2 = wp.lock();
	
		if(sp2)
		{
			cout<<"weak_ptr 提升成功"<<endl;
			cout<<*sp2<<endl;
			cout<<"sp2's use_count = "<<sp2.use_count()<<endl;
		}
		else
		{
			cout<<"weak_ptr提升失败"<<endl;
			cout<<*sp2<<endl<<endl;
		}

		return 0;
}
