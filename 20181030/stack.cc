 ///
 /// @file    stack.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 19:28:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class stack
{
	public:
		stack(int size=10)
		:_size(size)
		 ,_top(-1)
		 ,_array(new int[_size]())
	{}

		~stack()
		{
			delete [] _array;
		}

		bool empty() const
		{
			return _top==-1;
		}

		bool full() const
		{
			return _top==_size -1;
		}

		void push (int value )
		{
			if(!full())
			{
				_array [++_top]=value;
			}
			else 
			{
				cout << "栈已满"<<endl;
			}

		}
void pop()
{
	if(!empty())
	{
		--_top;
	}
	else 
	{
		cout<<"栈已满！"<<endl;
	}
}

		int top()
		{
			return _array[_top];
		}

	private :
		int _size;
		int _top;
		int * _array;
};

int main(void )
{
	stack stack;
	cout<< "此时栈是否为空？"<<stack.empty()<<endl;
	stack.push(1);
	cout<< "此时栈是否为空？"<<stack.empty()<<endl;

	for(int idx=2;idx!=10;++idx)
	{
		stack.push(idx);
	}
	
	cout<< "此时栈是否已满？"<<stack.full()<<endl;

	while(!stack.empty())
	{
		cout<<stack.top()<<" ";
			stack.pop();
	}
	cout<<endl;
	cout<<"此时栈是否为空？"<<stack.empty()<<endl;

	return 0;
}
