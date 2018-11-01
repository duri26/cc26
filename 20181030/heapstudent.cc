 ///
 /// @file    heapstudent.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 14:16:12
 ///
#include <string.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

class student
{
	public:
		student (int id,const char *name)
		:_id(id)
		 ,_name(new char[strlen(name)+1]())
	{
		strcpy(_name,name);
		cout << "string (int ,const char*)"<<endl;
	}
		void destroy()
		{
			delete this;
		}

	private:
		~student ()
		{
			delete [] _name;
			cout<<"~student ()"<<endl;
		}

	public:
		void print() const
		{
			cout <<"id:"<<_id<<endl
				<<"name:"<<_name<<endl;
		}

		void * operator new(size_t size)
		{
			cout <<"void * operator new(size_t)"<<endl;
			void * ret=malloc(size);
			return ret;
		}

		void operator delete (void * ret)
		{
			cout << "void operator delete (void *)"<<endl;
			free(ret);
		}

	private:
		int _id;
		char * _name;
};

int main(void)
{
	student * pstu =new student (100,"james");
	pstu->print();
	pstu->destroy();

//	student stu1(101,"sherry");
//	stu1.print();
	return 0;
	}
