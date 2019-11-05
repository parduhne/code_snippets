#include <iostream>
#include <string>

#include "Parser.h"

using namespace std;


Parser::Parser(){

}

bool Parser::parse(string s){
	if(s.length() > 0){
    string nospace;
    for(unsigned int i = 0; i < s.length(); i++){
      if(s[i] != ' '){
        nospace = nospace + s[i];
      }
    }
    return expr(nospace);
  }
  return false;
}


bool Parser::expr(string s){
	if(s.length() > 0){
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '+'){
				if(expr(s.substr(0,i)) && expr(s.substr(i+1))) return true;
			}
		}
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '-'){
				if(expr(s.substr(0,i)) && expr(s.substr(i+1))) return true;
			}
		}
		if(s[0] == '(' && s[s.length()-1] == ')'){
			return (expr(s.substr(1,s.length()-2)));
		}
		return digit(s);
	}
	return false;
}

bool Parser::digit(string s){
	if(s == "0") return true;
	else if(s == "1") return true;
	else if(s == "2") return true;
	else if(s == "3") return true;
	else if(s == "4") return true;
	else if(s == "5") return true;
	else if(s == "6") return true;
	else if(s == "7") return true;
	else if(s == "8") return true;
	else if(s == "9") return true;
	else return false;
}
