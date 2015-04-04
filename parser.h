#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

using mapSS = map<string,string>;
using arrOfmapSS = vector<mapSS>;

class result
{
	public:
		mapSS infos;
		arrOfmapSS objs;	
		void print()
		{
			if( !infos.empty() )
				cout << "type information:" << endl;
			for( auto info : infos )
				cout << info.first << "  \t  " << info.second << endl;

			if( objs.empty() )
				cout << "doesn't have any objects in this type" << endl;
			else
				cout << "\tobjs in this type:" << endl;
			for( auto obj : objs )
			{
				cout << "\t======" << endl;
				if( obj.empty() )
					cout << "\tempty obj" << endl;
				for( auto attr : obj )
					cout << "\t" << attr.first << "  =  " << attr.second << endl;
				cout << "\t======\n" << endl;
			}
		}
};

class parser 
{
	public:
		static vector<result> cut(string);
		//void printResult();
	private:
		static string tryCutString(string& , char ) throw(int);
		static int findChar( string& , char );
		static vector<string> splitByBrackets(string,char,char);
};

#endif
