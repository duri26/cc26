 ///
 /// @file    line.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-07 23:10:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class point
{
	public:
		point()
		:_ix(0)
		 ,_iy(0)
	{
		cout<<"point()"<<endl;
	}

	point(int ix,int iy)
	:_ix(ix)
	,_iy(iy)
	 {
		 cout<<"point(int ,int)"<<endl;
	 }

	void print()
	{
		cout<<"("<<this->_ix<<","<<this->_iy<<")";
	}

	~point()
	{
		cout<<"~point()"<<endl;
	}

	private:
	int _ix;
	int _iy;
};

class line
{
	public:
		line(int x1,int y1,int x2,int y2)
		: _pt1(x1,y1)
		  ,_pt2(x2,y2)
	{
		cout<<"line(int ,int ,int,int)"<<endl;
	}
	
	void printline()
	{
		_pt1.print();
		cout<<"----->";
		_pt2.print();
		cout<<endl;
	}

	private:
	point _pt1;
	point _pt2;
};

int main(void)
{
	line l(1,2,3,4);
	l.printline();

	return 0;
}
