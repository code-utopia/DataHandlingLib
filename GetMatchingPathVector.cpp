#include <regex>

#include <io.h>

#include "DataHandlingLib.h"

using namespace std;
using namespace std::tr1;
using namespace std::tr2::sys;

vector<path> GetMatchingPathVector(const string& strSchema, const unsigned& attrib)
{
	using namespace std::regex_constants;
	string strTemp	= regex_replace(strSchema, regex("\\?"), ".");
	string strRegex	= regex_replace(strTemp,   regex("\\*"), ".*");
	regex rx(strRegex, ECMAScript|icase);

	vector<path> vecPath;
	path pathCur = current_path<path>();

	if(attrib & _A_SUBDIR)
	{
		for(auto it = directory_iterator(pathCur) ; it != directory_iterator() ; it++)
		{
			path pathFolder = it->path();
			if( is_directory(pathFolder) && regex_match(pathFolder.filename().c_str(), cmatch(), rx))
				vecPath.push_back(pathFolder);
		}
	}

	if(attrib & _A_ARCH)
	{
		for(auto it = directory_iterator(pathCur) ; it != directory_iterator() ; it++)
		{
			path pathFile = it->path();
			if( is_regular_file(pathFile) && regex_match(pathFile.filename().c_str(), cmatch(), rx))
				vecPath.push_back(pathFile);
		}
	}

	return vecPath;
}