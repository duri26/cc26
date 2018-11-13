 ///
 /// @file    stackstudent.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-13 20:16:12
 ///
#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class student
{
	public:
		student(int id, const char * name)
			: _id(id)
			  ,_name(new char [strlen(name)+1]())
	{
		strcpy(_name,name);
		cout<<"student(int ,const char *)"<<endl;
	}

		~student()
		{
			delete [] _name;
			cout<<" ~student()"<<endl;
		}

		void print() const
		{
			cout<<"id: "<<_id<<endl
				<<"name: "<<_name<<endl;
		}

	private:
		void * operator new(size_t size);
		void operator delete(void * ret);

	private:
		int _id;
		char * _name;
};

 
int main(void)
{
	//student * pstu = new student(100, "Jackie");//error,要求编译无法通过
	//pstu->print();

	///delete pstu;

	student stu1(101, "Marry");//ok
	stu1.print();
	return 0;
}

