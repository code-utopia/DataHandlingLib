#include <regex>
#include <filesystem>

#include "DataHandlingLib.h"

using namespace data_handling_lib;

vector<string> ParseFilename(const string& strFilename)
{
	string strFilenameStem = GetFilenameWithoutExt(strFilename);
	string strExtensions = strFilename.substr(strFilenameStem.size()+1);

	vector<string> vecFilenameTokens = GetFieldsFromBuffer("[.]+", strExtensions);
	vecFilenameTokens.insert(vecFilenameTokens.begin(), strFilenameStem);

	return vecFilenameTokens;
}