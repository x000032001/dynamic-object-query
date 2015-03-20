#ifndef CORE
#define CORE

#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

class core : public obj {
	public:
		core(){hasChild=false;}
		vector<map<string,string>> get(){return nil;}
		vector<map<string,string>> getSel(string,string);
		obj* getChild(){return NULL;}
		string getAssoc(){return NULL;}
		string getClassName(){return "core";}
	private:
};

#endif
