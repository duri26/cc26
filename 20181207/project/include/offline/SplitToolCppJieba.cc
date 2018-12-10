 ///
 /// @file    SplitToolCppJieba.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-12-10 11:32:05
 ///

#include "../../include/offline/SplitToolCppJieba.h"
#include "../../include/offline/Configuration.h"

namespace dict
{

SplitToolJieba::SplitToolJieba()
	:_jieba(getConfig("dictPath")
			,getConfig("hmmPath")
			,getConfig("userDictPath")
			,getConfig("idfPath")
			,getConfig("stopWordPath"))
	{}

//调用cppjieba的Cut的方法
void SplitToolJieba::cut(vector<string> & result
		,const string & sentence)
{
	_jieba.Cut(sentence ,result, true);
}

}
