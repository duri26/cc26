///
/// @file    rsstest.cc
/// @author  duri(1197010670@qq.com)
/// @date    2018-11-12 20:53:25
///
#include "tinyxml2.h"
#include <string>
#include <regex>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using namespace tinyxml2;

int main(void)
{
	XMLDocument doc;
	doc.LoadFile("coolshell.xml");
	cout<<doc.ErrorID()<<endl;

	XMLElement * root = doc.FirstChildElement("rss");
	XMLElement * itemNode = root->FirstChildElement("channel")->FirstChildElement("item");

	int cnt = 0;
	do
	{
		if(itemNode)
		{
			XMLElement * tileNode = itemNode->FirstChildElement("title");
			XMLElement * linkNode = itemNode->FirstChildElement("link");
			XMLElement * descriptionNode = itemNode->FirstChildElement("description");
			XMLElement * contentNode = itemNode->FirstChildElement("content:encoded");

			string title;
			string link;
			string description;
			string content;

			if(tileNode)
				title = tileNode->GetText();
			if(linkNode)
				link = linkNode->GetText();
			if(descriptionNode)
				description = descriptionNode->GetText();
			if(contentNode)
				content = contentNode->GetText();
			else
				content = description;

			cout<<">>>title: "<<title<<endl<<endl
				<<">>>link:  "<<link<<endl<<endl;

//	std	::regex re("<(S*?)[^>]*>.*?|<.*? />");
			std::regex re("<.*?>");//标准库，不需要加lboost-regex
content = std::regex_replace(content, re, "");
			cout<<">>>content: \n\n"<<content<<endl<<endl;
		}
		++cnt;
		cout<<">>>cnt = "<<cnt<<endl;
	}while((itemNode=itemNode->NextSiblingElement("item")));
	return 0;

}
