 ///
 /// @file    insert_iterator.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-10 14:29:15
 ///
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <deque>
#include <set>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::ostream_iterator;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
using std::copy;
using std::deque;

int main(void)
{
	vector<int> vec{3,2,1,4,5,6};
	list<int> li{11,33,22};
	deque<int> deq;
	set<int> setInt {8,7,9,0};

copy(li.begin(),li.end(),back_insert_iterator<vector<int>>(vec));
copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
cout<<endl;

copy(li.begin(),li.end(),front_insert_iterator<deque<int>>(deq));
copy(deq.begin(),deq.end(),ostream_iterator<int>(cout," "));
cout<<endl;

copy(li.begin(),li.end(),insert_iterator<set<int>>(setInt, setInt.begin()));
copy(setInt.begin(),setInt.end(),ostream_iterator<int>(cout," "));
		cout<<endl;

return 0;
}
