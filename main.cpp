#include "cpu.h"
#include "core.h"
#include <cstdio>

void print(arrOfmapSS &vec)
{
	for( auto iter : vec )
	{
		cout << "   [" << endl;
		for( auto it : iter )
			cout << "    " << it.first << " : " << it.second << endl;
		cout << "   ]" << endl;
	}
}

void f(obj *o , string k , string v)
{
	arrOfmapSS it;
	if(k==""&&v=="")
	{
		cout << "class " << o->getClassName() << endl;
		cout << '{' << endl;
		it = o->get();
		if( it.empty() )
			exit(1);
		print(it);
	}
	else
	{
		cout << "class " << o->getClassName() ;
		cout << " (select by " << k << " = " << v << ")" << endl;
		cout << '{' << endl;
		it = o->getSel(k,v);
		if( it.empty() )
			exit(1);
		print(it);
	}

	if(o->hasChild)
	{
		obj* ch = o->getChild();
		string key = o->getAssoc();
		for( auto iter : it )
		{
			auto res = iter.find( key );
			if( res == iter.end() )
				break;

			f(ch , key , res->second);
		}
	}
	cout << '}' << endl;
}

int main()
{
	cpu c;
	f(&c,"","");

	return 0;
}


