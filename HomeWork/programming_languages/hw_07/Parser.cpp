/*  Author: Evan Parduhn
    Class: CSCI_350
    HW: 07
    Date: 11/3
*/
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

    this->root = expr(nospace);
    if(this->root != 0){
      return true;
    }
  }
  return false;
}

Exp* Parser::expr(string s){
  if(s.length()>0){
    for(unsigned int i = 0; i < s.length(); i++){
      if(s[i] == '+'){
        string sa = s.substr(0,i);
        string sb = s.substr(i+1);
        if(sa.length() != 0 && sb.length() != 0){
          Exp* a = expr(sa);
          Exp* b = term(sb);
          if(a != 0 && b != 0){
            Exp* newPlus =  new Plus(a,b);
            return newPlus;
          }//else return 0;
        }//else return 0;
      }
    }
    for(unsigned int i = 0; i < s.length(); i++){
      if(s[i] == '-'){
        string sa = s.substr(0,i);
        string sb = s.substr(i+1);
        if(sa.length() != 0 && sb.length() != 0){
          Exp* a = expr(sa);
          Exp* b = term(sb);
          if(a != 0 && b != 0){
            Exp* newMin =  new Minus(a,b);
            return newMin;
          }//else return 0;
        }//else return 0;
      }
    }
    return term(s);
  }
  return 0;
}
Exp* Parser::term(string s){
  if(s.length()>0){
    for(unsigned int i = 0; i < s.length(); i++){
      if(s[i] == '*'){
        string sa = s.substr(0,i);
        string sb = s.substr(i+1);
        if(sa.length() != 0 && sb.length() != 0){
          Exp* a = term(sa);
          Exp* b = factor(sb);
          if(a != 0 && b != 0){
            Exp* newMult = new Mult(a,b);
            return newMult;
          }//else return 0;
        }//else return 0;
      }
    }
    for(unsigned int i = 0; i < s.length(); i++){
      if(s[i] == '/'){
        string sa = s.substr(0,i);
        string sb = s.substr(i+1);
        if(sa.length() != 0 && sb.length() != 0){
          Exp* a = term(sa);
          Exp* b = factor(sb);
          if(a != 0 && b != 0){
            Exp* newDiv =  new Div(a,b);
            return newDiv;
          }//else return 0;
        }//else return 0;
      }
    }
    for(unsigned int i = 0; i < s.length(); i++){
      if(s[i] == '%'){
        string sa = s.substr(0,i);
        string sb = s.substr(i+1);
        if(sa.length() != 0 && sb.length() != 0){
          Exp* a = term(sa);
          Exp* b = factor(sb);
          if(a != 0 && b != 0){
            Exp* newMod = new Mod(a,b);
            return newMod;
          }//else return 0;
        }//else return 0;
      }
    }
    for(unsigned int i = 0; i < s.length(); i++){
      if(s[i] == '^'){
        string sa = s.substr(0,i);
        string sb = s.substr(i+1);
        if(sa.length() != 0 && sb.length() != 0){
          Exp* a = term(sa);
          Exp* b = factor(sb);
          if(a != 0 && b != 0){
            Exp* newExpo =  new Expo(a,b);
            return newExpo;
          }//else return 0;
        }//else return 0;
      }
    }
    return factor(s);
  }
  return 0;
}
Exp* Parser::factor(string s){
  if(s[0] == '(' && s[s.length()-1] == ')') return expr(s.substr(1,s.length()-2));
  else return digit(s);
}
int parse_digits(string s){
  if(s.length()>1){
    int last_digit = parse_digits(s.substr(s.length()-1));
    if(last_digit != -1){
      int rest = parse_digits(s.substr(0,s.length()-1));
      if(rest != -1){
        return rest * 10 + last_digit;
      }else{
        return -1;
      }

    }else{
      return -1;
    }

  }else{
    if(s=="0") return 0;
    else if(s=="1") return 1;
    else if(s=="2") return 2;
    else if(s=="3") return 3;
    else if(s=="4") return 4;
    else if(s=="5") return 5;
    else if(s=="6") return 6;
    else if(s=="7") return 7;
    else if(s=="8") return 8;
    else if(s=="9") return 9;
    else return -1;
  }
}

Exp* Parser::digit(string s){
  if(s.length()>0){
    int str_to_int = parse_digits(s);
    if(str_to_int != -1){
      Exp* newVal = new Val(str_to_int);
      return newVal;
    }else return 0;
  }
  else return 0;
}

int Parser::eval(){
  return root->eval();
}
int Parser::nodeCount(){
  return root->nodeCount();
}
