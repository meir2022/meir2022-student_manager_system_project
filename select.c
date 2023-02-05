#include "select.h"
#include "utils.h"

int
selectFName (struct student *head, char *value)
{
  return strcmp (head->fname, value);
}

int
selectLName (struct student *head, char *value)
{
  return strcmp (head->lname, value);
}

int
selectID (struct student *head, char *value)
{
  return strcmp (head->ID, value);
}

int
selectClanguage (struct student *head, char *value)
{
  return head->c_language - atoi (value);
}

int
selectCSfundemantal (struct student *head, char *value)
{
  return head->cs_fundementals - atoi (value);
}

int
selectComputerNet (struct student *head, char *value)
{
  return head->computer_network - atoi (value);
}

int
selectAvg (struct student *head, char *value)
{
  float ret = head->average - atof (value);
  if (ret == 0)
    return 0;
  if (ret > 0)
    return 1;
  else
    return -1;
}

void
selectGeneric (struct student *head, char *value, char *op,
	       int (*select) (struct student * head, char *value))
{

  int foundMatch = 0;

  if (!strcmp (op, ">"))
    while (head)
      {
	if (select (head, value) > 0)
	  {
	    if (!foundMatch)
	      printf ("\n  %10s\t%10s\t%8s\t%5s  %5s  %5s  %13s\n",
		      "first name", "last name", "ID", "c language",
		      "computer network", "cs fundemental", "average");

	    printNode (head);
	    foundMatch = 1;
	  }
	head = head->next;
      }
  if (!strcmp (op, "<"))
    while (head)
      {
	if (select (head, value) < 0)
	  {
	    if (!foundMatch)
	      printf ("\n  %10s\t%10s\t%8s\t%5s  %5s  %5s  %13s\n",
		      "first name", "last name", "ID", "c language",
		      "computer network", "cs fundemental", "average");
	    printNode (head);
	    foundMatch = 1;
	  }
	head = head->next;
      }
  if (!strcmp (op, "="))
    while (head)
      {
	if (!select (head, value))
	  {
	    if (!foundMatch)
	      printf ("\n  %10s\t%10s\t%8s\t%5s  %5s  %5s  %13s\n",
		      "first name", "last name", "ID", "c language",
		      "computer network", "cs fundemental", "average");
	    printNode (head);
	    foundMatch = 1;
	  }
	head = head->next;
      }
  if (!strcmp (op, "!="))
    while (head)
      {
	if (select (head, value))
	  {
	    if (!foundMatch)
	      printf ("\n  %10s\t%10s\t%8s\t%5s  %5s  %5s  %13s\n",
		      "first name", "last name", "ID", "c language",
		      "computer network", "cs fundemental", "average");
	    printNode (head);
	    foundMatch = 1;
	  }
	head = head->next;
      }
  if (!foundMatch)
    puts ("was not found !");
};


void
selectData (struct student *head, char *inputLine)
{
  toLowerStr (inputLine);
  char *op =
    strstr (inputLine, "!=") ? "!=" : strstr (inputLine,
					      "=") ? "=" : strstr (inputLine,
								   ">") ? ">"
    : strstr (inputLine, "<") ? "<" : " ";
  char *key = strtok (inputLine, " ");	// jump over the first word 'select' 
  removeSpaces (inputLine + strlen (key) + 1);

  key = strtok (NULL, "!=><");
  char *value = strtok (NULL, "\n");
  if (!strcmp (op, "!="))	// if the condition has 2 charachters jump over 2nd charachter
    value++;

  if (!strcmp (key, "firstname"))
    {
      selectGeneric (head, value, op, selectFName);
    }
  else if (!strcmp (key, "lastname"))
    {
      selectGeneric (head, value, op, selectLName);
    }
  else if (!strcmp (key, "id"))
    {
      selectGeneric (head, value, op, selectID);
    }
  else if (!strcmp (key, "averagegrade"))
    {
      selectGeneric (head, value, op, selectAvg);
    }
  else if (!strcmp (key, "clanguage"))
    {
      selectGeneric (head, value, op, selectClanguage);
    }
  else if (!strcmp (key, "csfundementals"))
    {
      selectGeneric (head, value, op, selectCSfundemantal);
    }
  else if (!strcmp (key, "computernetwork"))
    {
      selectGeneric (head, value, op, selectComputerNet);
    }
  else
    puts ("\nwrong details , try again");
}
