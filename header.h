
#pragma once
#ifndef __HEADER_H__
#define __HEADER_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef enum
{
  OVERCONDITION,
  UNDERCONDITION,
  EQUAL,
  NOTEQUAL
} mode;

typedef struct student
{
  int c_language:9;
  int computer_network:9;
  int cs_fundementals:9;
  float average;
  char *fname;
  char *lname;
  char *ID;
  char *course;
  char *error;
  struct student *next;
} student;

//----------------------------------------------------------------------------------------------------
// fileOps 
// input :file name from user ,and the head of valid list to read from file to linked list 
// second head (headB) for invalid lists 
// 
// this function handle with file and scan line by line and creates linked list from it
//----------------------------------------------------------------------------------------------------
void fileOps (char *fileName, struct student **head, struct student **headB);
//----------------------------------------------------------------------------------------------------
// createStruct 
// intput : string from function
//
// this function takes a string break it to struct fielde and return a new struct 
//----------------------------------------------------------------------------------------------------
struct student *createStruct (char *line);
//----------------------------------------------------------------------------------------------------
// validateNewStruct
// input : ptr to new struct , head of valid list , headB of invalid list from function
//
// this function sort structs into valid list or error list
//----------------------------------------------------------------------------------------------------
void validateNewStruct (struct student **newStudent, struct student **head,
			struct student **headB);
//----------------------------------------------------------------------------------------------------
// updateGrade
// input : new struct and phead of existing list from function
// 
// this function update existing student grade from new data
//----------------------------------------------------------------------------------------------------
void updateGrade (struct student *newStruct, struct student **phead);
//----------------------------------------------------------------------------------------------------
// insert
// input : head of list (valid or error) , and new struct from function
// 
// this function sort a new struct into a list in order 
//----------------------------------------------------------------------------------------------------
void insert (struct student **head, struct student *newStudent);
//----------------------------------------------------------------------------------------------------
// writeTofile
// input : struct from function
// 
// this function convert struct to line and write it to file
//----------------------------------------------------------------------------------------------------
void writeTofile (struct student *newStruct, char *fileName);
//----------------------------------------------------------------------------------------------------
void
displayMenu(char *fileName, struct student **head, struct student **headError);

#endif // !__HEADER_H__
