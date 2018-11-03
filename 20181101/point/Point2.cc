 ///
 /// @file    Point.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-01 23:14:38
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;


class Point;
class Line
{
	public:
		Line() 
		{
			cout<< "Line()"<<endl;
		}

		~Line()
		{
			cout<<" ~Line()"<<endl;
		}
 float distance (const Point & lhs,const Point & rhs);
};
		
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
		friend float Line:: distance(const Point & lhs ,const Point & rhs);
	private :
int _ix;
int _iy;
};

		

 float Line:: distance (const Point & lhs,const Point & rhs)
			{
				return sqrt(pow(lhs._ix -rhs._ix,2) + pow(lhs._iy -rhs._iy,2));

			}
int main(void )
{
Line();
	Point p1(1,3);
	Point p2(5,6);
p1.print();
cout<<"---->";
p2.print();

cout<<"距离"<<Line().distance(p1,p2)<<endl;//没刷新缓存区

return 0;
}

