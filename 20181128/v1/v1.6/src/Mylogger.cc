 ///
 /// @file    Mylogger.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-29 17:42:57
 ///

#include "Mylogger.h"

#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;

namespace duri
{

Mylogger * Mylogger::_pInstance;

Mylogger * Mylogger::getInstance()
{
	if(!_pInstance)
	{
		_pInstance = new Mylogger();
		atexit(shutdown);//自动delete
	}
	return _pInstance;
}

void Mylogger::shutdown()
{
	if(_pInstance)
	{
		delete _pInstance;
	}
}

Mylogger::Mylogger()
	:_root(Category::getRoot().getInstance("mylog"))
{
	PatternLayout * ptn1 = new PatternLayout();
	ptn1->setConversionPattern("%d %c [%p] %m%n");


	PatternLayout * ptn2 = new PatternLayout();
	ptn2->setConversionPattern("%d %c [%p] %m%n");

	OstreamAppender * pOstreamApp =
		new OstreamAppender("pOstreamApp",&cout);
	pOstreamApp->setLayout(ptn1);

	FileAppender * pFileApp =
		new FileAppender("pFileApp", "../log/test.log");
	pFileApp->setLayout(ptn2);

	_root.setAppender(pOstreamApp);
	_root.setAppender(pFileApp);
	_root.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
	Category::shutdown();
}

}
