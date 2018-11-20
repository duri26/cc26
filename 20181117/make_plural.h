 ///
 /// @file    make_plural.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-20 10:17:04
 ///

#ifndef __MAKE_PLURAL_H__
#define __MAKE_PLURAL_H__

#include <cstddef>
#include <string>
#include <iostream>

using std::size_t;
using std::string;
using std::cout;
using std::endl;

inline string make_plural(size_t ctr,const string & word,const string & ending)
	{
		return (ctr > 1)? word + ending :word;
	}

#endif

