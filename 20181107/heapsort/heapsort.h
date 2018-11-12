 ///
 /// @file    heapsort.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-09 21:01:03
 ///
#include <math.h>

#include <functional>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template <typename T ,typename Compare = std::less<T>>
class HeapSort
{
	public:
		HeapSort(T * arr, int size);
		void sort();

		private:
		void heapAdjust(int ,int);
		void swap(T & a, T & b);

		private:
		T * _arr;
		int _size;
		Compare _compare;
};

template <typename T , typename Compare>
HeapSort <T ,Compare>::HeapSort (T * arr, int size)
: _arr(arr)
	, _size(size)
,_compare(Compare())
{}

template <typename T, typename Compare>
void HeapSort <T ,Compare>::swap(T & a,T & b)
{
	T tmp =a;
	a = b;
	b = tmp;
}

template <typename T , typename Compare>
void HeapSort<T , Compare>::heapAdjust(int first ,int size)
{
	int dad = first,son = dad * 2 +1;

	while(son < size)
	{
		if((son + 1)< size && _compare(_arr[son],_arr[son+1]))
		{
			++son;
		}

		if(_compare(_arr[dad],_arr[son]))
		{
			swap(_arr[dad],_arr[son]);
			dad = son;
			son = son * 2 +1;
		}
		else 
		{
			break;
		}

	}
}

template <typename T ,typename Compare>
void HeapSort <T ,Compare>::sort()
{
	for(int i =(_size -1) / 2; i >= 0; --i)
	{
		heapAdjust(i, _size);
		}
	for(int i=_size -1; i!=0; --i)
	{
		swap(_arr[0],_arr[i]);
		heapAdjust(0,i);
	}
}


