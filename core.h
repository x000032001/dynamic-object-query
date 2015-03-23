#ifndef CORE
#define CORE

#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

class core : public obj {
	public:
		core(){hasChild=false;}
		arrOfmapSS get(){return arrOfmapSS();}
		arrOfmapSS getSel(string,string);
		obj* getChild(){return NULL;}
		string getAssoc(){return NULL;}
		string getClassName(){return "core";}
	private:
};

#endif
