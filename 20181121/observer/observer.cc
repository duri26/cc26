 ///
 /// @file    observer.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-21 17:49:24
 ///
#include <stdlib.h>
#include <time.h>

#include <list>
#include <algorithm>
#include <string>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::list;
using std::find;
using std::string;
using std::unique_ptr;

class Observer
{
	public:
		virtual void update()=0;
		virtual ~Observer(){}
};

class Baby
:public Observer
{
	public:
		Baby(const string & name)
		:_name(name),_random(0)
		{}

		void action()
		{
			update();
		}

		void update ()
		{
			::srand(::clock());
			_random =::rand() % 100;
			if(_random <= 25)
			{
				cout<<">>>>Baby "<<_name<<" is crying"<<endl;
			}
			else
			{
				cout<<">>>>Baby "<<_name<<" is sleeping "<<endl;
			}
		}

		~Baby()
		{
			cout<<"~Baby()"<<endl;
		}

	private:
		string _name;
		int _random;
};

class Nurse
:public Observer
{
	public:
		Nurse(const string & name)
			:_name(name),_random(0)
		{}

//		void action()
//		{
//			update();
//		}
//
		void update()
		{
			::srand(clock());
			_random= rand() % 100;
			if(_random <=75)
				cout<<">>>>Nurse "<<_name<<"is waking up"<<endl;
		else 
			cout<<">>>>Nurse "<<_name<<"is sleeping"<<endl;
		}

		~Nurse()
		{
			cout<<"~Nurse()"<<endl;
		}

	private:
		string _name;
		int _random;
};

class Subject
{
	public:
		virtual void attach(Observer *)=0;
		virtual void detach(Observer *)=0;
		virtual void notify()=0;

		virtual ~Subject() {};
};

class Ring
:public Subject
{
	public:
		Ring()
		:_isalarm(false)
		{}

		virtual ~Ring()
		{
			cout<<"~Ring()"<<endl;
		}
	
		void press()
		{
			setState(true);
			notify();
		}

		void attach(Observer * ob)
		{
			auto it =find(_observerList.begin(),_observerList.end(),ob);
			if(it == _observerList.end())
			_observerList.push_front(ob);
		}

		void detach (Observer * ob)
		{
			auto it =find(_observerList.begin(),_observerList.end(),ob);
			if(it != _observerList.end())
				_observerList.erase(it);
		}

		void notify()
		{
			for(auto & ob:_observerList)
				ob->update();
		}

		bool getState() const
		{
			return _isalarm;
		}

		void setState(bool state)
		{
			_isalarm = state;
		}

	private:
		bool _isalarm;
		list<Observer*> _observerList;
};

class Guest
{
	public:
		Guest(const string & name)
			:_name(name)
		{}

		void knock(Ring & ring)
		{
			cout<<" >>>>"<<_name<<" start knocking at the door"<<endl;
		ring.press();
		}

	private:
		string _name;
};

int main(void)
{
	unique_ptr<Observer> baby1(new Baby("niuniu"));
	unique_ptr<Observer> baby2(new Baby("xiongba"));

	unique_ptr<Observer> nurse1(new Nurse("marry"));
	unique_ptr<Observer> nurse2(new Nurse("may"));

	Ring ring;
	ring.attach(baby1.get());
	ring.attach(baby2.get());
	ring.attach(nurse1.get());
	ring.attach(nurse2.get());

	
	Guest guest("步惊云");
	guest.knock(ring);

	return 0;
}

