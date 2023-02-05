#include "header.h"

// scanLineDinamically
// input : file buffer type
//
// this function scan unlimited line by chunks and allocate memory to it 
//----------------------------------------------------------------------------------------------------
char *scanLineDinamically (FILE * type);
//----------------------------------------------------------------------------------------------------
// toLowerStr
// input : string from function
//
// this function takes a string and return it in lower case
//----------------------------------------------------------------------------------------------------
void toLowerStr (char *str);
//----------------------------------------------------------------------------------------------------
// removeSpaces
// input : string from function
//
// this function takes a string and return it without double spaces
//----------------------------------------------------------------------------------------------------
void removeSpaces (char *str);
//----------------------------------------------------------------------------------------------------
// isalphaStr
// input : string from function 
//
// this function checks a string if only alphabet charachters shows inside it
//----------------------------------------------------------------------------------------------------
int isalphaStr (char *str);
//----------------------------------------------------------------------------------------------------
//isDigitStr
//input : string from function
//
// this function checks a string if only numeric charachters shows inside it
//----------------------------------------------------------------------------------------------------
int isDigitStr (char *str);
//----------------------------------------------------------------------------------------------------
// printList
// input : head of list from both function or user
// 
// this function loop over list and print it
//----------------------------------------------------------------------------------------------------
void printList (struct student *head);
//----------------------------------------------------------------------------------------------------
// printNode
// input : node of list from printList function 
// 
// this function loop over node fields and print it
//----------------------------------------------------------------------------------------------------
void printNode (struct student *head);
//----------------------------------------------------------------------------------------------------
// freeList
// input :  head of list from function
// 
// this function loop on list and send each data to free it
//----------------------------------------------------------------------------------------------------
void freeList (struct student **head);
//----------------------------------------------------------------------------------------------------
// freeNode
// input : struct from function
// 
// this function free each field of current student struct
//----------------------------------------------------------------------------------------------------
void freeNode (struct student *tmp);
