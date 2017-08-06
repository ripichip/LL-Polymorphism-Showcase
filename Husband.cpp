#ifndef Husband_CPP
#define Husband_CPP
//This file implements Husband class
#include<iostream>
#include<vector>
#include<string>
//Import libraries
#include"Husband.h"
//Include the class file
using namespace std;

Husband::Husband()
{//Implement the default constructor
  SSN = 0;
  firstName = lastName = " ";
  nextFamily = NULL;
  myWife = NULL;
}
Husband::Husband(long ssn, string fname, string lname)
{//Initialize all variables
  SSN = ssn;
  firstName = fname;
  lastName = lname;
  nextFamily = NULL;
  myWife = NULL;
}
#endif
