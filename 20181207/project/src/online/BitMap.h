 ///
 /// @file    BitMap.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-11 16:31:10
 ///

#ifndef __MYSP_BITMAP_H__
#define __MYSP_BITMAP_H__

#include <vector>

using namespace std;

namespace mysp
{

class BitMap
{
	public:
		explicit BitMap(const size_t);

		bool isSet(const size_t) const;
		void setMap(const size_t);

	private:
		vector<char> _bitmap;
};

}

#endif
