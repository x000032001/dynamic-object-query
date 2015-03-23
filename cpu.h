#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "core.h"
using std::cout;
using std::endl;

class cpu : public obj {
	public:
		cpu(){
			hasChild=true; 
		}

		arrOfmapSS get() override;

		arrOfmapSS getSel(string,string) override 
		{
			return arrOfmapSS();
		}

		obj* getChild() override 
		{
			return &cu;
		}

		string getAssoc() override
		{
			return "physical id";
		}

		string getClassName() override
		{
			return "cpu";
		}
		
	private:
		core cu;
};

#endif
