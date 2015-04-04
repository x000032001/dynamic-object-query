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

void parseAndGenSQL(const string &s)
{
	auto r = parser::cut(s);
	for( auto xd : r )
	{
		auto v = xd.getSQL();
		for( auto &s : v )
			cout << s << endl;
	}
}

int main()
{
	// declare objects in daemon and get information
	cpu c;
	core cq;

	// in parser functions
	// start and end symnol can't be same
	// {} () [] <> ^ is identify char , can't be use in strings

	// get information in string and pass to parser
	// you can transfer text to agent via networking
	parseAndGenSQL( genText(&c) );
	parseAndGenSQL( genText(&cq) );

	return 0;
}


