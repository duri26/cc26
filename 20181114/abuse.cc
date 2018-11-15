 ///
 /// @file    abuse.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-14 20:33:03
 ///
#include <memory> 
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;

class Point
:public std::enable_shared_from_this<Point>
{
	public:
		Point(int ix=0,int iy =0)
			:_ix(ix),_iy(iy)
		{
			cout<<"point (int =0,int =0)"<<endl;
		}

		void print() const
		{
			cout<<"("<<_ix<<","<<_iy<<")"<<endl;
		}

		shared_ptr<Point> addPoint(const Point & rhs)
		{
			_ix += rhs._ix;
			_iy += rhs._iy;

			return shared_from_this();
		}

		~Point()
		{
			cout<<"~point()"<<endl;
		}

		friend std::ostream & operator<<(std::ostream & os,const Point & rhs);

	private:
		int _ix;
		int _iy;
};

std::ostream & operator <<(std::ostream & os,const Point & rhs)
{
	os<<"("<<rhs._ix<<","<<rhs._iy<<")";
	return os;
}

void test0()
{
	Point * pt = new Point(1,3);
	unique_ptr<Point> up1(pt);
	unique_ptr<Point> up2(pt);
	up1->print();
	up2->print();

}


void test2()
{
	shared_ptr<Point> sp1(new Point(1, 2));	
	shared_ptr<Point> sp2(new Point(3, 4));
	
	shared_ptr<Point> sp3(sp1->addPoint(*sp2));
	cout << "*sp3 = " << *sp3 << endl;
	
}
void test3()
{
	shared_ptr<Point> sp1(new Point(1,3));
	shared_ptr<Point> sp2(new Point(2,4));

	sp1.reset(sp2.get());
}
int main(void)
{
	test2();

	return 0;
}
