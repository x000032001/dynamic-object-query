#include "cpu.h"
#include "core.h"
#include <cstdio>

void print(vector<map<string,string>> &vec)
{
	for( auto iter : vec )
	{
		for( auto it : iter )
			cout << it.first << " : " << it.second << endl;
		cout << endl;
	}
}

void f(obj *o , string k , string v)
{
	vector<map<string,string>> it;
	if(k==""&&v=="")
	{
		it = o->get();
		puts("got objects:");
		print(it);
		puts("===========");
	}
	else
	{
		cout << "select by " << k << " = " << v << endl;
		it = o->getSel(k,v);
		puts("got objects:");
		print(it);
		puts("===========");
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

}

int main()
{
	cpu c;
	f(&c,"","");

	return 0;
}


