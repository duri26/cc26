 ///
 /// @file    cachemanager.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-04 15:57:46
 ///

#ifndef __WD_CACHEMANAGER_H__
#define __WD_CACHEMANAGER_H__

#include <vector>
#include "cache.h"

namespace wd
{
class CacheManager
{
	public:
		static void initCache(size_t);
		static Cache & getCache(size_t);
		static void periodicUpdateCahces();
	private:
		static vector<Cache> _cacheList;
};

}

#endif

