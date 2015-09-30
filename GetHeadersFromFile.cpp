#include "DataHandlingLib.h"

using namespace data_handling_lib;

vector<string> GetHeadersFromFile(const string& strInputFile)
{
	vector<string> vecHeaders;
	ifstream ifs(strInputFile.c_str());

	string strBuffer = "";
	if(getline(ifs, strBuffer))
		vecHeaders = GetFieldsFromBuffer("[\\s]+", strBuffer);
	else
		throw exception( ("'" + strInputFile + "' do not have header line.").c_str() );

	return vecHeaders;
}