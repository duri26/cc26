 ///
 /// @file    student.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-13 19:50:49
 ///
#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class student
{
	public:
		student(int id,const char * name)
			: _id(id)
			  ,_name(new char [strlen(name)+1]())
	{
		strcpy(_name,name);
		cout<<"student(int ,const char *)"<<endl;
	}


		void destroy()
		{
			delete this;
		}

	private:
		~student()
		{
			delete [] _name;
			cout<<"~student()"<<endl;
		}

	
	public:

		void print() const
		{
			cout<<"id:"<<_id<<endl
				<<"name: "<<_name<<endl;
		}


		void * operator new(size_t size)
		{
			cout<<"void * operator new(size_t )   "<<size<<endl;
			void * ret =malloc(size);
			return ret;
		}

		void operator delete(void * ret)
		{
			cout<<"void operator delete (void *)   "<<ret<<endl;
			free(ret);
			ret=NULL;
		}

	private:
		int _id;
		char * _name;
};


int main(void)
{
	student * pstu = new student(100, "Jackie");//ok
	pstu->print();
	pstu->destroy();

	//delete pstu;
	
	//对于栈对象而言，同时要求构造函数和析构函数都是Public的
//	student stu1(101, "Marry");//期望:error
//	stu1.print();
	return 0;
}

