 ///
 /// @file    figure2.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 22:50:31
 ///
#include <math.h>

#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::function;
using std::bind;

class Figure
{
	public:
		using DisplayCallback = function<void()>;
		using AreaCallback = function<double()>;

		void setDisplayCallback(DisplayCallback && cb)
		{
			_callback1 = std::move(cb);
		}

		void setAreaCallback(AreaCallback && cb)
		{
			_callback2 = std::move(cb);
		}

		void handleDisplayCallback()
		{
			if(_callback1)
				_callback1();
		}

		double handleAreaCallback()
		{
			if(_callback2)
				return _callback2();
			else
				return 0;
		}

	private :
		DisplayCallback _callback1;
		AreaCallback _callback2;
};

void display(Figure & fig)
{
	fig.handleDisplayCallback();
	cout<<"的面积：";
	cout<<fig.handleAreaCallback()<<endl;
}

class Rectangle
{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	void display() const
	{	cout << "矩形";	}

	double area() 
	{	return _length * _width;	}

private:
	double _length;
	double _width;
};

class Circle
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void show() const
	{	cout << "圆";	}

	double getArea() 
	{	return PI * _radius * _radius;	}

private:
	double _radius;
	static const double PI;
};
const double Circle::PI = 3.14159;

class Triangle
{
public:
	Triangle(double a, double b, double c)
	: _a(a), _b(b), _c(c)
	{}
	
	void print() const
	{	cout << "三角形";	}

	double calcArea() 
	{
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));//海伦公式
	}
private:
	double _a;
	double _b;
	double _c;
};

int main(void )
{
Rectangle re(10,11);
Circle ci(10);
Triangle tr(3,4,5);
Figure fig;

fig.setDisplayCallback(bind(&Rectangle::display,&re));
fig.setAreaCallback(bind(&Rectangle::area, &re));
display(fig);

fig.setDisplayCallback(bind(&Circle::show, &ci));
	fig.setAreaCallback(bind(&Circle::getArea, &ci));
	display(fig);

	fig.setDisplayCallback(bind(&Triangle::print, &tr));
	fig.setAreaCallback(bind(&Triangle::calcArea, &tr));
	display(fig);

return 0;
};
