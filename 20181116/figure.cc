 ///
 /// @file    figure.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-16 21:50:41
 ///
#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

class Figure
{
	public:
		virtual void display()const = 0;
		virtual  double area() = 0;
};

void display(Figure * fig)
{
	fig->display();
	cout<<"的面积是：";
	cout<<fig->area()<<endl;
}

class Rectangle
:public Figure
{
	public:
		Rectangle(double length,double width)
			:_length(length)
			 ,_width(width)
	{}

		void display() const
		{
			cout<<"矩形";
		}

		double area()
		{
			return _length * _width;
		}
		
	private:
		double _length;
		double _width;
};

class Circle
:public Figure
{
	public:
		Circle(double radius)
			: _radius(radius)
		{}

		void display() const
		{
			cout<<"圆";
		}

		double area()
		{
			return PI * _radius * _radius;
		}

	private:
		double _radius;
		static const double PI;
};

const double Circle::PI = 3.14159;



class Triangle
:public Figure
{
	public:
		Triangle(double a,double b,double c)
			:_a(a),_b(b),_c(c)
		{}

		void display() const
		{
			cout<<"三角形";
		}

		double area()
		{
			double p =(_a + _b + _c) /2;
			return sqrt(p *(p - _a) *(p -_b)*(p - _c));
		}

	private:
		double _a;
		double _b;
		double _c;
};

int main(void)
{
	Circle circle(10);
	Rectangle re(10,33);
	Triangle t(5,5,5);

	display(&circle);
	display(&re);
	display(&t);

	return 0;
}
			
