 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-05 23:32:34
 ///
#include <string> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T,int kSize=10>
class  Queue
{
	public:
		Queue ()
			:_size(kSize)
			 ,_array(new T[_size]())
			 ,_head(0)
			 ,_tail(0)
	{}

		~Queue()
		{
			delete [] _array;
		}

		bool empty() const
		{
			return _head ==_tail;
		}

		bool full() const
		{
			return _head ==(_tail +1) % _size;
		}

		void push(const T & number)
		{
			if(!full())
			{
				_array[_tail++]=number;
				_tail %= _size;
			}
			else
			{
				cout<<"队列已满"<<endl;
			}
		}

		void pop()
		{
			if(!empty())
			{
				++_head;
				_head %= _size;
			}
			else
			{
				cout<<"队列已空"<<endl;
			}
		}

		T front()
		{
			return _array[_head];
		}

		T back()
		{
			return _array[(_tail -1 + _size)% _size];
		}

	private :
		int _size;
		T * _array;
		int _head;
		int _tail;
};


int main(void)
{
	Queue<string> que;
	cout << "此时队列是否为空?" << que.empty() << endl;
	que.push("aaa");
	cout << "此时队列是否为空?" << que.empty() << endl;

	for(int idx = 2; idx != 12; ++idx) {
		que.push(string(2,'a'+idx));
	}
	cout << "此时队列是否已满?" << que.full() << endl;

	cout << "队列头部的元素是:" << que.front() << endl;
	cout << "队列尾部的元素是:" << que.back() << endl;
	que.pop();
	que.push("z");
	cout << endl << "元素出队入队之后: " <<endl;
	cout << "队列头部的元素是:" << que.front() << endl;
	cout << "队列尾部的元素是:" << que.back() << endl;

	while(!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
	cout << "此时队列是否为空?" << que.empty() << endl;
	return 0;
}

