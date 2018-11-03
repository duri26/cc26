 ///
 /// @file    Point.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-01 23:14:38
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix=0,int iy=0)
		: _ix (ix)
		  ,_iy(iy)
	{
		cout<< " point (int =0,int =0)"<<endl;
	}

		void print() const
		{
			cout<<"("<<_ix<<","<<_iy<<")";
		}
friend float distance (const Point & lhs,const Point & rhs);
	private :
int _ix;
int _iy;
};

		 float distance (const Point & lhs,const Point & rhs)
			{
				return sqrt(pow(lhs._ix -rhs._ix,2) + pow(lhs._iy -rhs._iy,2));

			}
int main(void )
{

	Point p1(1,3);
	Point p2(5,6);
p1.print();
cout<<"---->";
p2.print();

cout<<"距离"<<distance(p1,p2)<<endl;

return 0;
}

