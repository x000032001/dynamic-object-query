#ifndef CPU_H
#define CPU_H

#include <iostream>
#include "core.h"
using std::cout;
using std::endl;

class cpu : public obj {
	public:
		cpu(){
		}

		arrOfmapSS get() override;

		string getClassName() override
		{
			return "cpu";
		}
};

#endif
