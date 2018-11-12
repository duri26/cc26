 ///
 /// @file    stacktemplate.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-06 17:33:59
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T,int kSize =10>
class Stack
{
	public:
		Stack()
			:_top(-1)
			 ,_array(new T[kSize]())
	{}

		~Stack()
		{
			delete [] _array;
		}

		bool empty()const;
		bool full()const;
		void push(const T & t);
		void pop();
		T top();

	private:
		int _top;
		T * _array;
};

template <typename T,int kSize>
bool Stack<T,kSize>::empty() const
{
	return _top==-1;
}

template <typename T,int kSize>
bool Stack<T,kSize>::full()const
{
	return _top==kSize -1;
}

template  <typename T,int kSize>
void Stack<T,kSize>::push(const T & t)
{
	if(!full())
	{
		_array[++_top]=t;
	}
	else
	{
		cout<<"stack is full,cannot push data any more"<<endl;
	}
}

template <typename T,int kSize >
void Stack<T,kSize>::pop()
{
	if(!empty())
	{
		--_top;
	}
	else
	{
		cout<<"stack is empty,no more data"<<endl;
	}
}

template <typename T,int kSize>
T Stack<T,kSize>::top()
{
	return _array[_top];
}

int test0(void)
{
	Stack<int>stack;
	cout<<"此时栈是否为空？"<<stack.empty()<<endl;
	stack.push(1);
	cout<<"此时栈是否为空？"<<stack.empty()<<endl;

for(int idx=2;idx<12;++idx)
{
	stack.push(idx);
}

cout<<"此时栈是否已满？"<<stack.full()<<endl;

while(!stack.empty())
{
	cout<<stack.top()<<"  ";
	stack.pop();
}
cout<<endl;
}
int test1(void)
{
	Stack<string> stack;
	cout << "此时栈中是否为空？" << stack.empty() << endl;
	stack.push("aaa");
	cout << "此时栈中是否为空？" << stack.empty() << endl;

	for(int idx = 1; idx != 11; ++idx)
	{
		stack.push(string(2, 'a' + idx));
	}

	cout << "此时栈中是否已满？" << stack.full() << endl;

	while(!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	return 0;
}

int main(void)
{
	test1();

	return 0;
}
