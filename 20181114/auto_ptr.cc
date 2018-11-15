 ///
 /// @file    auto_ptr.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-14 21:39:29
 ///
#include <memory> 
#include <iostream>
using std::cout;
using std::endl;
using std::auto_ptr;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Pint(int=0,int=0)" << endl;	}

	void print() const 
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{	cout << "~Point()" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

int main(void)
{
	Point * pt =new Point(2,6);
	auto_ptr<Point> ap(pt);
	cout<<"ap's get() = "<<ap.get()<<endl;
	cout<<"pt = "<<pt<<endl;

	ap->print();
	(*ap).print();
	cout<<*ap<<endl;

	auto_ptr<Point> ap2(ap);

	cout<<"ap2's get()= "<<ap2.get()<<endl;
	cout<<"pt = "<<pt<<endl;
	ap2->print();
	(*ap2).print();

	cout<<endl;
	cout<<"ap's get() = "<<ap.get()<<endl;
	ap->print();

	return 0;
}
