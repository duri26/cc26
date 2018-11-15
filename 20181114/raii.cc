 ///
 /// @file    rall.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-14 19:46:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class RAII
{
	public:
		RAII(T * data)
			: _data(data)
		{}

		RAII(const RAII &) =delete;
		RAII & operator = (const RAII &) =delete;

		T * operator->()
		{
			return _data;
		}

		T & operator *()
		{
			return * _data;
		}

		T * get()
		{
			return _data;
		}

		void reset( T * data)
		{
			if(_data)
				delete _data;
			_data =data;
		}

		~RAII()
		{
			if(_data)
				delete _data;
		}

	private:
		T * _data;
};

class Point
{
	public:
		Point(int ix = 0,int iy = 0)
			: _ix(ix)
			  , _iy(iy)
	{
		cout<<"Point (int =0,int =0)"<<endl;
	}
		void print() const 
		{
			cout<<"("<<_ix<<","<<_iy<<")"<<endl;
			}

		~Point()
		{
			cout<<"~Point()"<<endl;
		}

		friend std::ostream & operator <<(std::ostream & os,const Point &rhs);
	private:
		int _ix;
		int _iy;
};

std::ostream & operator <<(std::ostream & os,const Point & rhs)
{
	os<<"("<<rhs._ix<<","<<rhs._iy<<")";
	return os;
}

int main(void)
{
	RAII<Point> p(new Point(1,3));
	p->print();
	(*p).print();
	cout<<*p<<endl;

	return 0;
}
