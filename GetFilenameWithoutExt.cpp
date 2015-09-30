#include <regex>

#include "DataHandlingLib.h"

using namespace std;
using namespace std::tr1;

string GetFilenameWithoutExt(const string& strFilename)
{
	regex rPattern("[0-9]+\\.[0-9]+");
	sregex_token_iterator reIter(strFilename.begin(), strFilename.end(), rPattern);
	vector<string> vecFloat = vector<string>(reIter, sregex_token_iterator());
	vector<string> vecFloatDot2Underscore = vecFloat;
	string strFilenameTemp = strFilename;

	for(unsigned i=0 ; i<vecFloat.size() ; i++)
	{
		string strTemp = vecFloat[i];
		string strMatch = strTemp.replace(vecFloat[i].find("."), 1, "?");
		strFilenameTemp.replace(strFilenameTemp.find(vecFloat[i]), strMatch.size(), strMatch);
	}

	string strFilenameStem = strFilenameTemp.substr(0, strFilenameTemp.find("."));
	return regex_replace(strFilenameStem, regex("\\?"), ".");
}
