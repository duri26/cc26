 ///
 /// @file    circleReference2.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-14 21:24:05
 ///
#include <memory> 
#include <iostream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child;

class Parent
{
	public:
		Parent()
		{
			cout<<"Parent()"<<endl;
		}
		~Parent()
		{
			cout<<"~Parent()"<<endl;
		}

		shared_ptr<Child> _pChild;
};

class Child
{
	public:
		Child()
		{
			cout<<"Child()"<<endl;
		}
		~Child()
		{
			cout<<"~Child()"<<endl;
		}

		weak_ptr<Parent> _pParent;
};

int main(void)
{
	shared_ptr<Parent> pParent(new Parent);
	shared_ptr<Child> pChild(new Child);

	pParent->_pChild =pChild;
	pChild->_pParent=pParent;

	return 0;
}
