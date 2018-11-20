 ///
 /// @file    wordquerytest.cc
 /// @author  duri(1197010670@qq.com)
 /// @date    2018-11-20 11:12:13
 ///

#include "query.h"
#include "textquery.h"

int main(int argc,char **argv)
{
	TextQuery file =get_file(argc,argv);

	do {
		string sought;
		if(!get_word(sought))
			break;

		Query name(sought);
		const QueryResult results =name.eval(file);
		cout<<"\nExecuting Query for: "<<name<<endl;
		print(cout,results)<<endl;
	}while(true);
	return 0;
}
