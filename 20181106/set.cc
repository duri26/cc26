 ///
 /// @file    set.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-06 14:56:56
 ///
#include <math.h>

#include <set>
#include <iostream>
using std::cout;
using std::endl;
using std::set;

template <typename Container>
void display(const Container & c)
{
	for(auto & elem:c)
	{
		cout<<elem <<"  ";
	}
	cout<<endl;
}

void test0()
{
	int arr[10]={1,1,2,11,2,3,3,3,4};
	set<int,std::greater<int>>numbers(arr,arr+10);
	//set<int>numbers(arr,arr+10);默认的升序；
	display(numbers);
	
	size_t cnt =numbers.count(0);
	cout<<"cnt="<<cnt<<endl;
	cnt =numbers.count(11);
	cout<<"cnt="<<cnt<<endl;

	set<int>::iterator it=numbers.find(11);
	cout<<"*it="<<*it<<endl;
}

class Point
{
	public:
		Point(int ix=0,int iy=0)
			:_ix(ix)
			 ,_iy(iy)
	{
		cout<<"Poin()"<<endl;
	}

		void print()const
		{
			cout<<"("<<_ix<<","<<_iy<<")"<<endl;
		}

		float getDistance()const
		{
			return sqrt(_ix * _ix + _iy * _iy);
		}

		friend std::ostream & operator<<(std::ostream & os,const Point & rhs);

	private:
		int _ix;
		int _iy;
};

std::ostream & operator <<(std::ostream & os,const Point & rhs)
{
	os <<"("<<rhs._ix<<","<<rhs._iy<<")";
	return os;
}
#if 0
bool operator <(const Point &lhs,const Point & rhs)
	{
		return lhs.getDistance()>rhs.getDistance();
	}
#endif 
struct Compare
{
	bool operator () (const Point &lhs,const Point &rhs)
	{
		return lhs.getDistance()<rhs.getDistance();
	}
};

void test1()
{
	set<Point,Compare>points
	{
		Point(1,1),Point(1,2),Point(3,3)
	};
display(points);
}


int main(void)
{
	test1();

	return 0;
}
