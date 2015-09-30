#include "DataHandlingLib.h"

using namespace data_handling_lib;

map<string, vector<string> > ReadTable(const string& file, const unsigned& nInitialBufferSize)
{
	vector<vector<string> > matrix;

	ifstream ifs(file.c_str());
	string strBuffer = "";
	vector<string> vecHeader;
	if(getline(ifs, strBuffer))				//	READ 1ST LINE(HEADERS) FROM FILE
	{
		vecHeader = GetFieldsFromBuffer("[,\\s]+", strBuffer);
		matrix.resize(vecHeader.size());
		for(unsigned i=0 ; i<vecHeader.size() ; i++)
			matrix[0].reserve(nInitialBufferSize);
	}

	vector<string> vecValues;
	while(getline(ifs, strBuffer))
	{
		vecValues = GetFieldsFromBuffer("[,\\s]+", strBuffer);
		if(vecValues.size() != vecHeader.size())
		{
			bool bBlankAndLastLine = true;
			for(unsigned i=0 ; i<vecValues.size() ; i++)
			{
				if(vecValues[i] != "")
				{
					bBlankAndLastLine = false;
					break;
				}
			}

			if(!getline(ifs, strBuffer))	//	마지막 라인임
				break;

			throw exception( ("'" + file + "' column size mismatch.").c_str() );
		}

		for(unsigned i=0 ; i<vecHeader.size() ; i++)
			matrix[i].push_back(vecValues[i]);
	}

	map<string, vector<string> > mapTable;
	for(unsigned i=0 ; i<vecHeader.size() ; i++)
		mapTable[vecHeader[i]] = matrix[i];

	return mapTable;
}