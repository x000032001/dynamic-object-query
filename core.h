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
			hasChild=false;
		}

		arrOfmapSS get() override
		{
			return arrOfmapSS();
		} 

		arrOfmapSS getSel(string,string) override;

		obj* getChild() override 
		{
			return NULL;
		}

		string getAssoc() override 
		{
			return NULL;
		}

		string getClassName() override 
		{
			return "core";
		}
	private:
};

#endif
