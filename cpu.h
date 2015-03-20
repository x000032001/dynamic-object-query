#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "core.h"
using std::cout;
using std::endl;

class cpu : public obj {
	public:
		cpu(){hasChild=true; }
		void init(){}
		vector<map<string,string>> get();
		vector<map<string,string>> getSel(string,string){}
		obj* getChild(){return &cu;}
		string getAssoc(){return "physical id";}
		
		core cu;
		void fin(){}

	private:
};

#endif
