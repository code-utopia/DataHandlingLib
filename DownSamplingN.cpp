#include "DataHandlingLib.h"

using namespace data_handling_lib;

void DownSamplingN(const string& strFilename, const unsigned& n, const string& strExt)
{
	ifstream ifs(strFilename.c_str());
	ofstream ofs( (path(strFilename).stem() + strExt).c_str() );

	string strBuffer = "";
	for(unsigned i=0 ; getline(ifs, strBuffer) ; i++)
	{
		if( (i%n) == 0 )
			ofs<<strBuffer<<"\n";
	}
}