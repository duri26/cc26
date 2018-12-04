 ///
 /// @file    bitmap.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 15:42:24
 ///

#include "bitmap.h"

#include <math.h>

namespace wd
{
	BitMap::BitMap(const size_t size)
		:_size(size)
		 ,_bitmap(ceil(size/8),0)
	{
	}
//位图，获取一位，
	bool BitMap::isSet(const size_t idx)const 
	{
		size_t i = idx/8, j =idx % 8;
		return _bitmap[i] & (1<<j);
	}
//设置一位 
	void BitMap::setMap(const size_t idx)
	{
		size_t i =idx/8,j=idx % 8;
		_bitmap[i] |= (1<<j);
	}

	size_t BitMap::size()const 
	{
		return _size;
	}

}
