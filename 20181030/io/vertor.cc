 ///
 /// @file    vertor.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-10-30 23:29:52
 ///
#include <vector> 
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void printVector(vector<int> & vec) 
{
	cout << "vec's size() = " << vec.size() << endl
		 << "vec's capacity() = " << vec.capacity() << endl;
}

//动态数组的实现策略:
//1. 当size() == capacity() 时，直接开辟 2 * size() 的空间
//2. 将原来空间的元素复制到新空间上
//3. 销毁原来空间的元素，释放原来的空间
//4. 在新空间中添加新的元素
 
int main(void)
{
	vector<int> numbers;
	numbers.reserve(20);//可以避免频繁的扩容操作,提升程序执行效率
	printVector(numbers);

	numbers.push_back(1);
	printVector(numbers);

	numbers.push_back(2);
	printVector(numbers);

	numbers.push_back(3);
	printVector(numbers);
	
	numbers.push_back(4);
	printVector(numbers);

	numbers.push_back(5);
	printVector(numbers);

	for(size_t idx = 0; idx != numbers.size(); ++idx) 
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	for(auto & elem : numbers) 
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}

