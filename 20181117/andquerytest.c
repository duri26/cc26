 ///
 /// @file    andquerytest.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-19 20:43:23
 ///
#include "query.h"
#include "textquery.h"

#include <string>

int main(int argc, char ** argv)
{
	TextQuery file = get_file(argc,argv);

	do
	{
		string sought1,sought2;

		if(!get_words(sought1,sought2))
			break;

		Query andq = Query(sought1) & Query(sought2);
		cout<<"\nEcecuting query for: " <<andq<<endl;
	   QueryResult results = andq.eval(file);// eval 什么东西
	   print(cout,results);

	   results = Query(sought1).eval(file);
	   cout<<"\nExecuted query : "<<Query(sought1)<<endl;

	   print(cout,results);

	   results = Query(sought2).eval(file);
	   cout<<"\nExecuted query: "<<Query(sought2)<<endl;

	   print(cout,results);
	}while(true);

	return 0;
};
