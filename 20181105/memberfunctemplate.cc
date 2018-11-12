 ///
 /// @file    memberfunctemplate.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-05 23:48:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
	Point(int ix=0,int iy=0)
		:_ix(ix)
		 ,_iy(iy)
	{
		cout<<"Point ()"<<endl;
	}

	template <typename T>
		T typecast()
		{
			return (T) _ix*_iy;
		}
	private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt(3,3);
	double x=pt.typecast<double>();
	cout<<"x="<<x<<endl;
	return 0;
}
