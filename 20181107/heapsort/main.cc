 ///
 /// @file    main.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-09 21:19:49
 ///
#include "heapsort.h"

#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int ix = 0, int iy = 0)
		:_ix(ix)
		,_iy(iy){
		}

		double distance() const{
			return sqrt(_ix * _ix + _iy * _iy);
		}

		friend ostream & operator<<(ostream & os, const Point & rhs);
	private:
		int _ix;
		int _iy;
};

ostream & operator<<(ostream & os, const Point & rhs){
	os << "(" << rhs._ix
	   << "," << rhs._iy << ")";

	return os;
}
bool operator>(const Point & lhs, const Point & rhs){
	return lhs.distance() > rhs.distance();
}

int test0(){
	int arr[10] = {1, 3, 5, 7, 9, 8, 4, 2, 6, 10};

	//int数组按升序排列
	HeapSort<int> ihs(arr, 10);
	ihs.sort();

	for (int i = 0; i < 10; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

int test1(){
	Point arr[] = {
		{1, 2},
		{3, 4},
		{-1, -1},
		{2, 6},
		{-2, 0},
		{3, 4},
		{3, 7},
		{-6, -4}
	};

	//Point类型数组按降序排列(重载>号)
	HeapSort<Point, std::greater<Point>> phs(arr, 8);
	phs.sort();

	for (int i = 0; i < 8; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

struct Compare{
	bool operator()(const Point & lhs, const Point & rhs){
		return lhs.distance() < rhs.distance();
	}
};

int test2(){
	Point arr[] = {
		{1, 2},
		{3, 4},
		{-1, -1},
		{2, 6},
		{-2, 0},
		{3, 4},
		{3, 7},
		{-6, -4}
	};

	//Point数组类型按升序排列(函数对象)
	HeapSort<Point, Compare> phs(arr, 8);
	phs.sort();

	for (int i = 0; i < 8; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

int main(){
	//test0();
	//test1();
	test2();

	return 0;
}

