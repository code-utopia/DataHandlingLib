#include "DataHandlingLib.h"

using namespace data_handling_lib;

map<string, vector<int> > ReadTableDigit(const string& file, const unsigned& nInitialBufferSize, const unsigned& nReadLimitColumn)
{
	vector<vector<int> > matrix;

	ifstream ifs(file.c_str());
	string strBuffer = "";
	vector<string> vecHeader;
	unsigned nSize;
	if(getline(ifs, strBuffer))				//	READ 1ST LINE(HEADERS) FROM FILE
	{
		vecHeader = GetFieldsFromBuffer("[,\\s]+", strBuffer);
		nSize = (nReadLimitColumn<=0) ? unsigned(vecHeader.size()) : nReadLimitColumn;
		matrix.resize(nSize);
		for(unsigned i=0 ; i<nSize ; i++)
			matrix[0].reserve(nInitialBufferSize);
	}

	vector<string> vecValuesStr;
	while(getline(ifs, strBuffer))
	{
		vecValuesStr = GetFieldsFromBuffer("[,\\s]+", strBuffer);
		if(vecValuesStr.size() < nSize)
			throw exception( ("'" + file + "' column size mismatch.").c_str() );

		for(unsigned i=0 ; i<nSize ; i++)
			matrix[i].push_back(atoi(vecValuesStr[i].c_str()));
	}

	map<string, vector<int> > mapTable;
	for(unsigned i=0 ; i<nSize ; i++)
		mapTable[vecHeader[i]] = matrix[i];

	return mapTable;
}