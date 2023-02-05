#include "header.h"

//----------------------------------------------------------------------------------------------------
// selectFName
// input : head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
int selectFName (struct student *head, char *value);
//----------------------------------------------------------------------------------------------------
// selectLName
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
int selectLName (struct student *head, char *value);
//----------------------------------------------------------------------------------------------------
// selectID
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
int selectID (struct student *head, char *value);
//----------------------------------------------------------------------------------------------------
// selectCLanguage
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
int selectCLanguage (struct student *head, char *value);
//----------------------------------------------------------------------------------------------------
// selectCsFundementals
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
int selectCsFundementals (struct student *head, char *value);
//----------------------------------------------------------------------------------------------------
// selectComputerNet
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
int selectComputerNet (struct student *head, char *value);
//----------------------------------------------------------------------------------------------------
// selectAvg
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
int selectAvg (struct student *head, char *value);
//----------------------------------------------------------------------------------------------------
// selectData
// input : head of list and input from user
// 
// this function gets a query from user and search for it in list and return found data
//----------------------------------------------------------------------------------------------------
void selectData (struct student *head, char *inputLine);
//----------------------------------------------------------------------------------------------------
// selectGeneric
// input : head of list and condition and value generic function from one of the fields corresponding 
// the current search
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void selectGeneric (struct student *head, char *value, char *op,
		    int (*test) (struct student * head, char *value));
