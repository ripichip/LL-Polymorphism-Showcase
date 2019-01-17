/*
  Name: Oleksandr Shershnov
  Class: CS211
  Due Date: 11/05/2017
  Assignment #4
  Description: This program creates a linked list and performs various functions within it
*/
#ifndef main_CPP
#define main_H
//This is the file that contains the entry point of the program
#include<iostream>
#include<string>
#include<vector>
//Import needed libraries
#include"Family.h"
//Include the Family class
using namespace std;

int main()//Entry point of the program
{
  Family USAFamilies;//Create a new instance of the class Family
  USAFamilies.ReadTransactionFile();//Call the function within the class Family
  return 0;
}
#endif
