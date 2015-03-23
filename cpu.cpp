#include "cpu.h"

arrOfmapSS cpu::get()
{
	arrOfmapSS dict;

	mapSS c[2];

	/* get information and put it yo dict */
	c[0]["model name"] = "Intel Xeon";
	c[1]["model name"] = "Intel Xeon";

	c[0]["physical id"] = "0";
	c[1]["physical id"] = "1";

	dict.push_back(c[0]);
	dict.push_back(c[1]);
	return dict;
}


