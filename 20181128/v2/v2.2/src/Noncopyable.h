 ///
 /// @file    Noncopyable.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 19:57:50
 ///

#ifndef __DURI_NONCOPYABLE_H__
#define __DURI_NONCOPYABLE_H__

namespace duri
{

class Noncopyalbe
{
	protected:
		Noncopyalbe() = default;
		~Noncopyalbe() = default;

		Noncopyalbe(const Noncopyalbe &) = delete;
		Noncopyalbe & operator = (const Noncopyalbe &) = delete;
};

}

#endif
