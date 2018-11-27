 ///
 /// @file    noncopyable.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-23 22:01:49
 ///

#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

namespace wd
{

class Noncopyable
{
	protected:
		Noncopyable(){}
		~Noncopyable(){}

Noncopyable(const Noncopyable &) =delete;
Noncopyable & operator =(const Noncopyable &)=delete;
};

}

#endif
