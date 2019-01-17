#ifndef Husband_H
#define Husbang_H
//This file creates a husband class
#include<iostream>
#include<vector>
#include<string>
//Import libraries
#include"Wife.h"
#include"Person.h"
//Import other files
using namespace std;
class Husband;//Class prototype
typedef Husband* HusbandPtr;//Create a pointer for this class

class Husband:public Person//Inherit from the Person class
{friend class Family;//Make a friend to Family class
 protected://Declare two pointers as the variables initialized within this class exclusively 
  HusbandPtr nextFamily;
  WifePtr myWife;
 public:
  Husband();//Default constructor
  Husband(long ssn, string fname, string lname);//Constructor
  //~Husband();
};
#endif
