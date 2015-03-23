#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "core.h"
using std::cout;
using std::endl;

class cpu : public obj {
	public:
		cpu(){hasChild=true; }
		arrOfmapSS get();
		arrOfmapSS getSel(string,string){return arrOfmapSS();}
		obj* getChild(){return &cu;}
		string getAssoc(){return "physical id";}
		string getClassName(){return "cpu";}
		
	private:
		core cu;
};

#endif
