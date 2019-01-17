#ifndef Wife_CPP
#define Wife_CPP
//This file implements the Wife class
#include<iostream>
#include<vector>
#include<string>
//Import libraries
#include"Wife.h"
//Include the .h file
Wife::Wife()
{//Default constructor
  myChildren = NULL;
}
Wife::Wife(long ssn, string fname, string lname)
{//Initialize all variables needed
  SSN = ssn;
  firstName = fname;
  lastName = lname;
}
#endif
