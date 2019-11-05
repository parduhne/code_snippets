/******************************************************************************
Author:  Evan Parduhn
 Class:  CSCI350 - HW 05
  Date:  10/20/19
Languange: L1 = (101)+0(101)+
Grammar:
        A-> 101B
        B-> 101B | 0C
        C-> 101D
        D-> 101D | END
*******************************************************************************/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define BELONGS cout<<"Accepted"<<endl;
#define DNBELONG cout<<"Not Accepted"<<endl;

void A(char *exp,char *p);
void B(char *exp,char *p);
void C(char *exp,char *p);
void D(char *exp,char *p);

int main(){
  char binaryNr[100];
  char *p;
  char *end;
  bool exit = true;
  while(exit){
    cout<<"\nEnter a binary number to see if it is in the language: ";
    cin.getline(binaryNr,100);
    string thing = binaryNr;
    if(thing == "exit"){
      exit = false;
    }
    else{
      p = binaryNr;
      end = binaryNr + strlen(binaryNr)-1;
      A(end,p);
    }
  }
}

void A(char *exp,char *p){
  if(p != exp && *p == '1'){
    if(++p != exp && *p == '0'){
      if(++p != exp && *p == '1'){
        B(exp,++p);
        return;
      }
    }
  }
  DNBELONG;
  return;
}

void B(char *exp,char *p){
  if(p != exp && *p == '1'){
    if(++p != exp && *p == '0'){
      if(++p != exp && *p == '1'){
        B(exp,++p);
        return;
      }
    }
  }
  else if(p != exp && *p == '0'){
    C(exp,++p);
    return;
  }
  DNBELONG;
  return;
}

void C(char *exp,char *p){
  if(p != exp && *p == '1'){
    if(++p != exp && *p == '0'){
      if(*(++p) == '1'){
        D(exp,p);
        return;
      }
    }
  }
  DNBELONG;
  return;

}

void D(char *exp,char *p){
  if(p == exp){
   BELONGS;
   return;
  }
  else{
    if(++p != exp && *p == '1'){
      if(++p != exp && *p == '0'){
        if(*(++p) == '1'){
          D(exp,p);
          return;
        }
      }
    }
    DNBELONG;
    return;
  }
}
