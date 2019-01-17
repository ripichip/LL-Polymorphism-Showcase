#ifndef Family_H
#define Family_H
//This file creates Family class
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
//Import all the needed libraries
#include"Husband.h"
#include"Child.h"
#include"Wife.h"
//Include the needed files
using namespace std;

class Family
{//Create a class
 protected://Declare variables
  Husband* top;
 public://List functions avaiable in this class
  Family();
  bool AddHusband(long SSN, string Fname, string Lname);
  bool RemoveHusband(long SSN);
  bool AddWife(long SSN, string Fname, string Lname, long husbandSSN);
  bool RemoveWife(long husbandSSN);
  bool AddAChild(long SSN, string Fname, string Lname, long fatherSSN);
  bool RemoveAChild(long FatherSSN, long childSSN);
  bool SearchChild(long fatherSSN, long childSSN);
  HusbandPtr SearchHusband(long SSN);
  bool PrintAFamily(long fatherSSN);
  void PrintAllFamilies();
  void ReadTransactionFile();
};
#endif
