 ///
 /// @file    bitmap.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 15:32:34
 ///

#ifndef __WD_BITMAP_H__
#define __WD_BITMAP_H__

#include <vector>
using namespace std;

namespace wd
{

class BitMap
{
	public:
		BitMap(const size_t);

		bool isSet(const size_t)const;
		void setMap(const size_t);
		size_t size()const;

	private:
		size_t _size;
		vector<char> _bitmap;
};

}

#endif
