 ///
 /// @file    Noncopyable.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-10 21:20:57
 ///

#ifndef __MYSP_NONCOPYABLE_H__
#define __MYSP_NONCOPYABLE_H__

namespace mysp
{

class Noncopyable
{
	protected:
		Noncopyable() = default;
		~Noncopyable() = default;

		Noncopyable(const Noncopyable &) = delete;
		Noncopyable & operator = (const Noncopyable &) = delete;

};

}

#endif
