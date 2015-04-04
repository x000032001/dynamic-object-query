#ifndef CORE
#define CORE

#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

class core : public obj {
	public:
		core()
		{
		}

		arrOfmapSS get() override;

		string getClassName() override
		{
			return "core";
		}

};

#endif
