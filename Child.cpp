#ifndef Child_CPP
#define Child_CPP
//This file implements the Child class
#include<iostream>
#include<vector>
#include<string>
//Include all libraries needed
#include"Child.h"
//Include the .h file of the class
using namespace std;

Child::Child()
{//Default constructor
  mySibling = NULL;
}
Child::Child(long ssn, string fname, string lname)
{//Implement the constructor that initializes all the variables needed
  SSN = ssn;
  firstName = fname;
  lastName = lname;
}
#endif
