///
/// @file    point3d.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-15 15:39:12
///

#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix=0,int iy = 0)
			:_ix (ix),_iy(iy)
		{
			cout<<"Point (int ,int)"<<endl;
		}

		void print() const
		{
			cout<<"("<<_ix<<","<<_iy<<")"<<endl;
		}

		int getY() const
		{
			return _iy;
		}

	protected:
		int _ix;
		int getX() const
		{
			return _ix;
		}

	private:
		int _iy;
};


class Point3D
:protected  Point
{
	public:
		Point3D(int ix,int iy,int iz)
			: Point(ix,iy)
			  ,_iz(iz)
	{
		cout<<"Point3D(int, int ,int )"<<endl;
	}

		void display() const
		{
			cout<<"("<<_ix<<","<<getY()<<","<<_iz<<")"<<endl;
		}

	private:
		int _iz;
};


int main(void)
{
	Point pt(1,6);
//pt.print();
	
	Point3D p3(1,4,6);
	p3.display();
//	p3.print();

	return 0;
}
