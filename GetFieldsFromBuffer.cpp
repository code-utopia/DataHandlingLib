#include <regex>

#include "DataHandlingLib.h"

using namespace std;
using namespace std::tr1;

vector<string> GetFieldsFromBuffer(const string& strSeparator, const string& strBuffer)
{
	regex rDeliminator(strSeparator);
	sregex_token_iterator reIter(strBuffer.begin(), strBuffer.end(), rDeliminator, -1);
	return vector<string>(reIter, sregex_token_iterator());
}

vector<string> GetFieldsFromBuffer(const unsigned& nTotalColumn, const string& strBuffer)
{
	vector<string> vecRtn(nTotalColumn);
	istrstream iss(strBuffer.c_str(), strBuffer.size());
	for(unsigned i=0 ; i<nTotalColumn ; i++)
		iss>>vecRtn[i];
	return vecRtn;
}