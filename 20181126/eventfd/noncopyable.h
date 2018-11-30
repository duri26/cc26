 ///
 /// @file    noncopyable.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-30 17:44:15
 ///

#ifndef __WD_NONCOPYABLE__
#define __WD_NONCOPYABLE__

namespace wd
{

class Noncopyable
{
	protected:
		Noncopyable() {}
		~Noncopyable() {}

		Noncopyable(const Noncopyable &) = delete;
		Noncopyable & operator =(const Noncopyable &) = delete;
};

}

#endif
