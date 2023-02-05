#include "header.h"


//----------------------------------------------------------------------------------------------------
// setNewData
// input : string of query from user , and head of list from function
// 
// this function takes a new struct format from user 
//----------------------------------------------------------------------------------------------------
void setNewData (char *inputLine, struct student **head,
		 struct student **headB, char *fileName);
//----------------------------------------------------------------------------------------------------
// checkValidSet
// input : string from function 
// 
// this function checks input struct format include all fields required
//----------------------------------------------------------------------------------------------------
struct student *checkValidSet (char *inputSet);
