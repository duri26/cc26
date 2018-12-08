 ///
 /// @file    SplitTool.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-07 20:06:41
 ///

#ifndef __DICT_SPLITTOOL_H__
#define __DICT_SPLITTOOL_H__

using namespace std;

namespace dict
{

class SplitTool
{
	public:
		virtual ~SplitToll() {}
		virtual void cut(vector<string>&,const string &) = 0;
};

}

#endif
