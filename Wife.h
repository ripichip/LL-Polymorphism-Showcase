#ifndef Wife_H
#define Wife_H
//This file creates a wife class
#include<iostream>
#include<string>
#include<vector>
//Import libraries
#include"Child.h"
#include"Person.h"
//Include other files needed for this program to work
using namespace std;

class Wife;//Class prototype

typedef Wife* WifePtr;//Create a pointer to Wife class

class Wife:public Person//Inherit from Person class
{friend class Family;//Make a friednd of Family class
 protected://Declare one pointer that's exclusive to this class
 ChildPtr myChildren;
 public:
 Wife();//Default constructor
 Wife(long ssn, string fname, string lname);//This constructor sets all the variables needed
};
#endif
