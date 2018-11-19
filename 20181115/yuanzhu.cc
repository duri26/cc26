 ///
 /// @file    yuanzhu.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-18 20:47:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Circle
{
	public:
		Circle()
		:_radius(0)
		{
		}

		Circle(double r)
			: _radius(r)
		{
		}

		double getArea() const 
		{
			return  PI * _radius*_radius;
		}

		double getPerimeter() const
		{
			return 2 * PI * _radius;
		}

		void show() const
		{
			cout<<"radius = "<<_radius<<endl
				<<"周长 ："<<getPerimeter()<<endl
				<<"面积 ："<<getArea()<<endl;
		}

	protected:
		static const double PI;
		double _radius;
};

const double Circle:: PI = 3.141592;

class Cylinder
: public Circle
{
public :
	Cylinder(double r,double h)
		:Circle(r)
		 ,_height(h)
	{
	}

	double getVolume () const
	{
		return getArea() * _height;
	}

	void showVolume()
	{
		cout<<" r："<<_radius<<"  height: "<<_height<<"  的圆柱体积: "<<getVolume()<<endl;
	}

	private:
	double _height;
};

int main(void)
{
	Cylinder cy1(10,10);
	cy1.show();
cout<<endl;

	cy1.showVolume();
	return 0;
}
