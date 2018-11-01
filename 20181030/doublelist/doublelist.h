 ///
 /// @file    doublelist.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-31 14:52:03
 ///

#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

struct Node
{
	
	Node()
	:Node(0)
	{
	}

	Node(int e)
	:data(e)
	,pre(nullptr)
	,next(nullptr)
	{
	}

	int data;
	Node * pre;
	Node * next;
};

class List{
	public:
		List();
		~List();

		void push_back(int);
		void push_front(int);
		void pop_back();
		void pop_front();
		void insert(int, int idx);
		void erase(int element);
		void display () const;

		int size() const{ return _size;};
		bool empty() const{ return !_size;}
	private:
		Node * _head;
		Node * _tail;
		int _size;
};

#endif 
