#include "parser.h"

vector<result> parser::cut(string s)
{
	vector<result> retv;

	auto res = splitByBrackets(s,'{','}');
	for( string &s : res )
	{
		result tmpRet;
		auto infos = splitByBrackets(s,'(',')');
		for( string t : infos )
		{
			string attrName;
			try {	
				attrName = tryCutString( t , '^' );
			} catch(...) {
				puts("no delimter there");
			}
			tmpRet.infos[attrName] = t;
		}

		auto objs = splitByBrackets(s,'[',']');
		for( string &t : objs )
		{
			mapSS tmpObj;
			auto attrs = splitByBrackets(t,'<','>');

			for( string v : attrs )
			{
				string attrName;
				try {	
					attrName = tryCutString( v , '^' );
				} catch(...) {
					puts("no delimter there");
				}
				tmpObj[attrName] = v;
			}		
			tmpRet.objs.push_back(tmpObj);
		}

		retv.push_back(tmpRet);
	}

	return retv;
}

string parser::tryCutString(string& str, char delim) throw(int)
{
	size_t pos = str.find(delim);	
	if( pos == string::npos )
		throw 1;

	string ret = str.substr( 0, pos );
	str.erase( 0, pos+1 );

	return ret;
}

vector<string> parser::splitByBrackets( string s , char start_sym , char end_sym )
{
	vector<string>ret;
	if(s.empty())
		return ret;

	size_t start = string::npos , end = string::npos ;
	bool usedStart = false ,alreadyFindStart = false;
	for( size_t i = 0 ; i <= s.size() ; ++i )
	{
		if( s[i] == start_sym )
		{
			if( alreadyFindStart == true )
			{
				puts("ERR:find duplicate start sym");
				return ret;
			}
			start = i;
			alreadyFindStart = true;
			usedStart = false;
		}
		if( s[i] == end_sym )
		{
			if( start == string::npos )
			{
				puts("ERR:start sym not found");
				return ret;
			}
			else {
				end = i;
				if( start < end )
				{
					if( usedStart == true )
					{
						puts("ERR:duplicate end sym ,don't use nested brackets");
						ret.clear();
						return ret;
					}

					string sub = s.substr( start+1,end-start-1 );
					ret.push_back(sub);
					usedStart = true;
					alreadyFindStart = false;
				}
			}
		}
	}

	if( end == string::npos )
	{
		puts("ERR:end sym not found");
	}

	return ret;
}


