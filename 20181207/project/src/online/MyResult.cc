///
/// @file    MyResult.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-12-12 19:46:45
///

#include "MyResult.h"

namespace mysp
{

	bool operator<(const MyResult & r1, const MyResult & r2)
	{
		if (r1._dist != r2._dist)
		{
			return r1._dist > r2._dist;
		}
		if (r1._freq != r2._freq)
		{
			return r1._freq < r2._freq;
		}

		return r1._word > r2._word;
	}

}
