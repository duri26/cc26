 ///
 /// @file    singletong.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-05 23:33:22
 ///
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

/* 实现一个模板形式的单例类，要求对于任意类型的类经过Singleton的处理之后，
  　都能获取一个单例对象，并且可以传递任意参数

  */

template <typename T>
class Singletong
{
	public:
		template <typename ...Args>
			static T * getInstance(const Args & ...args)
			{
				if(!_pInstance)
				{
					_pInstance = new T(args...);
					atexit(destory);
				}
				return _pInstance;
			}

		static void destory()
		{
			delete _pInstance;
		}

	private:
		Singletong()
		{
			cout<<"Singletong()"<<endl;
		}
		~Singletong()
		{
			cout<<"~Singletong()"<<endl;
		}

		static T * _pInstance;
};

template <typename T>
T * Singletong<T>::_pInstance;

class Computer
{
	public:
		Computer(const char *name,double price)
		:_name(new char [strlen(name)+1]())
		 ,_price(price)
	{
		strcpy(_name,name);
	}
		~Computer()
		{
			delete [] _name;
		}

		friend ostream & operator <<(ostream & ,const Computer &);

	private :
		char * _name;
		double _price;
};

ostream & operator<<(ostream & os,const Computer & rhs)
{
	os <<"品牌:   "<<rhs._name<<"价格:  "<<rhs._price<<endl;

	return os;
}

class Point
{
	public:
		Point (int ix=0,int iy=0)
		:_ix(ix)
		 ,_iy(iy)
	{}

	friend ostream & operator <<(ostream &,const Point &);

	private:
	int _ix;
	int _iy;
};

ostream & operator <<(ostream & os ,const Point & rhs)
{
	os << "("<<rhs._ix<<","<<rhs._iy<<")";

	return os;
}



void test()
{
	Computer * p1 =Singletong<Computer>::getInstance("sony",8999);

	Computer * p2 =Singletong<Computer>::getInstance("sony",8999);
cout<<"p1= "<<p1<<"  "<<*p1<<endl;
cout<<"p2= "<<p2<<"  "<<*p2<<endl;
}

void test1()
{
	Point * d1=Singletong<Point>::getInstance(2,3);
	Point * d2=Singletong<Point>::getInstance(2,3);

	cout<<"d1 ="<<d1<<"  "<<*d1<<endl;
	cout<<"d2 ="<<d2<<"  "<<*d2<<endl;
}


void test2()
{
	double * d1=Singletong<double>::getInstance(2.39999);
	double * d2=Singletong<double>::getInstance(2.39999);

	cout<<"d1 ="<<d1<<"  "<<*d1<<endl;
	cout<<"d2 ="<<d2<<"  "<<*d2<<endl;
}

int main(void)
{
	test();
test1();
test2();
	return 0;
}
