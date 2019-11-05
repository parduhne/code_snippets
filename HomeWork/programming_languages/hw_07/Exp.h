/*  Author: Evan Parduhn
    Class: CSCI_350
    HW: 07
    Date: 11/3
*/
#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <string>
#include <math.h>
#include "Parser.h"
using namespace std;

class Exp{
  friend class Parser;
public:
  virtual ~Exp(){};
  virtual int eval() = 0;
  virtual unsigned int nodeCount() = 0;
};

class Val: public Exp{
public:
  Val(int value){
    this->value = value;
  }
  int eval(){
    return value;
  }
  unsigned int nodeCount(){
    return 1;
  }
private:
  int value;
};

class Plus: public Exp{
public:
  Plus(Exp* a, Exp* b){
    left = a;
    right = b;
  }

  ~Plus(){
    cout << "plus destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() + right->eval();
  }
  unsigned int nodeCount(){
    // if(this == NULL) return 0;
    if(this->left == NULL && this->right == NULL) return 1;
    else return this->left->nodeCount() + this->right->nodeCount() + 1;
  }
private:
  Exp* left;
  Exp* right;
};

class Minus: public Exp{
public:
  Minus(Exp* a, Exp* b){
    left = a;
    right = b;
  }

  ~Minus(){
    cout << "plus destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() - right->eval();
  }
  unsigned int nodeCount(){
    // if(this == NULL) return 0;
    if(this->left == NULL && this->right == NULL) return 1;
    else return this->left->nodeCount() + this->right->nodeCount() + 1;
  }
private:
  Exp* left;
  Exp* right;
};


class Mult: public Exp{
public:
  Mult(Exp* a, Exp* b){
    left = a;
    right = b;
  }

  ~Mult(){
    cout << "plus destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() * right->eval();
  }
  unsigned int nodeCount(){
    // if(this == NULL) return 0;
    if(this->left == NULL && this->right == NULL) return 1;
    else return this->left->nodeCount() + this->right->nodeCount() + 1;
  }
private:
  Exp* left;
  Exp* right;
};

class Div: public Exp{
public:
  Div(Exp* a, Exp* b){
    left = a;
    right = b;
  }

  ~Div(){
    cout << "plus destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() / right->eval();
  }
  unsigned int nodeCount(){
    // if(this == NULL) return 0;
    if(this->left == NULL && this->right == NULL) return 1;
    else return this->left->nodeCount() + this->right->nodeCount() + 1;
  }
private:
  Exp* left;
  Exp* right;
};

class Mod: public Exp{
public:
  Mod(Exp* a, Exp* b){
    left = a;
    right = b;
  }

  ~Mod(){
    cout << "plus destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return left->eval() % right->eval();
  }
  unsigned int nodeCount(){
    // if(this == NULL) return 0;
    if(this->left == NULL && this->right == NULL) return 1;
    else return this->left->nodeCount() + this->right->nodeCount() + 1;
  }
private:
  Exp* left;
  Exp* right;
};

class Expo: public Exp{
public:
  Expo(Exp* a, Exp* b){
    left = a;
    right = b;
  }

  ~Expo(){
    cout << "plus destruct " << endl;
    delete left;
    delete right;
    left = NULL;
    right = NULL;
  }

  int eval(){
    return pow(left->eval(), right->eval());
  }
  unsigned int nodeCount(){
    // if(this == NULL) return 0;
    if(this->left == NULL && this->right == NULL) return 1;
    else return this->left->nodeCount() + this->right->nodeCount() + 1;
  }
private:
  Exp* left;
  Exp* right;
};
#endif
