#ifndef CORE
#define CORE

#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

class core : public obj {
	public:
		core(){hasChild=false;}
		void init(){}
		vector<map<string,string>> get(){}
		vector<map<string,string>> getSel(string,string);
		void fin(){}
		obj* getChild(){return NULL;}
		string getAssoc(){return NULL;}
	private:
};

#endif
