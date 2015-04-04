#ifndef OBJ_H
#define OBJ_H

#include <map>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;
using mapSS = map<string,string>;
using arrOfmapSS = vector<map<string,string>>;

class obj {
	public:
		~obj(){}

		virtual arrOfmapSS get() = 0;
		virtual string getClassName() = 0;
};

#endif
