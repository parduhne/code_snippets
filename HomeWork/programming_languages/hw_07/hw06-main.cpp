#include <iostream>
#include <string>

#include "Parser.h"

using namespace std;

int main(){
  string input;
  cout<<">";
  getline(cin,input);
  Parser p;
  while(input!="quit"){
    bool thing = p.parse(input);
    if(thing){
      cout << "Accepted\nValued as: ";
      cout << p.eval() << endl;
      cout << "Node Count: ";
      cout << p.nodeCount() <<endl;
    }else{
      cout << "Not accepted" << endl;
    }
    cout << ">";
    getline(cin,input);
  }
}
