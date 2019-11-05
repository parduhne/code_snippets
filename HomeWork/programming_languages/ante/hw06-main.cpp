#include <iostream>
#include <string>

#include "Parser.h"

using namespace std;

int main(){
	string input;
	cout << ">";
	getline(cin,input);
	Parser p;

	while(input != "quit"){
		if(p.parse(input)){
			cout << "Accepted";
		}else{
			cout << "Not accepted";
		}
		cout << ">";
		getline(cin,input);
	}
}
