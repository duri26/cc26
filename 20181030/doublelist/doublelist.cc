///
/// @file    doublelist.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-10-31 14:55:50
///
#include "doublelist.h"

#include <iostream>
using std::cout;
using std::endl;

List::List()
	:_head(nullptr)
	,_tail(NULL)
	 ,_size(0)
{
}

List::~List()
{
	Node * ptmp;
	while(_head)
	{
		ptmp = _head;
		_head = _head->next;
		delete ptmp;
	}
}


void List::push_back(int element)
{
	Node * pinsert = new Node(element);

	if (empty())
	{
		_head = _tail = pinsert;
	}
	else
	{
		pinsert->pre = _tail;
		_tail->next = pinsert;
		_tail = pinsert;
	}
	_size ++;
}

void List::push_front(int element)
{
	Node * pinsert = new Node(element);

	if (empty())
	{
		_head = _tail = pinsert;
	}
	else
	{
		pinsert->next = _head;
		_head->pre = pinsert;
		_head = pinsert;
	}
	_size ++;
}

void List::pop_back()
{
	if (!empty())
	{
		Node * ptmp = _tail;
		_tail = _tail->pre;
		delete ptmp;
		if (_tail)
		{
			_tail->next = nullptr;
		}

		_size --;
	}
}

void List::pop_front()
{
	if (!empty())
	{
		Node * ptmp = _head;
		_head = _head->next;
		delete ptmp;
		if (_head) 
		{
			_head->pre = nullptr;
		}

		_size --;
	}
}

void List::insert(int element=0, int idx=0)
{
	if (idx > _size)
	{
		return;
	}
	else if (idx == 0)
	{
		push_front(element);
	}

	else if(idx == _size)
	{
		push_back(element);
	}

	else{
		Node * pinsert = new Node(element);

		Node * pcur = _head;
		while (idx > 0)
		{
			pcur = pcur->next;
			idx --;
		}

		pcur->pre->next = pinsert;
		pinsert->pre = pcur->pre;

		pinsert->next = pcur; 
		pcur->pre = pinsert;

		_size ++;
	}
}

void List::erase(int element)
{
	Node * pcur = _head, * ptmp;
	while (pcur){
		if (pcur->data == element)
		{
			if (pcur == _head)
			{
				pcur = pcur->next;
				pop_front();
			}
			else if (pcur == _tail)
			{
				pop_back();
				pcur = nullptr;
			}
			else 
			{
				ptmp = pcur->next;
				pcur->pre->next = pcur->next;
				pcur->next->pre = pcur->pre;
				delete pcur;
				pcur = ptmp;
				_size --;
			}
		}
		else
		{
			pcur = pcur->next;
		}
	}
}

void List::display () const
{
	Node * pcur = _head;
	while (pcur != _tail)
	{
		cout << pcur->data << "->";
		pcur = pcur->next;
	}
	if (pcur)
	{
		cout << pcur->data << endl;
	}
}

