#include "core.h"

vector<map<string,string>> core::getSel(string k,string v)
{
	vector<map<string,string>> dict;

	map<string,string> core[5];

	core[1]["physical id"] = "0";
	core[2]["physical id"] = "0";
	core[3]["physical id"] = "1";
	core[4]["physical id"] = "1";

	core[1]["processor"] = "0";
	core[2]["processor"] = "1";
	core[3]["processor"] = "2";
	core[4]["processor"] = "3";

	core[1]["mhz"] = "1596";
	core[2]["mhz"] = "1596";
	core[3]["mhz"] = "1596";
	core[4]["mhz"] = "1596";

	for( auto it : core )
	{
		auto iter = it.find(k);
		if( iter == it.end() )
			continue;

		if( iter->second == v )
			dict.push_back(it);
	}

	return dict;
}


