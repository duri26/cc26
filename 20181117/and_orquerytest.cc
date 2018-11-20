 ///
 /// @file    and_orquerytest.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-19 23:38:20
 ///

#include "query.h"
#include "textquery.h"

using std::cin;
using std::cerr;

int main(int argc,char **argv)
{
	TextQuery file =get_file(argc,argv);

	while(true)
	{
		string sought1,sought2,sought3;
		if(!get_words(sought1,sought2))
			break;
		cout<<"\nenrer third word: ";
		cin>>sought3;

		Query q =Query(sought1) &Query(sought2) |Query(sought3);
		cout<<"\nExecuting Query for: "<<q<<endl;
		const QueryResult results = q.eval(file);

		print(cout,results);
	}
	return 0;
}
