#ifndef Person_H
#define Person_H
//This is a parent class for other classes in this program
#include<iostream>
#include<vector>
#include<string>
//Import libraries
using namespace std;

class Person
{
 protected://Declare variables
  long SSN;
  string firstName;
  string lastName;
 public:
  Person();//Constructor
};
#endif
