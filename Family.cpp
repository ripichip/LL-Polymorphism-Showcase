#ifndef Family_CPP
#define Family_CPP
//This file implements the family class.
//This file also serves as the class in the program that contains
//all the logic
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
//Import the needed libraries
#include"Family.h"
//Include the .h file
using namespace std;

Family::Family()
{//Default constructor
  top = NULL;
}
bool Family::AddHusband(long SSN, string Fname, string Lname)
{//This function adds a husband and prints out an appropriate message
  HusbandPtr checkHusband = top;
  if(checkHusband != NULL)
    {
      while(checkHusband != NULL)//Run the while loop to get to the lasp point of the linked list
	{
	  if(checkHusband -> SSN == SSN)//Find if the previous instance of the provided SSN exists
	    {
      	      cout << "***ERROR*** CAN'T ADD HUSBAND. INVALID SSN" << endl;
	      return false;
	    }
	  checkHusband = checkHusband -> nextFamily;
	}
    }
  HusbandPtr husband = new Husband(SSN, Fname, Lname);//Create a new node
  husband -> nextFamily = top;
  top = husband;//Connect the node to the linked list
  cout << "Husband ID: " << SSN << " has been added" << endl;
  return true;
}
bool Family::RemoveHusband(long SSN)
{//This function removes a husband based on the provided SSN
  HusbandPtr husband = top;//Create two pointers 
  HusbandPtr prev;
  while(husband != NULL)
    {//Go through all the nodes looking for a match
      if(husband -> SSN == SSN)//If the match is found, proceed
	{
	  if(husband -> myWife != NULL)//Check to see if husband has a wife
	    {//If husband has a wife, remove her before removing husband
	      Family::RemoveWife(SSN);
	      if(husband -> nextFamily == NULL)//If the husband instance is the very last in the linked list...
		{//Delete and print out the appropriate message
		  cout << "\nHusband " << husband -> firstName << " " << husband -> lastName << " has been deleted " << endl;
		  delete husband;
		  prev -> nextFamily = NULL;
		  return true;
		}
	      else
		{//If the husband's instance is not the very last, delete and tie the previous and next nodes together
		  HusbandPtr next = husband -> nextFamily;
		  prev -> nextFamily = next;
		  cout << SSN << endl;
		  cout << "Husband " << husband -> firstName << " " << husband -> lastName << " has been deleted" <<  endl;
		  delete husband;
		  return true;
		}
	    }
	}
      prev = husband;
      husband = husband -> nextFamily;
    }
  cout << "***ERROR** Husband SSN provided is invalid" << endl;
  return false;
}
bool Family::AddWife(long SSN, string Fname, string Lname, long husbandSSN)
{//This function adds a wife to the linked list
  //HusbandPtr husband = SearchHusband(husbandSSN);
  HusbandPtr husband = top;
  WifePtr wife = new Wife(SSN, Fname, Lname);
  while(husband != NULL)
    {
      if(husbandSSN == husband -> SSN)
	{
	  if(husband -> myWife != NULL)
	    {
	      cout << "***ERROR*** Husband already has a wife. Can't add " << Fname << " " << Lname << endl;
	      return false;
	    }
	  else
	    {
	      cout << "Wife " << Fname << " " << Lname << " has been added" << endl;
	      husband -> myWife =  wife;
	      wife = husband -> myWife;
	      return true;
	    }
	}
      husband = husband -> nextFamily;
    }
  cout << "***ERROR*** HUSBAND SSN DOES NOT EXIST. CAN'T ADD A WIFE" << endl;
  return false;
}
bool Family::RemoveWife(long husbandSSN)
{//This function removes a wife from the linked list
  HusbandPtr husband = top;
  while(husband != NULL)
    {
      if(husband -> SSN == husbandSSN)
	{
	  if(husband -> myWife != NULL)
	    {
	      WifePtr wife = husband -> myWife;
	      if(wife -> myChildren != NULL)
		{//Remove all children before removing a wife
		  ChildPtr child = wife -> myChildren;
		  while(child != NULL)
		    {
		      int childSSN = child -> SSN;
		      Family::RemoveAChild(husbandSSN, childSSN);
		      child = child -> mySibling;
		    }
		  cout << "Wife " << wife -> firstName << " has been deleted" << endl;
		  delete wife;
		  husband -> myWife = NULL;
		  return true;
		}
	    }
	  else
	    {
	      cout << "***ERROR** HUSBAND DOES NOT HAVE A WIFE. CAN'T REMOVE A WIFE" << endl;
	    }
	}
      husband = husband -> nextFamily;
    }
  cout << "***ERROR*** HUSBAND ID DOES NOT EXIST. CAN'T REMOVE A WIFE" << endl;
}
bool Family::AddAChild(long SSN, string Fname, string Lname, long fatherSSN)
{//This function adds a child to the linked list
  HusbandPtr husband = top;
  if(Family::SearchChild(fatherSSN, SSN) == true)
    {//Check to see if child already exists
      cout << "***ERROR*** CHILD ALREADY EXISTS. CAN'T ADD AGAIN" << endl;
      return false;
    }
  while(husband != NULL)
    {//Find husband SSN
      if(husband -> SSN == fatherSSN)
	{//If there's a match for SSN - proceed 
	  if(husband -> myWife != NULL)
	    {//Check if husband has a wife
	      WifePtr wife = husband -> myWife;
	      if(wife -> myChildren == NULL)
		{//Add first child
		  ChildPtr child = new Child(SSN, Fname, Lname);
		  wife -> myChildren = child;
		  child = wife -> myChildren;
		  cout << "Child has been added to the family " << child -> firstName << endl;
		  return true;
		}
	      else
		{//Add a sibling
		  ChildPtr childCheck = wife -> myChildren;
		  if(childCheck -> SSN != SSN)
		    {
		      ChildPtr sibling = wife -> myChildren;
		      while(sibling -> mySibling != NULL)
			{
			  sibling = sibling -> mySibling;
			}
		      if(sibling -> SSN != SSN)
			{
			  ChildPtr child = new Child(SSN, Fname, Lname);
			  sibling -> mySibling = child;
			  cout << "Sibling has been added " << child -> firstName << endl;
			  return true;
			}
		    }
		  else
		    {
		      cout << "***ERROR*** CHILD CAN'T BE ADDED. SSN ALREADY EXISTS" << endl;
		      return false;
		    }
		}
	    }
	  else
	    {
	      cout << "\nThis husband doesn't have a wife, can't add a child " << endl;
	    }
	}
      husband = husband -> nextFamily;
    }
  cout << "Father id doesnt exist, can't add child " << endl;
  return false;
}
bool Family::RemoveAChild(long fatherSSN, long childSSN)
{//This function removes a child from the linked list
  if(Family::SearchChild(fatherSSN, childSSN) == false)
    {//Check if child ID passed in is valid
      cout << "***ERROR***Invalid child ID. Can't remove child" << endl;
      return false;
    }
  HusbandPtr husband = top;
  while(husband != NULL)
    {//Find husband in the linked list
      if(husband -> SSN == fatherSSN)
	{//If there's a match for SSN - proceed
	  WifePtr wife = husband -> myWife;
	  if(wife -> myChildren != NULL)
	    {//Find out if wife has children
	      ChildPtr child = wife -> myChildren;
	      if(child -> SSN == childSSN)
		{
		  if(child -> mySibling != NULL)
		    {//This portion will remove a child that wife directly points to
		      ChildPtr sibling = child -> mySibling;
		      wife -> myChildren = sibling;
		      cout << "Child has been deleted " << child -> firstName << " " << child -> lastName<< endl;
		      delete child;
		      return true;
		    }
		  else
		    {
		      cout << "Child " << child -> firstName << " " << child -> lastName << " has been deleted" << endl;
		      delete child;
		      wife -> myChildren = NULL;
		      return true;
		    }
		}
	      else if(child -> mySibling != NULL)
		{//This portion will remove a child linked as a sibling
		  ChildPtr ch = wife -> myChildren;
		  ChildPtr sibling = child -> mySibling;
		  ChildPtr nextSib = sibling -> mySibling;
		  while(sibling -> mySibling != NULL)
		    {
		      if(sibling -> SSN == childSSN)
			{
			  nextSib = sibling -> mySibling;
			  ch -> mySibling = nextSib;
			  cout << "Sibling has been deleted " << sibling -> firstName << " " << sibling -> lastName << endl;
			  delete sibling;
			  return true;
			}
		      ch = ch -> mySibling;
		      sibling = sibling -> mySibling;
		      nextSib = nextSib -> mySibling;
		    }
		}
	    }
	  else
	    {
	      return false;
	      cout << "***ERROR*** THIS FAMILY DOES NOT HAVE CHILDREN. CAN'T REMOVE A CHILD" << endl;
	    }
	}
      husband = husband -> nextFamily;
    }  
  cout << "***ERROR*** FATHER ID CAN'T BE FOUND. COULD NOT REMOVE A CHILD. " << endl;
  return false;
}
/*HusbandPtr Family::SearchHusband(long SSN)
{//This functions searches through the linked list to find if husband exists
  HusbandPtr husband = top;
  if(husband == NULL)
    {
      return NULL;
    }
  else
    {
      while(husband != NULL)
	{
	  if(husband -> SSN == SSN)
	    {
	      return husband;
	    }
	  husband = husband -> nextFamily;
	}
      return NULL;
    }
    }*/
bool Family::SearchChild(long fatherSSN, long childSSN)
{//This function searches for a child within the linked list
 //Creating this function was not required, however, it simplifies other functions
 //Entry point of the linked list
  HusbandPtr father = top;
  while(father != NULL)
    {
      if(father -> SSN == fatherSSN)
	{
	  if(father -> myWife != NULL)
	    {
	      WifePtr wife = father -> myWife;
	      if(wife -> myChildren != NULL)
		{
		  ChildPtr child = wife -> myChildren;
		  if(child -> SSN == childSSN)
		    {
		      return true;
		    }
		  else if(child -> mySibling != NULL)
		    {
		      ChildPtr sibling = child -> mySibling;
		      if(sibling -> SSN != childSSN)
			{
			  while(sibling -> mySibling != NULL)
			    {
			      if(sibling -> SSN == childSSN)
				{
				  return true;
				}
			      sibling = sibling -> mySibling;
			    }
			  return false;
			}
		      else
			{
			  return true;
			}
		    }
		}
	      else
		{
		  return false;
		}
	    }
	  else
	    {
	      return false;
	    }
	}
      father = father -> nextFamily;
    }
  return false;
}
bool Family::PrintAFamily(long fatherSSN)
{//This function prints out a family based on the provided SSN of father/husband
  cout << "\n";
  HusbandPtr husband = top;
  while(husband != NULL)
    {
      if(husband -> SSN == fatherSSN)
	{
	  cout << "Husband: " << husband -> firstName << " " << husband -> lastName << endl;
	  if(husband -> myWife != NULL)
	    {
	      WifePtr wife = husband -> myWife;
	      cout << "Wife: " << wife -> firstName << " " << wife -> lastName << endl;
	      if(wife -> myChildren != NULL)
		{
		  ChildPtr child = wife -> myChildren;
		  cout << "Child: " << child -> firstName << " " << child -> lastName << endl;
		  if(child -> mySibling != NULL)
		    {
		      ChildPtr sibling = child -> mySibling;
		      while(sibling != NULL)
			{
			  cout << "Sibling " << sibling -> firstName << " " << sibling -> lastName << endl;
			  sibling = sibling -> mySibling;
			}
		    }
		}
	    }
	  return true;
	}
      husband = husband -> nextFamily;
    }
  cout << "***ERROR*** CAN'T PRINT A FAMILY. FAMILY DOES NOT EXIST" << endl;
  return false;
}
void Family::PrintAllFamilies()
{//This function prints out all attributes of the linked list
  cout << "\n";//Create an empty line for better readability
  int counter = 1;
  HusbandPtr husband = top;
  if(husband != NULL)
    {
      while(husband != NULL)
	{//Use while loop to cover every iteration of the linked list
	  cout << "Family: " << counter << endl;
	  cout << "Husband: " <<  husband -> SSN << " " << husband -> firstName << " " << husband -> lastName << endl;
	  if(husband -> myWife != NULL)
	    {
	      WifePtr wife = husband -> myWife;
	      cout << "Wife: " << wife -> SSN << " " << wife -> firstName << " " << wife -> lastName << endl;
	      if(wife -> myChildren != NULL)
		{
		  ChildPtr child = wife -> myChildren;
		  cout << "Child: " << child -> firstName << endl;
		  if(child -> mySibling != NULL)
		    {
		      ChildPtr sibling = child -> mySibling;
		      while(sibling != NULL)
			{
			  cout << "Sibling " << sibling -> firstName << endl;
			  sibling = sibling -> mySibling;
			}
		    }
		}
	    }
	  cout << "\n";
	  husband = husband -> nextFamily;//Check next iteration of the linked list
	  counter++;
	}
    }
  else
    {
      cout << "\nLinked list is empty..." << endl;
    }
}
void Family::ReadTransactionFile()
{//This function reads the transaction file and calls appropriate functions
  // based on the information from the transaction file
  ifstream in;
  in.open("Transaction.txt");//Open the transaction file
  long id, fid;
  string fn, ln;
  string command;
  while(!in.eof())//Keep reading in the file until it ends
    {
      in >> command;//Read in the command...
      //Next, follows a series of if/else if statements that calls the appropriate function
      if(command == "AddHusband")
	{
	  in >> id >> fn >> ln;
	  cout << "Adding a husband... " << endl;
	  AddHusband(id, fn, ln);
	}
      else if(command == "AddWife")
	{
	  cout << "Adding a wife... " << endl;
	  in >> id >> fn >> ln >> fid;
	  AddWife(id, fn, ln, fid);
	}
      else if(command == "AddAChild")
	{
	  cout << "Adding a child... " << endl;
	  in >> id >> fn >> ln >> fid;
	  AddAChild(id, fn, ln, fid);
	}
      else if(command == "RemoveAchild")
	{
	  cout << "Removing a child...." << endl;
	  in >> fid >> id;
	  RemoveAChild(fid, id);
	}
      else if(command == "RemoveAWife")
	{
	  cout << "Removing a wife..." << endl;
	  in >> fid;
	  RemoveWife(fid);
	}
      else if(command == "RemoveAHusband")
	{
	  cout << "Removing a husband..." << endl;
	  in >> id;
	  RemoveHusband(id);
	}
      else if(command == "PrintAllFamilies")
	{
	  cout << "\nPrinting all families: " << endl;
	  PrintAllFamilies();
	}
      else if(command == "PrintAFamily")
	{
	  in >> fid;
	  cout << "\nPrinting a family... ID: " << fid << endl;
	  PrintAFamily(fid);
	}
      else
	{
	  cout << "Error. Command was not found." << endl;
	}
    }
}
#endif
