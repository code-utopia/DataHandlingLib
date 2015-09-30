#include "DataHandlingLib.h"

using namespace data_handling_lib;

void DumpMsgUtils4CrashHeader(const string& strAuthor, const string& strEmail, const string& strVer)
{
	cerr<<"\n";
	cerr<<"------------------------------------------------------------------------------------\n";
	cerr<<"                      Programmed by "<<strAuthor<<"\n";
	cerr<<"                      E-MAIL:  "<<strEmail<<"\n";
	cerr<<"------------------------------------------------------------------------------------\n";
	cerr<<"\n\n";

	if(strVer != "")
		cerr<<"Version "<<strVer<<"\n\n";

#ifdef _M_AMD64
	cerr<<"Compile information : 64bit, "<<__DATE__<<", "<<__TIME__<<", ";
#else
	cerr<<"Compile information : "<<__DATE__<<", "<<__TIME__<<", ";
#endif

#ifdef __USE_STD_LIB__
	cerr<<"USE_STD_LIB"<<", ";
#else
	cerr<<"NOUSE_STD_LIB"<<", ";
#endif

	cerr<<"\n";
}