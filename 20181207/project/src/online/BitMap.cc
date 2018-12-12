 ///
 /// @file    BitMap.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-12 20:43:06
 ///

#include "BitMap.h"
#include "math.h"

namespace mysp
{

BitMap::BitMap(const size_t size)
: _bitmap(ceil(size / 8), 0)
{
}

//获取一位
bool BitMap::isSet(const size_t idx) const
{
	size_t i = idx /8, j = idx % 8;
	return _bitmap[i] & (1 << j);
}

//设置一位
void BitMap::setMap(const size_t idx)
{
	size_t i = idx / 8, j = idx % 8;
	_bitmap[i] |= (1 << j);
}

}
 
