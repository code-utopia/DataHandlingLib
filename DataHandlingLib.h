#include <iostream>
#include <string>
#include <vector>
#include <strstream>
#include <filesystem>
#include <map>

#include <io.h>

namespace data_handling_lib
{

using namespace std;
using namespace std::tr1;
using namespace std::tr2::sys;

void DumpMsgUtils4CrashHeader(const string& strAuthor, const string& strEmail, const string& strVer);

vector<string> GetFieldsFromBuffer(const string& strSeparator, const string& strBuffer);
vector<string> GetFieldsFromBuffer(const unsigned& nTotalColumn, const string& strBuffer);

string GetFilenameWithoutExt(const string& strFilename);
vector<path> GetMatchingPathVector(const string& strSchema, const unsigned& attrib);
vector<string> ParseFilename(const string& strFilename);
vector<string> GetHeadersFromFile(const string& strInputFile);

map<string, vector<string> > ReadTable(const string& file, const unsigned& nInitialBufferSize = 1500);
map<string, vector<int> > ReadTableDigit(const string& file, const unsigned& nInitialBufferSize = 1500, const unsigned& nReadLimitColumn = 0);

void DownSamplingN(const string& strFilename, const unsigned& n, const string& strExt);

};