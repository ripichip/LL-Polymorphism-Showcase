#ifndef Person_CPP
#define Person_CPP
//This is file that implements person class
#include<iostream>
#include<string>
#include<vector>
//Import libraries
#include"Person.h"
//Include the person file
using namespace std;

Person::Person()//Impliment default constructor
{//Initialize variables
  SSN = 0;
  firstName = lastName = " ";
};
#endif
