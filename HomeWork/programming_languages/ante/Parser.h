#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>

using namespace std;

class Parser{
	public:
	Parser();
	
	bool parse(string s);
	
	bool expr(string s);
	bool digit(string s);
};

#endif
