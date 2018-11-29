 ///
 /// @file    SplitTool.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 16:48:46
 ///

#ifndef __DURI_SPLITTOOL_H__
#define __DURI_SPLITTOOL_H__

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace duri
{

class SplitTool
{
	public:
		virtual ~SplitTool() {}
		virtual std::vector<std::string> cut(const std::string &) = 0;//纯虚函数，抽象类
};

}

#endif
