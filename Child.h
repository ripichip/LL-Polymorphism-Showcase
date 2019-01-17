#ifndef Child_H
#define Child_H
//This file creates Child class
#include<iostream>
#include<string>
#include<vector>
//Import libraries
#include"Person.h"
//Include where the variables are importe from
class Child;//Class prototype

using namespace std;

typedef Child* ChildPtr;//Create a pointer to Child class

class Child:public Person//Inherit from Person class
{friend class Family;//Make friend to Family class
 protected://Declare a variable
  ChildPtr mySibling;
 public:
  Child();//Default constructor
  Child(long ssn, string fname, string lname);//Constructor that initializes all variables  
};

#endif
