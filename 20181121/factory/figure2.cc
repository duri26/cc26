 ///
 /// @file    figure2.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-21 15:44:00
 ///
#include <math.h>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;

class Figure
{
	public:
		virtual void display () const =0;
		virtual double area() = 0;
		virtual ~Figure() {}
};

void display(Figure * fig)
{
	fig->display();
	cout<<" 的面积 ";
	cout<<fig->area()<<endl;
}

class Rectangle
: public Figure
{
	public:
		Rectangle(double length,double width)
			:_length(length),_width(width)
		{
		}

		void display()const
		{
			cout<<"矩形";
		}

		double area()
		{
			return _length * _width;
		}
		
		~Rectangle()
		{
			cout<<"~Rectangle()"<<endl;
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
			:_radius(radius)
		{}

		void display()const
		{
			cout<<" 圆 ";
		}
		
		double area()
		{
			return PI * _radius * _radius;
		}

		~Circle()
		{
			cout<<"~Circle()"<<endl;
		}

	private:
		double _radius;
		static const double PI;
};

const double Circle::PI = 3.141592;

class Triangle
:public Figure
{
	public:
		Triangle(double a,double b,double c)
			:_a(a),_b(b),_c(c)
		{}

		void display()const
		{
			cout<<" 三角形 ";
		}

		double area()
		{
			double p =(_a + _b + _c) / 2;
			return sqrt(p *(p-_a)*(p-_b)*(p-_c));
		}

		~Triangle()
		{
			cout<<"~Triangle()"<<endl;
		}

	private:
		double _a;
		double _b;
		double _c;
};

class Factory
{
	public:
		virtual Figure * create() =0;
		virtual ~Factory() {}
};

class CircleFactory
:public Factory
{
	public:
		Figure * create()
		{
			return new Circle(10);
		}

		~CircleFactory()
		{
			cout<<"~CircleFactory()"<<endl;
		}
};

class RectangleFactory
: public Factory
{
	public:
		Figure * create()
		{
			return new Rectangle(10,22);
		}

		~RectangleFactory()
		{
			cout<<"~RectangleFactory()"<<endl;
		}
};

class TriangleFactory
:public Factory
{
	public:
		Figure * create()
		{
			return new Triangle(3,4,5);
		}

		~TriangleFactory()
		{
			cout<<"~TriangleFactory()"<<endl;
		}
};

int main(void)
{
	unique_ptr<Factory> pcircleFactory(new CircleFactory());
	unique_ptr<Figure> pcircle(pcircleFactory->create());

	unique_ptr<Factory> prectangleFactory(new RectangleFactory());
	unique_ptr<Figure> prectangle(prectangleFactory->create());

	unique_ptr<Factory> ptriangleFactory(new TriangleFactory());
	unique_ptr<Figure> ptriangle(ptriangleFactory->create());

	display(pcircle.get());
	display(prectangle.get());
	display(ptriangle.get());

	return 0;
}
