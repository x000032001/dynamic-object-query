#ifndef OBJ_H
#define OBJ_H

#include <map>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;

class obj {
	public:
		~obj(){}
		virtual void init() = 0;
		virtual vector<map<string,string>> get() = 0;
		virtual vector<map<string,string>> getSel(string,string) = 0;
		virtual void fin() = 0;
		virtual obj* getChild() = 0;
		virtual string getAssoc() = 0;
		bool hasChild;
};

#endif
