 ///
 /// @file    computer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-26 21:22:40
 ///
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

struct computer
{
	public:
		void setbrand(const char* brand)
		{
			strcpy(_brand,brand);
		}

		void setprice(float price)
			{
				_price=price;
			}
		void print()
		{
			cout<<"品牌:"<<_brand<<endl
				<<"加个:"<<_price<<endl;
		}
	protected:
		float _price;

		private:
		char _brand[20];
};

int main()
{
	int a;
	computer pc1;
	pc1.setbrand("sony");
	pc1.setprice(7999);
	pc1.print();

	return 0;
}
