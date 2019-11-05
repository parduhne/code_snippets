/*  Author: Evan Parduhn
    Class: CSCI_350
    HW: 07
    Date: 11/3
*/
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include "Exp.h"
using namespace std;

class Parser{
  private:
    Exp* expr(string s);
    Exp* term(string s);
    Exp* factor(string s);
    Exp* digit(string s);
    Exp* root;
  public:
    Parser();
    bool parse(string s);
    int eval();
    int nodeCount();


};
#endif
