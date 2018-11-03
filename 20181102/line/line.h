 ///
 /// @file    line.h
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-02 23:30:15
 ///

#ifndef __LINE_H__
#define __LINE_H__

class Line
{
	public:
		Line(int,int ,int,int);
		~Line();

		void printLine()const;

		class LinePimpl;

private:
		LinePimpl * _pimpl;
};

#endif
