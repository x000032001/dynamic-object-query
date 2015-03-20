#include "cpu.h"

vector<map<string,string>> cpu::get()
{
	vector<map<string,string>> dict;

	map<string,string> c[2];

	c[0]["model name"] = "Intel Xeon";
	c[1]["model name"] = "Intel Xeon";

	c[0]["physical id"] = "0";
	c[1]["physical id"] = "1";

	dict.push_back(c[0]);
	dict.push_back(c[1]);
	return dict;
}


