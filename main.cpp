#include "cpu.h"
#include "core.h"
#include "parser.h"
#include <cstdio>

string genText(obj *o)
{
	string ret;
	ret += "{";
		ret += "(";
		ret += "name^" + o->getClassName();	
		ret += ")";

		ret += "(";
		ret += "type^const";
		ret += ")";

		auto objs = o->get();
		for( auto obj : objs )
		{
			ret += "[";
			for( auto attr : obj )
			{
				ret += "<";
				ret += attr.first + "^" + attr.second;
				ret += ">";
			}
			ret += "]";
		}
	ret += "}";

	return ret;
}

int main()
{
	cpu c;
	core cq;

	// start and end symnol can't be same
	// {} () [] <> ^ is identify char , can't be use in strings
	puts("@@@@@@@ testing parser");
	auto r = parser::cut(genText(&c));
	auto r2 = parser::cut(genText(&cq));
	for( auto xd : r )
		xd.print();

	for( auto xd : r2 )
		xd.print();

	return 0;
}


